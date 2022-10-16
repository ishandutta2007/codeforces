#include<bits/stdc++.h>
#define rep(i,a,b) for(ll i=(a);i<=(b);i++)
#define per(i,a,b) for(ll i=(a);i>=(b);i--)
#define op(x) ((x&1)?x+1:x-1)
#define odd(x) (x&1)
#define even(x) (!odd(x))
#define lc(x) (x<<1)
#define rc(x) (lc(x)|1)
#define lowbit(x) (x&-x)
#define Max(a,b) (a>b?a:b)
#define Min(a,b) (a<b?a:b)
#define next Cry_For_theMoon
#define il inline
#define pb(x) push_back(x)
#define is(x) insert(x)
#define sit set<int>::iterator
#define mapit map<int,int>::iterator
#define pi pair<int,int>
#define ppi pair<int,pi>
#define pp pair<pi,pi>
#define fr first
#define se second
#define vit vector<int>::iterator
#define mp(x,y) make_pair(x,y)
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef double db;
using namespace std;
const int MAXN=510,INF=1e9;
int n,k,m[MAXN];
char str[MAXN];
struct Trie{
	int ch[MAXN][10];
	int tot,w[MAXN],dp[MAXN][MAXN][15];
	char H(char ch){return ch-'0';}
	void Insert(char* s,int val){
		int u=0;
		for(int i=0;s[i];i++){
			if(!ch[u][H(s[i])])ch[u][H(s[i])]=++tot;
			u=ch[u][H(s[i])];
		}
		w[u]+=val;
	}
	void dfs(int u,int depth){
		rep(j,0,9){if(!ch[u][j])continue;
			dfs(ch[u][j],depth+1);
		}
		rep(i,0,depth)rep(j,0,k)dp[u][i][j]=i*w[u];
		rep(j,0,9){if(!ch[u][j])continue;
			int v=ch[u][j];
			rep(i,0,depth){
				per(x,k,0){
					dp[u][i][x]+=dp[v][i+1][0];
					rep(use,1,x)dp[u][i][x]=Min(dp[u][i][x],dp[u][i][x-use]+dp[v][i+1][use]),
					dp[u][i][x]=Min(dp[u][i][x],dp[u][i][x-use]+dp[v][0][use-1]);
				}
			}
		}
		/*
		rep(j,0,depth){
			rep(x,1,k){
				dp[u][j][x]=Min(dp[u][j][x],dp[u][0][x-1]);
			}
		}
		*/
	}
}trie;
int main(){
	cin>>n>>k;
	rep(i,1,n){
		cin>>str>>m[i];
		trie.Insert(str,m[i]);
	}
	trie.dfs(0,0);
	cout<<trie.dp[0][0][k];
	return 0;
}