#include <bits/stdc++.h>
using namespace std;
int a[100001],b[100001];
int n;
int last;
long long ans;
int main(){
    cin>>n;
    cin>>a[1]>>b[1];
    last=b[1];
    ans=b[1]*a[1];
    for (int i=2;i<=n;++i){
        cin>>a[i]>>b[i];
        if (b[i]<last) last=b[i];
        ans+=a[i]*last;
    }
    cout<<ans;
}