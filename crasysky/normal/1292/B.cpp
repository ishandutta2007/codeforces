#include <bits/stdc++.h>
#define rep(i,l,r) for (int i=l,i##end=r;i<=i##end;++i)
#define per(i,r,l) for (int i=r,i##end=l;i>=i##end;--i)
#define ll long long
#define pr pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define pb push_back
using namespace std;
const int N=1e6+6;
ll x[N],y[N];
ll d(ll x1,ll y1,ll x2,ll y2){
    return fabs(x1-x2)+fabs(y1-y2);
}
int read(){
    int c=0; char ch=getchar();
    while (ch<'0'||'9'<ch) ch=getchar();
    while ('0'<=ch&&ch<='9') c=c*10+ch-'0',ch=getchar();
    return c;
}
int main(){
    ll ax,ay,bx,by,xs,ys,t;
    cin>>x[0]>>y[0]>>ax>>ay>>bx>>by>>xs>>ys>>t;
    int m=1;
    for (;;++m){
        x[m]=ax*x[m-1]+bx,y[m]=ay*y[m-1]+by;
        if (x[m]>xs+t||y[m]>ys+t) break;
    }
    int ans=0;
    rep(l,0,m)
        rep(r,l,m){
            if (d(xs,ys,x[l],y[l])+d(x[l],y[l],x[r],y[r])<=t)
                ans=max(ans,r-l+1);
            if (d(xs,ys,x[r],y[r])+d(x[l],y[l],x[r],y[r])<=t)
                ans=max(ans,r-l+1);
        }
    cout<<ans<<endl;
    return 0;
}