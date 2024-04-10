#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
#define ll long long
#define M 1000000007
#define all(a) a.begin(), a.end()

const int maxn = 1000010;
int go[maxn][26], fail[maxn], cnt[maxn], root = 1, tot = 1;
vector<int> g[maxn];
int dp[maxn][2], dep[maxn];
bool vis[maxn];
int T, n;
char s[maxn];

void insert(char *str){
	int cur = root, i = 0;
	while(str[i]){
		int idx = str[i] - 'a';
		if(!go[cur][idx]){
			go[cur][idx] = ++tot; 
			memset(go[tot], 0, sizeof(go[tot])); fail[tot] = 0;
			dep[tot] = dep[cur] + 1;
			g[tot].clear();
			vis[tot] = 0;
		}
		cur = go[cur][idx];
		i++;
	}
}

void build(){
	queue<int> q;
	q.push(root);
	while(!q.empty()){
		int t = q.front(); q.pop();
		for(int i = 0; i < 26; ++i)
			if(!go[t][i]){
				go[t][i] = t == root ? 1 : go[fail[t]][i];
			}else{
				fail[go[t][i]] = t == root ? 1 : go[fail[t]][i];
				if(fail[go[t][i]] != 1 && dep[go[t][i]] == dep[fail[go[t][i]]] + 1)
					g[fail[go[t][i]]].pb(go[t][i]), vis[go[t][i]] = 1;
				q.push(go[t][i]);
			}
	}
}

void dfs(int t){
	dp[t][0] = 0;
	dp[t][1] = 1;
	for(int v : g[t]){
		dfs(v);
		dp[t][1] += dp[v][0];
		dp[t][0] += max(dp[v][1], dp[v][0]);
	}
}

int main(){
	scanf("%d", &T);
	while(T--){
		scanf("%d", &n);
		root = tot = 1; memset(go[1], 0, sizeof(go[1])); cnt[1] = fail[1] = 0; g[1].clear();
		for(int i = 0; i < n; ++i){
			scanf("%s", s);
			insert(s);
		}
		build();
		int ans = 0;
		for(int i = 2; i <= tot; ++i)
			if(!vis[i]){
				dfs(i);
				ans += max(dp[i][0], dp[i][1]);
			}
		printf("%d\n", ans);
	}
	
#ifndef ONLINE_JUDGE
	system("pause");
#endif
	return 0;
}