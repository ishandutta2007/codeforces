#include <bits/stdc++.h>
using namespace std;
int n;
int mn=1e9;
int a[1005];
int mx;

int main(){
    cin>>n;
    for (int i=1;i<=n;++i) {
        cin>>a[i]; mn=min(mn,a[i]);
    }
    mx=1e9;
    for (int i=1;i<=n;++i)
        if (a[i]>mn && a[i]<mx) mx=a[i];
    if (mx==1e9) cout<<"NO";
    else cout<<mx;
}