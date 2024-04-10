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
const ll MAXN=1.5e4+10,MAXM=3e4+10,MAXK=1e3+10,INF=1e18;
const int P=1e7+19,mod=1e9+7;
int n,k,v[MAXN],w[MAXN],l[MAXN],r[MAXN];
int q,op[MAXM],power[MAXK];
ll f[MAXN][MAXK];
int top;
vector<pi>arr[MAXM<<2];
void add(int x,int l,int r,int ql,int qr,int v,int w){
    if(ql<=l && qr>=r){
        arr[x].pb(mp(v,w));
        return;
    }
    int mid=(l+r)>>1;
    if(ql<=mid)add(lc(x),l,mid,ql,qr,v,w);
    if(qr>mid)add(rc(x),mid+1,r,ql,qr,v,w);
}
void solve(int x,int l,int r){
    for(auto p:arr[x]){
        top++;
        rep(i,0,k)f[top][i]=f[top-1][i];
        rep(i,p.se,k)f[top][i]=max(f[top][i],f[top-1][i-p.se]+p.fr);
    }
    if(l==r){
        if(op[l]==3){
            ll ret=0;
            rep(i,1,k){
                ret=(ret+f[top][i]*power[i-1]%mod)%mod;
            }
            printf("%lld\n",ret);
        }
        return;
    }
    int cur=top;
    int mid=(l+r)>>1;
    solve(lc(x),l,mid);
    top=cur;
    solve(rc(x),mid+1,r);
}
int main(){
    power[0]=1;rep(i,1,1e3)power[i]=1ll*power[i-1]*P%mod;
    scanf("%d%d",&n,&k);
    rep(i,1,n)scanf("%d%d",&v[i],&w[i]);
    scanf("%d",&q);
    rep(i,1,n)l[i]=1,r[i]=q;
    rep(i,1,q){
        scanf("%d",&op[i]);
        if(op[i]==1){
            n++;scanf("%d%d",&v[n],&w[n]);
            l[n]=i;r[n]=q;
        }else if(op[i]==2){
            int x;scanf("%d",&x);
            r[x]=i;
        }
    }
    rep(i,1,n)add(1,1,q,l[i],r[i],v[i],w[i]);
    solve(1,1,q);
    return 0;
}