#include <bits/stdc++.h>
using namespace std;
int n;
int ans[1005];
int a[1005];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;++i)
        cin>>a[i];
    sort(a+1,a+n+1);
    ans[1]=a[n];
    ans[n]=a[1];
    for (int i=2;i<n;++i)
        ans[i]=a[i];
    for (int i=1;i<=n;++i)
    cout<<ans[i]<<" ";
}