#include <bits/stdc++.h>
using namespace std;


long double pi=3.141592653589793;
int n;
long double l,r;
long double x[25],y[25],a[25];
long double dp[(1<<20)+5];
inline long double getnxt(long double xx,int t){
    long double ang=a[t]-atan((long double)((x[t]-xx)/y[t]));
    if (ang>(pi/2)) return 1e9;
    return x[t]+tan(ang)*y[t];
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>l>>r;
    for (int i=1;i<=n;++i) {
        cin>>x[i]>>y[i]>>a[i];
        a[i]=(a[i]*pi)/180;
    }
    for (int i=0;i<(1<<n);++i) {
        dp[i]=l;
        for (int j=0;j<n;++j) if ((i&(1<<j))) {
            long double z=getnxt(dp[(i^(1<<j))],j+1);
            dp[i]=max(dp[i],z);
        }
    }
    cout<<fixed<<setprecision(9);
    if (dp[(1<<n)-1]>r) cout<<r-l;
    else cout<<dp[(1<<n)-1]-l;
}