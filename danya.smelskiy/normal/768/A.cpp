#include <bits/stdc++.h>
using namespace std;
int n;
int ans;
int a[100001];
int main(){
    cin>>n;
    for (int i=1;i<=n;++i)
        cin>>a[i];
    sort(a+1,a+n+1);
    for (int i=1;i<=n;++i)
        if (a[i]!=a[1] && a[i]!=a[n]) ++ans;
    cout<<ans;
}