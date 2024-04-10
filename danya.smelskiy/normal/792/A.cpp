#include <bits/stdc++.h>
using namespace std;

long long ans,ans2,a[300005];
long long n;
int main(){
    cin>>n;
    for (int i=1;i<=n;++i){
    cin>>a[i];
    }
    sort(a+1,a+n+1);
    long long ans=a[2]-a[1];
    int ans2=1;
    for (int i=3;i<=n;++i){
        if (a[i]-a[i-1]<ans) {
            ans=a[i]-a[i-1];
            ans2=1;
        } else if (a[i]-a[i-1]==ans)  ++ans2;
    }
    cout<<ans<<" "<<ans2;
}