#include<cstdio>
#include<algorithm>
#include<vector>

using namespace std;

const int MAXN = 3e5 + 10;

int n, l[MAXN], r[MAXN], sec[MAXN], sz;
int ptr[MAXN];
vector<int>	adj[MAXN];
short used[MAXN], cur = 1;

void dfs(int v, int p = -1){
	for (; ptr[v] < adj[v].size();){
		int e = adj[v][ptr[v]++];
		if (!used[e]){
			used[e] = 1;
			dfs(l[e]^r[e]^v, e);
		}
	}
	if (~p){
		if (v == l[p])
			used[p] = 2;
		else
			used[p] = 1;
	}
}

int main(){
	scanf("%d", &n);	int m = n;
	for (int i = 0; i < n; i++){
		scanf("%d %d", &l[i], &r[i]), l[i] <<= 1, r[i] <<= 1, r[i] |= 1;
		sec[sz++] = l[i], sec[sz++] = r[i];
	}
	sort(sec, sec + sz);
	sz = unique(sec, sec + sz) - sec;
	for (int i = 0; i < n; i++){
		l[i] = lower_bound(sec, sec + sz, l[i]) - sec, r[i] = lower_bound(sec, sec + sz, r[i]) - sec;
		adj[l[i]].push_back(i);
		adj[r[i]].push_back(i);
	}
	int lst = -1;
	for (int i = 0; i < sz; i++)
		if (adj[i].size() & 1){
			if (~lst){
				l[m] = lst, r[m] = i;
				adj[lst].push_back(m);
				adj[i].push_back(m);
				m++;
				lst = -1;
			}
			else
				lst = i;
		}
	
	for (int i = 0; i < sz; i++)
		if (ptr[i] < adj[i].size())
			dfs(i);
	for (int e = 0; e < n; e++)
		printf("%d ", used[e] - 1);
	printf("\n");
	return 0;
}