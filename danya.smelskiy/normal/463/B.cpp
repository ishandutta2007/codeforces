#include <bits/stdc++.h>
using namespace std;
int n;
int a[100001];
int l,ans;
int main(){
    cin>>n;
    for (int i=1;i<=n;++i){
        cin>>a[i];
    }
    for (int i=0;i<=n;++i){
        ans+=a[i]-a[i-1];
        if (ans>0){
            l+=ans;
            ans=0;
        }
    }
    cout<<l;
}