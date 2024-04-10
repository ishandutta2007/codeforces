#include <bits/stdc++.h>
using namespace std;
int n,a[1000001];
long long  now=0,ans=0;
int main(){
    cin>>n;
    for (int i=1;i<=n;++i){
        cin>>a[i]; ans+=a[i];
    }
    sort(a+1,a+n+1);
    for (int i=n;i>0;--i){
        now+=a[i];
        ans-=a[i];
        if (now>ans) {
            cout<<n-i+1;
            return 0;
        }
    }
}