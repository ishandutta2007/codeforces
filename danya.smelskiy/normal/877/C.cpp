#include <bits/stdc++.h>
using namespace std;

int n;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    cout<<n+n/2<<'\n';
    for (int i=2;i<=n;i+=2)
        cout<<i<<" ";
    for (int i=1;i<=n;i+=2)
        cout<<i<<" ";
    for (int i=2;i<=n;i+=2)
        cout<<i<<" ";
}