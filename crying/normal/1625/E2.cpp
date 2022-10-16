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
const int MAXN=3e5+10;
int n,q;
char s[MAXN];
int st[MAXN],top,match[MAXN];
int num[MAXN],cnt[MAXN],idx[MAXN],F[MAXN],tot;
int sz[MAXN];
struct BIT{
    vector<ll>t;
    int tot;
    void set(int len){
        t.resize(len+10);
        tot=len;
    }
    void upd(int x,ll v){for(;x<=tot;x+=lowbit(x))t[x]+=v;}
    ll qry(int x){ll r=0;for(;x;x-=lowbit(x))r+=t[x];return r;}
    ll qry(int l,int r){return qry(r)-qry(l-1);}
}t,del[MAXN];
void build(int l,int r,int fa){
    if(l>r)return;
    if(s[l]!='(' || !match[l])return (void)(build(l+1,r,fa));
    if(s[r]!=')' || !match[r])return (void)(build(l,r-1,fa));
    num[l]=num[match[l]]=++tot;sz[tot]=1;
    cnt[fa]++;idx[tot]=cnt[fa];F[tot]=fa;
    build(l+1,match[l]-1,tot);
    sz[fa]+=sz[num[l]];
    build(match[l]+1,r,fa);
}
ll S(ll n){return n*(n+1)/2;}
int main(){
    scanf("%d%d%s",&n,&q,s+1);
    rep(i,1,n){
        if(s[i]=='(')st[++top]=i;
        else if(top)match[i]=st[top],match[st[top]]=i,top--;
    }
    build(1,n,0);
    t.set(tot);
    rep(i,0,tot)del[i].set(cnt[i]);
    rep(i,1,tot)t.upd(i,S(cnt[i]));
    rep(i,1,q){
        int tp,l,r;
        scanf("%d%d%d",&tp,&l,&r);
        if(tp==1){
            int u=num[l],fa=F[u];
            del[fa].upd(idx[u],1);
            if(fa)t.upd(fa,-S(cnt[fa]));
            cnt[fa]--;
            if(fa)t.upd(fa,S(cnt[fa]));
        }else{
            int L=num[l],R=num[r],fa=F[L];
            int k=(idx[R]-del[fa].qry(idx[R]))-(idx[L]-del[fa].qry(idx[L]))+1;
            R=R+sz[R]-1;
            ll ans=t.qry(L,R)+S(k);
            printf("%lld\n",ans);
        }
    }
    return 0;
}