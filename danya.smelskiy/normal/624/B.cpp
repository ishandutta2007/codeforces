#include <bits/stdc++.h>
using namespace std;


long long ans;
int a[100];
int n;

int main(){
    cin>>n;
    for (int i=1;i<=n;++i)
        cin>>a[i];
    sort(a+1,a+n+1);
    for (int i=n-1;i>0;--i) {
        if (a[i]>=a[i+1]) {
            a[i]=a[i+1]-1;
            a[i]=max(a[i],0);
        }
    }
    for (int i=1;i<=n;++i)
        ans+=a[i];
    cout<<ans;
}