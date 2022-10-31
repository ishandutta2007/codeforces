#include <bits/stdc++.h>
using namespace std;

int n,m;
int a[1005];

int main(){
    //
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for (int i=1;i<=n+n+1;++i) {
        cin>>a[i];
    }
    for (int i=2;i<=n+n+1;i+=2)
    if (a[i]-1>a[i-1] && a[i]-1>a[i+1] && m) {
        --a[i];
        --m;
    }
    for (int i=1;i<=n+n+1;++i)
        cout<<a[i]<<" ";
}