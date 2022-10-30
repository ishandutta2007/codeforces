#include <bits/stdc++.h>
using namespace std;

long long n,m,k,x,ans=1e15;
int main(){
    cin>>n>>m>>k;
    for (int i=1;i<=n;++i){
        cin>>x;
        if (x!=0 && i!=m && x<=k) ans=min(ans,abs(i-m)*10);
    }
    cout<<ans;
}