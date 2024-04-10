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
const int MAXN=1.5e5+10,MAXM=MAXN*30,mod=998244353;
int n,x,a[MAXN];
int ch[MAXM][2],sz[MAXM],tot=1;
ll power[MAXN];
void Ins(int u,int x,int d){
    sz[u]++;
    if(d<0)return;
    int v=x>>d&1;
    if(!ch[u][v])ch[u][v]=++tot;
    Ins(ch[u][v],x,d-1);
}
ll dfs(int u1,int u2,int d){
    if(!u1)return power[sz[u2]];
    if(!u2)return power[sz[u1]];
    if(u1==u2){
        if(d<0)return power[sz[u1]];
        int lc=ch[u1][0],rc=ch[u1][1];
        if(x>>d&1)return dfs(lc,rc,d-1);
        return (dfs(lc,lc,d-1)+dfs(rc,rc,d-1)+mod-1)%mod;
    }else{
        if(d<0)return power[sz[u1]+sz[u2]];
        int lc1=ch[u1][0],lc2=ch[u2][0],rc1=ch[u1][1],rc2=ch[u2][1];
        if(x>>d&1)return dfs(lc1,rc2,d-1)*dfs(rc1,lc2,d-1)%mod;
        ll ret=0;
        ret=(dfs(lc1,lc2,d-1)+dfs(rc1,rc2,d-1)+mod-1)%mod;
        ret=(ret+(power[sz[lc1]]+mod-1)*(power[sz[rc1]]+mod-1)%mod)%mod;
        ret=(ret+(power[sz[lc2]]+mod-1)*(power[sz[rc2]]+mod-1)%mod)%mod;
        return ret;
    }
}
int main(){
    power[0]=1;rep(i,1,1.5e5)power[i]=power[i-1]*2%mod;
    scanf("%d%d",&n,&x);
    rep(i,1,n){
        scanf("%d",&a[i]);
        Ins(1,a[i],29);
    }
    ll ans=dfs(1,1,29);
    ans=(ans+mod-1)%mod;
    printf("%lld",ans);
    return 0;
}