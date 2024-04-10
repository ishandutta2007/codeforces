#include<cstdio>
#include<cmath>
#include<algorithm>
#include<vector>
#include<utility>

using namespace std;

const int MAXN = 1e6 + 100;

int n;
int p[MAXN];
int mark[MAXN];
int nxt[MAXN];
int cnt[MAXN];
vector<int>	vec;

int gs(int v, int par, int d = 0){
	mark[v] = 1;
	if (v == par && d)	return	d;
	vec.push_back(v);
	return	gs(p[v], par, d + 1);
}

void fill(int v){
	if (vec.size() == 1){
		nxt[vec[0]] = vec[0];
		mark[vec[0]] = 2;
		return;
	}

	int sz = (int)vec.size() / 2;
	for (int i = 0; i < sz; i++)
		nxt[vec[i]] = vec[sz + i + 1];
	for (int i = sz; i < vec.size(); i++)
		nxt[vec[i]] = vec[i - sz];
	for (int u:vec)
		mark[u] = 2;
}

void merge(int u, int v){
	int sz = vec.size();
	for (int i = 0; i < sz; i++){
		mark[u] = mark[v] = 2;
		nxt[u] = v;
		u = p[u];
		nxt[v] = u;
		v = p[v];
	}
}

int main(){
	scanf("%d", &n);
	for (int i = 0; i < n; i++){
		scanf("%d", &p[i]);
		p[i]--;
	}

	for (int i = 0; i < n; i++){
		if (mark[i])	continue;
		vec.clear();
		int sz = gs(i, i);
		if (sz % 2 == 1)
			fill(i);
		else{
			if (cnt[sz]){
				int t = cnt[sz] - 1;
				cnt[sz] = 0;
				merge(t, i);
			}
			else	cnt[sz] = i + 1;
		}
	}

	for (int i = 0; i < n; i++)
		if (mark[i] == 1){
			printf("-1\n");
			return 0;
		}
	for (int i = 0; i < n; i++)
		printf("%d ", nxt[i] + 1);
	printf("\n");
	return 0;
}