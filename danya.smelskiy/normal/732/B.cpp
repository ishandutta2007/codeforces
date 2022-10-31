#include <bits/stdc++.h>
using namespace std;
int a[100001];
int n,k;
long long ans;
int main(){
    cin>>n>>k;
    for (int i=1;i<=n;++i){
        cin>>a[i];
        if (i>1){
            if (a[i-1]+a[i]<k){
                ans+=(k-a[i]-a[i-1]);
                a[i]+=(k-a[i]-a[i-1]);
            }
        }
    }
    cout<<ans<<endl;
    for (int i=1;i<=n;++i)
        cout<<a[i]<<" ";
}