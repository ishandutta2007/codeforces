#include <bits/stdc++.h>
using namespace std;
long long n,m,a[1000001],b[1000001];
int main(){
    cin>>n>>m;
    for (int i=1;i<=n;++i){
        cin>>a[i];
    }
    for (int i=1;i<=m;++i){
        cin>>b[i];
    }
    sort(a+1,a+n+1);
    sort(b+1,b+m+1);
    long long l=max(a[1]*2,a[n]);
    if (l>=b[1]) cout<<"-1";
    else cout<<l;
}