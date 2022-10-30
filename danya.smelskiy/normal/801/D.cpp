#include <bits/stdc++.h>
using namespace std;



int n;
pair<long double,long double> a[5000005];
long double ans=1e18;
inline long double get(int a1,int a2,int a3){
    long double x,y,xx,yy,xx2,yy2;
    x=a[a1].first;
    y=a[a1].second;
    xx=a[a2].first;
    yy=a[a2].second;
    xx2=a[a3].first;
    yy2=a[a3].second;
    long double z=abs((yy2-yy)*x-(xx2-xx)*y+xx2*yy-yy2*xx);
    z=z/sqrt((yy2-yy)*(yy2-yy)+(xx2-xx)*(xx2-xx));
    return z/2;
}
int main(){
    cin>>n;
    for (int i=1;i<=n;++i)
        cin>>a[i].first>>a[i].second;
    for (int i=2;i<n;++i)
        ans=min(ans,get(i,i-1,i+1));
    ans=min(ans,get(1,n,2));
    ans=min(ans,get(n,n-1,1));
    cout<<fixed<<setprecision(6)<<ans;
}