#include <bits/stdc++.h>
#define pb push_back
#define pr pair<int,int>
#define mp make_pair
#define fi first
#define se second
using namespace std;
const long long INF=1LL<<60;
const int N=1e6+6;
pair< pr ,int> c[N];
pr a[N],b[N];
long long mx[N],tg[N];
void up(int rt){ mx[rt]=max(mx[rt<<1],mx[rt<<1|1])+tg[rt]; }
void build(int rt,int l,int r){
    if (l==r){ mx[rt]=-b[l].se; return; }
    int m=l+r>>1;
    build(rt<<1,l,m),build(rt<<1|1,m+1,r);
    up(rt);
}
void add(int rt,int l,int r,int ql,int y){
    if (r<ql) return;
    if (l>=ql){ mx[rt]+=y,tg[rt]+=y; return; }
    int m=l+r>>1;
    add(rt<<1,l,m,ql,y),add(rt<<1|1,m+1,r,ql,y);
    up(rt);
}
int main(){
    int n,m,p; cin>>n>>m>>p;
    for (int i=1;i<=n;++i) scanf("%d%d",&a[i].fi,&a[i].se);
    for (int i=1;i<=m;++i) scanf("%d%d",&b[i].fi,&b[i].se);
    for (int i=1;i<=p;++i) scanf("%d%d%d",&c[i].fi.fi,&c[i].fi.se,&c[i].se);
    sort(a+1,a+1+n),sort(b+1,b+1+m),sort(c+1,c+1+p);
    build(1,1,m);
    long long ans=-INF;
    for (int i=1,j=0;i<=n;++i){
        while (j<p&&c[j+1].fi.fi<a[i].fi){
            int t=lower_bound(b+1,b+1+m,mp(c[j+1].fi.se+1,0))-b;
            if (t<=m) add(1,1,m,t,c[j+1].se);
            ++j;
        }
        ans=max(ans,-a[i].se+mx[1]);
    }
    cout<<ans<<endl;
}