#include <bits/stdc++.h>
using namespace std;
long long n,x,ans;
long long a[500001];
long long maxim;
int main(){
    cin>>n;
    for (int i=1;i<=n;++i){
        cin>>a[i];
        maxim=max(maxim,a[i]);
    }
    for (int i=1;i<=n;++i)
        ans+=maxim-a[i];
    cout<<ans;
}