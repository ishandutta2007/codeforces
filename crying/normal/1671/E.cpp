#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define op(x) ((x&1)?x+1:x-1)
#define odd(x) (x&1)
#define even(x) (!odd(x))
#define lc(x) (x<<1)
#define rc(x) (lc(x)|1)
#define lowbit(x) (x&-x)
#define mp(x,y) make_pair(x,y)
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
using namespace std;
const int MAXN=(1<<19),mod=998244353;
int n;
char s[MAXN];
ll f[MAXN];
string S[MAXN];
void dfs1(int u,int depth){
    S[u]+=s[u];
    if(depth==n)return;
    dfs1(lc(u),depth+1);dfs1(rc(u),depth+1);
    if(S[lc(u)]<S[rc(u)])S[u]=S[u]+S[lc(u)]+S[rc(u)];
    else S[u]=S[u]+S[rc(u)]+S[lc(u)];
}
void dfs2(int u,int depth){
    if(depth==n){f[u]=1;return;}
    dfs2(lc(u),depth+1);dfs2(rc(u),depth+1);
    f[u]=f[lc(u)]*f[rc(u)]%mod;
    if(S[lc(u)]!=S[rc(u)]){
        f[u]=(f[u]+f[rc(u)]*f[lc(u)]%mod)%mod;
    }
}
int main(){
    cin>>n>>(s+1);
    dfs1(1,1);
    dfs2(1,1);
    cout<<f[1];
    return 0;
}