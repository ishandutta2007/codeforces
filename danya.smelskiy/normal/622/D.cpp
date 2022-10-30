#include <bits/stdc++.h>
using namespace std;

int n;
int ans[1000005];


int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i=1;i<=n/2;++i) {
        ans[i]=ans[n-i+1]=i*2-1;
    }
    for (int i=1;i<=n/2;++i) {
        ans[n+i]=ans[n+n-i]=i*2;
    }
    for (int i=1;i<=n+n;++i)
        if (!ans[i]) cout<<n<<" ";
        else cout<<ans[i]<<" ";
}