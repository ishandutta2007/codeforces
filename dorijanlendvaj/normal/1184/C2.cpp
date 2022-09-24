#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
typedef long long ll;
const int N=3e5+1;
const int ts=1<<20;
int n;
ll k;
ll x[N],y[N];
pair<ll,int>sx[N],sy[N];
int mx[ts],tg[ts];
void push(int id){
    tg[id*2]+=tg[id];
    mx[id*2]+=tg[id];
    tg[id*2+1]+=tg[id];
    mx[id*2+1]+=tg[id];
    tg[id]=0;
}
void upd(int id,int l,int r,int ql,int qr,int v){
    if(l>qr || r<ql) return;
    if(ql<=l && r<=qr){
        tg[id]+=v;mx[id]+=v;
        return;
    }
    push(id);
    int mid=(l+r)/2;
    upd(id*2,l,mid,ql,qr,v);
    upd(id*2+1,mid+1,r,ql,qr,v);
    mx[id]=max(mx[id*2],mx[id*2+1]);
}
int qry(int id,int l,int r,int ql,int qr){
    if(l>qr || r<ql) return 0;
    if(ql<=l && r<=qr) return mx[id];
    push(id);
    int mid=(l+r)/2;
    return max(qry(id*2,l,mid,ql,qr),qry(id*2+1,mid+1,r,ql,qr));
}
int main(){
    ios::sync_with_stdio(false);
    cin >> n >> k;k*=2;
    for(int i=1; i<=n ;i++){
        ll u,v;cin >> u >> v;
        x[i]=u-v;y[i]=u+v;
        sx[i]={x[i],i};sy[i]={y[i],i};
    }
    sort(sx+1,sx+n+1);
    sort(sy+1,sy+n+1);
    int ptr=1;
    int ans=0;
    for(int i=1; i<=n ;i++){
        while(sy[i].fi-sy[ptr].fi>k){
            int cur=sy[ptr].se;
            int l=lower_bound(sx+1,sx+n+1,make_pair(x[cur]-k,0))-sx;
            int r=lower_bound(sx+1,sx+n+1,make_pair(x[cur]+1,0))-sx-1;
            upd(1,1,n,l,r,-1);
            ptr++;
        }
        int cur=sy[i].se;
        int l=lower_bound(sx+1,sx+n+1,make_pair(x[cur]-k,0))-sx;
        int r=lower_bound(sx+1,sx+n+1,make_pair(x[cur]+1,0))-sx-1;
        upd(1,1,n,l,r,1);
        ans=max(ans,mx[1]);
    }
    cout << ans << endl;
}