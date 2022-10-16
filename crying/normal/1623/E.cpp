#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
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
const int MAXN=2e5+10;
int n,k,lc[MAXN],rc[MAXN];
char s[MAXN];
int pos[MAXN],tot,tag[MAXN],vis[MAXN];
void dfs(int u){
    if(lc[u])dfs(lc[u]);
    pos[++tot]=u;
    if(rc[u])dfs(rc[u]);
}
int dfs2(int u,int c){
    if(!u)return 0;
    if(c>k)return 0;
    if(dfs2(lc[u],c+1))vis[u]=1;
    else if(k>0&&tag[u])vis[u]=1,k-=c;
    if(vis[u])dfs2(rc[u],1);
    return vis[u];
}
int main(){
    ios::sync_with_stdio(false);
    cin>>n>>k>>(s+1);
    rep(i,1,n)cin>>lc[i]>>rc[i];
    dfs(1);
    int st=1;
    rep(i,2,n){
        if(s[pos[i]]!=s[pos[i-1]]){
            if(s[pos[i]]>s[pos[i-1]]){
                rep(j,st,i-1)tag[pos[j]]=1;
            }
            st=i;
        }
    }
    dfs2(1,1);   
    rep(i,1,n)rep(j,1,1+vis[pos[i]])putchar(s[pos[i]]);
    return 0;
}