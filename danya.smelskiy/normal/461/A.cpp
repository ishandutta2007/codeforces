#include <bits/stdc++.h>
using namespace std;
int n;
long long a[500001];
long long ans,sum;
int main(){
    cin>>n;
    for (int i=1;i<=n;++i){
        cin>>a[i];
        sum+=a[i];
    }
    sort(a+1,a+n+1);
    for (int i=1;i<n;++i){
        ans+=sum+a[i];
        sum-=a[i];
    }
    cout<<ans+a[n];
}