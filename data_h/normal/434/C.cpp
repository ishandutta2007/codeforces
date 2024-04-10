#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

const int TYPE = 22;
const int MOD = 1000000007;

int use, n, m, upper;
vector<int> lvec, rvec;
int length, tot;

struct node
{
	node *child[TYPE], *fail;
	int score, id;
	void clear()
	{
		for(int i = 0; i < m; i++)
			child[i] = NULL;
		fail = NULL;
		score = 0;
	}
}buc[444 + 10], *root, *q[444 + 10];

node *newnode()
{
	buc[++use].clear();
	buc[use].id = use;
	return &buc[use];
}

void insert(const vector<int> &buf, int c)
{
	node *tmp = root;
	for(int i = 0; i < (int)buf.size(); i++) {
		int ind = buf[i];
		if (tmp->child[ind] == NULL) {
			tmp->child[ind] = newnode();
		}
		tmp = tmp->child[ind];
	}
	tmp->score += c;
}

void build()
{
	int qhead = 0, qtail = 1;
	q[qtail] = root; root->fail = NULL;
	while(qhead < qtail)
	{
		node* tmp = q[++qhead];
		for(int i = 0; i < m; i++)
			if (tmp->child[i] != NULL) {
				q[++qtail] = tmp->child[i];
				if (tmp == root) {
					tmp->child[i]->fail = root;
					continue;
				} else {
					node* p = tmp->fail;
					while(p != NULL && p->child[i] == NULL)
						p = p->fail;
					if (p != NULL)
						tmp->child[i]->fail = p->child[i];
					else
						tmp->child[i]->fail = root;
				}
			}
	}
	for(int i = 1; i <= qtail; i++) {
		if (q[i]->fail != NULL)
			q[i]->score += q[i]->fail->score;
	}
	tot = qtail;
}

void getVec(vector<int> &vec) {
	int len;
	scanf("%d", &len);
	for(int i = 0; i < len; i++) {
		int x;
		scanf("%d", &x);
		vec.push_back(x);
	}
}

void addLeadZero(vector<int> &vec, int d) {
	vector<int> tmp;
	for(int i = 0; i < d; i++) {
		tmp.push_back(0);
	}
	for(int i = 0; i < (int)vec.size(); i++) {
		tmp.push_back(vec[i]);
	}
	vec = tmp;
}

int f[2][202][502][2][2];

int solve(const vector<int> &bound, int special = 0) {
	int cur = 0;
	for(int i = 1; i <= tot; i++)
		for(int j = 0; j <= upper; j++)
			for(int k = 0; k < 2; k++)
				for(int l = 0; l < 2; l++)
					f[0][i][j][k][l] = 0;
	f[0][root->id][0][0][0] = 1;
	for(int i = 0; i < length; i++) {
		memset(f[cur ^ 1], 0, sizeof(f[cur ^ 1]));
		for(int j = 1; j <= tot; j++)
			for(int k = 0; k <= upper; k++)
				for(int l = 0; l < 2; l++) 
					for(int p = 0; p < 2; p++) {
					if (f[cur][j][k][l][p] == 0)
						continue;
					if (cur == 1 && j == 1 && k == 0 && l == 1 && p == 0)
						cur = 1;
					for(int nxt = 0; nxt < m; nxt++) {
						if (l == 0 && nxt > bound[i])
							continue;
						node *tmp = &buc[j];
						if (nxt || p) {
							while(tmp != NULL && tmp->child[nxt] == NULL)
								tmp = tmp->fail;
							if (tmp == NULL)
								tmp = root;
							else
								tmp = tmp->child[nxt];
						}
						if (k + tmp->score <= upper)
							(f[cur ^ 1][tmp->id][k + tmp->score][l | (nxt < bound[i])][p | (nxt > 0)] 
								+= f[cur][j][k][l][p]) %= MOD;
					}
					
				}
		cur ^= 1;
	}
	int res = 0;
	for(int i = 1; i <= tot; i++)
		for(int j = 0; j <= upper; j++)
			for(int k = 0; k < 2; k++) 
				for(int l = 0; l < 2; l++) {
					if (special && k == 0)
						continue;
					(res += f[cur][i][j][k][l]) %= MOD;
				}
	return res;
}

int main() {
	root = newnode();
	scanf("%d %d %d", &n, &m, &upper);
	getVec(lvec);
	getVec(rvec);
	length = max((int)lvec.size(), (int)rvec.size());
	if ((int)lvec.size() < length) {
		addLeadZero(lvec, length - (int)lvec.size());
	}
	for(int i = 1; i <= n; i++) {
		int v, l;
		scanf("%d", &l);
		vector<int> str;
		for(int j = 0; j < l; j++) {
			int x;
			scanf("%d", &x);
			str.push_back(x);
		}
		scanf("%d", &v);
		if (l > length) {
			continue;
		}
		insert(str, v);
	} 
	build();
	printf("%d\n", (solve(rvec) - solve(lvec, 1) + MOD) % MOD);
}