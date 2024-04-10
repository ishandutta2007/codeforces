#include <bits/stdc++.h>
using namespace std;
int n,m,k1,k2;
int a[100001];
int b[100001];

bool cmp(int a,int b){
    return (a>b);
}
int main(){

    cin>>n>>m;
    cin>>k1>>k2;
    for (int i=1;i<=n;++i) cin>>a[i];
    for (int i=1;i<=m;++i) cin>>b[i];
    sort(a+1,a+n+1);
    sort(b+1,b+m+1,cmp);
    if (a[k1]<b[k2]) cout<<"YES";
    else cout<<"NO";
}