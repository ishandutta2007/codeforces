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
const int MAXN=1e5+10;
int T,n,k,a[MAXN];
map<int,int>f;
struct seg{
    int cnt[MAXN<<2],sum[MAXN<<2];
    void pushup(int x){
        cnt[x]=cnt[lc(x)]+cnt[rc(x)];
        sum[x]=sum[lc(x)]+sum[rc(x)];
    }
    void build(int x,int l,int r){
        cnt[x]=sum[x]=0;
        if(l==r)return;
        int mid=(l+r)>>1;
        build(lc(x),l,mid);build(rc(x),mid+1,r);
    }
    void upd(int x,int l,int r,int pos,int v1,int v2){
        if(l==r){
            cnt[x]+=v1;sum[x]+=v2;
            return;
        }
        int mid=(l+r)>>1;
        if(pos<=mid)upd(lc(x),l,mid,pos,v1,v2);
        else upd(rc(x),mid+1,r,pos,v1,v2);
        pushup(x);
    }
    int qry(int x,int l,int r,int k){
        if(l==r){return min(cnt[x],k/l);}
        int mid=(l+r)>>1;
        if(sum[lc(x)]>=k)return qry(lc(x),l,mid,k);
        else{
            int ret=cnt[lc(x)];
            ret+=qry(rc(x),mid+1,r,k-sum[lc(x)]);
            return ret;
        }
    }
}t;
void solve(){
    cin>>n>>k;f.clear();
    rep(i,1,n)cin>>a[i],f[a[i]]++;
    t.build(1,1,n);
    int ans=0,cnt=n,diff=0;
    for(auto p:f){
        t.upd(1,1,n,p.second,1,p.second);
        ans++;diff++;
    }
    int need=0;
    rep(i,0,n-1){
        //i
        if(f.find(i)==f.end())need++;
        else cnt--,t.upd(1,1,n,f[i],-1,-f[i]);
        if(cnt<need || k<need)break;
        int delta=t.qry(1,1,n,k);
        ans=min(ans,(diff-delta+need)-(i+1));
    }
    cout<<ans<<'\n';    
}
int main(){
    ios::sync_with_stdio(false);
    cin>>T;
    while(T--)solve();


    return 0;
}