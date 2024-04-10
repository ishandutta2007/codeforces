#include <bits/stdc++.h>
using namespace std;
long long n,m;
long long a,ans;
int main(){
    cin>>n>>m;
    for (int i=0;i<=n;++i){
        a=i*2;
        if (i*2>m) break;
        ans=max(ans,i+min((n-i)/2,(m-i*2)));
    }
    cout<<ans;
}