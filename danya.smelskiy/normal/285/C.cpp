#include <bits/stdc++.h>
using namespace std;
long long n,ans;
long long a[10000001];
long long b[1000001];
int main(){
    cin>>n;
    for (int i=1;i<=n;++i){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for (int i=1;i<=n;++i){
        ans+=abs(a[i]-i);
    }
    cout<<ans<<endl;
}