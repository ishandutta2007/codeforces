#include <bits/stdc++.h>
using namespace std;
int a[100001];
int n,c;
long long ans=0;
int main(){
    cin>>n>>c;
    for (int i=1;i<=n;++i){
        cin>>a[i];
    }
    for (int i=1;i<n;++i){
        if (a[i]-a[i+1]-c>ans) ans=a[i]-a[i+1]-c;
    }
    cout<<ans;
}