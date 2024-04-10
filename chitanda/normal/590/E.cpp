#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
#define ll long long
#define M 1000000007
#define all(a) a.begin(), a.end()

const int maxn = 760, maxm = 10001000;
int n;
char s[maxm];
int go[maxm][2], fail[maxm], root = 1, tot = 1;
int last[maxm], cnt[maxm];
int b[maxn][maxn];
bool vis[maxn];
int p[maxn], bg[maxn], q[maxn];
bool mark[maxn][2];

void insert(char *str, int id){
	int cur = root, i = 0;
	while(str[i]){
		int idx = str[i] - 'a';
		if(!go[cur][idx]) go[cur][idx] = ++tot;
		cur = go[cur][idx];
		i++;
	}
	cnt[cur] = id;
}

void build(){
	queue<int> q;
	q.push(root);
	while(!q.empty()){
		int t = q.front(); q.pop();
		for(int i = 0; i < 2; ++i)
			if(!go[t][i]){
				go[t][i] = t == root ? 1 : go[fail[t]][i];
			}else{
				fail[go[t][i]] = t == root ? 1 : go[fail[t]][i];
				last[go[t][i]] = cnt[fail[go[t][i]]] ? fail[go[t][i]] : 
					last[fail[go[t][i]]];
				q.push(go[t][i]);
			}
	}
}

bool dfs(int t){
	for(int i = 1; i <= n; ++i)
		if(b[t][i] && !vis[i]){
			vis[i] = 1;
			if(!p[i] || dfs(p[i])){
				p[i] = t;
				q[t] = i;
				return 1;
			}
		}
	return 0;
}

void dfs(int x, int side){
	if(mark[x][side]) return;
	mark[x][side] = 1;
	if(!side){
		for(int i = 1; i <= n; ++i)
			if(b[x][i]) dfs(i, 1);
	}else{
		if(p[x]) dfs(p[x], 0);
	}
}

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i){
		scanf("%s", s + bg[i]);
		bg[i + 1] = bg[i] + strlen(s + bg[i]);
		insert(s + bg[i], i);
	}
	build();
	for(int i = 1; i <= n; ++i){
		int cur = root;
		for(int j = bg[i]; j < bg[i + 1]; ++j){
			cur = go[cur][s[j] - 'a'];
			b[i][cnt[last[cur]]] = 1;
			b[i][cnt[cur]] = 1;
		}
	}
	for(int k = 1; k <= n; ++k)
		for(int i = 1; i <= n; ++i)
			for(int j = 1; j <= n; ++j)
				b[i][j] |= b[i][k] && b[k][j];
	for(int i = 1; i <= n; ++i) b[i][i] = 0;

	int res = n;
	for(int i = 1; i <= n; ++i){
		memset(vis, 0, sizeof(vis));
		res -= dfs(i);
	}
	printf("%d\n", res);
	for(int i = 1; i <= n; ++i)
		if(!q[i]) dfs(i, 0);
	for(int i = 1; i <= n; ++i)
		if(!(mark[i][1] || !mark[i][0]))
			printf("%d ", i);
	
#ifndef ONLINE_JUDGE
	system("pause");
#endif
	return 0;
}