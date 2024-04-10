#include <bits/stdc++.h>
using namespace std;
int n;
long long ans=1e9;
int a[100001];
int pos;
int main(){
    cin>>n;
    for (int i=1;i<=n;++i) cin>>a[i];
    for (int i=2;i<n;++i){
        if (a[i+1]-a[i-1]<ans) { ans=a[i+1]-a[i-1]; pos=i;}
    }
    a[pos]=0;
    ans=0;
    sort(a+1,a+n+1);
    for (int i=3;i<=n;++i){
        if (a[i]-a[i-1]>ans) ans=a[i]-a[i-1];
    }
    cout<<ans;
}