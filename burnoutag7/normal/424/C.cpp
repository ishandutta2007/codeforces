#include<bits/stdc++.h>
using namespace std;

int n,ans,f[1000005];

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for(int i=1;i<=n;i++){
        static int t;
        cin>>t;
        ans^=t;
        f[i]=i^f[i-1];
    }
    for(int i=1;i<=n;i++){
        if(n/i&1)ans^=f[i-1];
        ans^=f[n%i];
    }
    cout<<ans<<endl;

    return 0;
}