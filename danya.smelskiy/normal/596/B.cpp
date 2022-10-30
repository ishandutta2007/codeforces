#include <bits/stdc++.h>
using namespace std;
long long n,a[200001],ans;
int main(){
    cin>>n;
    for (int i=1;i<=n;++i){
        cin>>a[i];
        ans+=abs(a[i]-a[i-1]);
    }
    cout<<ans;
}