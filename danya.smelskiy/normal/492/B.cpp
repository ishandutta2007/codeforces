#include <bits/stdc++.h>
using namespace std;
long long n,l;
long double a[100001];
long double ans;
int main(){
    cin>>n>>l;
    for (int i=1;i<=n;++i)
        cin>>a[i];
    sort(a+1,a+n+1);
    for (int i=2;i<=n;++i){
        if (a[i]-a[i-1]>ans) ans=a[i]-a[i-1];
    }
    cout<<fixed<<setprecision(9)<<max(ans/2,max(a[1],l-a[n]));
}