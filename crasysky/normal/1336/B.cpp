#include <bits/stdc++.h>
#define rep(i,l,r) for (int i=l,i##end=r;i<=i##end;++i)
#define per(i,r,l) for (int i=r,i##end=l;i>=i##end;--i)
#define pr pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define ll long long
using namespace std;
const int N=1e6+6,P=998244353;
const long long INF=3e18;
int l[N][3],r[N][3];
pr a[N];
ll calc(int a,int b,int c){
    return (ll)(a-b)*(a-b)+(ll)(a-c)*(a-c)+(ll)(b-c)*(b-c);
}
signed main(){
    int T; scanf("%d",&T);
    while (T--){
        int na,nb,nc; scanf("%d%d%d",&na,&nb,&nc);
        rep(i,1,na) scanf("%d",&a[i].fi),a[i].se=0;
        rep(i,1,nb) scanf("%d",&a[na+i].fi),a[na+i].se=1;
        rep(i,1,nc) scanf("%d",&a[na+nb+i].fi),a[na+nb+i].se=2;
        int n=na+nb+nc;
        sort(a+1,a+1+n);
        rep(i,2,n){
            l[i][0]=l[i-1][0],l[i][1]=l[i-1][1],l[i][2]=l[i-1][2];
            l[i][a[i-1].se]=i-1;
        }
        r[n][0]=r[n][1]=r[n][2]=0;
        per(i,n-1,1){
            r[i][0]=r[i+1][0],r[i][1]=r[i+1][1],r[i][2]=r[i+1][2];
            r[i][a[i+1].se]=i+1;
        }
        ll ans=INF;
        rep(i,1,n){
            int p=-1,q;
            rep(j,0,2)
                if (j!=a[i].se){
                    if (p==-1) p=j;
                    else q=j;
                }
            if (l[i][p]&&r[i][q]) ans=min(ans,calc(a[i].fi,a[l[i][p]].fi,a[r[i][q]].fi));
            if (l[i][q]&&r[i][p]) ans=min(ans,calc(a[i].fi,a[l[i][q]].fi,a[r[i][p]].fi));
        }
        cout<<ans<<endl;
    }
    return 0;
}