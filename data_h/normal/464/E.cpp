#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

const int N = 1e5 + 30;
const int LOG = 20;
const int MAGIC = 3;
const int MOD = 1000000007;

long long power[N], allOne[N];

struct Tree {
	Tree *child[2];
	long long hash;
	int l, r;
	Tree() {
		child[0] = child[1] = NULL;
	}
	Tree* update() {
		hash = child[1]->hash * power[child[0]->r - child[0]->l + 1] + child[0]->hash;
		return this;
	}
};

bool cmp(Tree *a, Tree *b) {
	if (a->hash == b->hash) {
		return 0;
	}
	if (a->l == a->r) {
		return a->hash < b->hash;
	}
	if (a->child[1]->hash == b->child[1]->hash) {
		return cmp(a->child[0], b->child[0]);
	} else {
		return cmp(a->child[1], b->child[1]);
	}
}

struct Value {
	Tree *value;
	int x;
	Value(Tree *value, int x) : value(value), x(x) {}
	inline friend bool operator <(const Value &a, const Value &b) {
		return cmp(a.value, b.value);
	}
	inline friend bool operator >(const Value &a, const Value &b) {
		return cmp(b.value, a.value);
	}
};

Tree *dist[N];
Tree pool[N * LOG * 2];
int used = 0, source, target, n, m, maxPower, from[N], visit[N];
vector<pair<int, int> > e[N];
priority_queue<Value, vector<Value>, greater<Value> > q;

int getID(int l, int r) {
	return (l + r) | (l != r);
}


Tree* build(int l, int r) {
	Tree *temp = &pool[getID(l, r)];
	temp->hash = 0;
	temp->l = l;
	temp->r = r;
	if (l != r) {
		int mid = (l + r) >> 1;
		temp->child[0] = build(l, mid);
		temp->child[1] = build(mid + 1, r);
	}
	return temp;
}

int detect(Tree *root, int pos) {
	int l = root->l, r = root->r, mid = (l + r) / 2;
	if (allOne[r - l + 1] == root->hash || pos > r) {
		return r + 1;
	}
	
	if (root->l == root->r) {
		return root->l;
	} else {
		int temp = detect(root->child[0], pos);
		if (temp <= mid) {
			return temp;
		} else {
			return detect(root->child[1], pos);
		}
	}
}

Tree* cover(Tree *root, int ql, int qr){
	if (qr < root->l || root->r < ql) {
		return root;
	}
	if (ql <= root->l && root->r <= qr) {
		return &pool[getID(root->l, root->r)];
	}
	Tree *temp = &pool[used++];
	*temp = *root;
	temp->child[0] = cover(temp->child[0], ql, qr);
	temp->child[1] = cover(temp->child[1], ql, qr);
	return temp->update();
}

Tree *flip(Tree *root, int pos) {
	Tree *temp = &pool[used++];
	*temp = *root;
	if (root->l == root->r) {
		temp->hash = 1;
		return temp;
	}
	
	int mid = (root->l + root->r) / 2;
	if (pos <= mid) {
		temp->child[0] = flip(temp->child[0], pos);
	} else {
		temp->child[1] = flip(temp->child[1], pos);
	}
	return temp->update();
}

Tree* add(Tree *root, int pos) {
	int newPos = detect(root, pos);
	root = cover(root, pos, newPos - 1);
	root = flip(root, newPos);
	return root;
}

void dfs(Tree *x, int &res) {
	if (x == NULL) {
		return;
	}
	if (x->child[0] == NULL) {
		res = (res * 2 % MOD + x->hash) % MOD;
	} else {
		dfs(x->child[1], res);
		dfs(x->child[0], res);
	}
}

int main() {
	maxPower = 0;
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= m; i++) {
		int u, v, x;
		scanf("%d %d %d", &u, &v, &x);
		e[u].push_back(make_pair(v, x));
		e[v].push_back(make_pair(u, x));
		maxPower = max(maxPower, x);
	}
	maxPower += 20;
	power[0] = 1;
	allOne[0] = 0;
	for(int i = 1; i <= maxPower + 5; i++) {
		power[i] = power[i - 1] * MAGIC;
		allOne[i] = allOne[i - 1] * MAGIC + 1;
	}
	
	scanf("%d %d", &source, &target);
	dist[source] = build(0, maxPower);
	used = 2 * maxPower + 20;
	q.push(Value(dist[source], source));
	from[source] = 0;
	while(!q.empty()) {
		Value temp = q.top();
		q.pop();
		int x = temp.x;
		if (visit[x]) {
			continue;
		}
		visit[x] = 1;
		if (x == target) {
			break;
		}
		for(int i = 0; i < (int)e[x].size(); i++) {
			int y = e[x][i].first;
			if (visit[y]) {
				continue;
			}
			Tree* newValue = add(temp.value, e[x][i].second);
			if (dist[y] == NULL || cmp(newValue, dist[y])) {
				dist[y] = newValue;
				from[y] = x;
				q.push(Value(newValue, y));
			}
		}
	}
	if (!visit[target]) {
		puts("-1");
	} else {
		int result = 0;
		dfs(dist[target], result);
		printf("%d\n", result);
		vector<int> path;
		int x = target;
		while(x) {
			path.push_back(x);
			x = from[x];
		}
		reverse(path.begin(), path.end());
		printf("%d\n", (int)path.size());
		for(int i = 0; i < (int)path.size(); i++) {
			printf("%d%c", path[i], i == (int)path.size() - 1 ? '\n' : ' ');
		}
	}
	
	return 0;
}