#include <bits/stdc++.h>
using namespace std;

int n,k;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>k;
    int res=(n-1)/k;
    res+=res;
    if ((n-1)%k==1) ++res;
    else if ((n-1)%k>=2) res+=2;
    cout<<res<<'\n';
    for (int i=1;i<=k;++i)
        cout<<1<<" "<<1+i<<'\n';
    for (int i=2+k;i<=n;++i)
        cout<<i-k<<" "<<i<<'\n';
}