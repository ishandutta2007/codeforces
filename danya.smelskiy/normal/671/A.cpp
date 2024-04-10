#include <bits/stdc++.h>
using namespace std;
const long double inf=1e15;


long double ans,ans2;
inline long double d(long double x,long double y,long double xx,long double yy){
    return sqrt((x-xx)*(x-xx)+(y-yy)*(y-yy));
}
int n;
long double ax,ay,bx,by,tx,ty;
pair<long double,long double> a[100005];
long double dp1[100005];
long double dp2[100005];
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>ax>>ay>>bx>>by>>tx>>ty;
    cin>>n;
    for (int i=1;i<=n;++i){
        cin>>a[i].first>>a[i].second;
        ans+=2*d(a[i].first,a[i].second,tx,ty);
    }
    dp1[0]=inf;
    dp2[n+1]=inf;
    ans2=inf;
    for (int i=1;i<=n;++i)
        dp1[i]=min(dp1[i-1],d(a[i].first,a[i].second,bx,by)-d(a[i].first,a[i].second,tx,ty));
    for (int i=n;i>0;--i)
        dp2[i]=min(dp2[i+1],d(a[i].first,a[i].second,bx,by)-d(a[i].first,a[i].second,tx,ty));
    for (int i=1;i<=n;++i){
        long double q=ans;
        q-=d(a[i].first,a[i].second,tx,ty);
        q+=d(a[i].first,a[i].second,ax,ay);
        q+=min(dp1[i-1],dp2[i+1]);
        ans2=min(ans2,q);
        ans2=min(ans2,ans-d(a[i].first,a[i].second,tx,ty)+d(a[i].first,a[i].second,ax,ay));
        ans2=min(ans2,ans-d(a[i].first,a[i].second,tx,ty)+d(a[i].first,a[i].second,bx,by));
    }
    cout<<fixed<<setprecision(8)<<ans2;
}