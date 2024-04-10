#include <bits/stdc++.h>
using namespace std;
int a[100001];
long long n,last,ans;
int main(){
    cin>>n;
    for (int i=1;i<=n;++i){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for (int i=1;i<=n;++i){
        if (last<=a[i]) { ++ans; last+=a[i];}
    }
    cout<<ans;
}