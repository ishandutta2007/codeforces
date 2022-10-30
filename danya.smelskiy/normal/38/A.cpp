#include <bits/stdc++.h>
using namespace std;
long long n,ans,l,r,a[100001];
int main(){
    cin>>n;
    for (int i=1;i<n;++i)
        cin>>a[i+1];
    cin>>l>>r;
    for (int i=l+1;i<=r;++i)
        ans+=a[i];
    cout<<ans;
}