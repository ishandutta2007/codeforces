#include <bits/stdc++.h>
using namespace std;



int n,m;
long long ans,ans2;
long long a[100005];
long long b[100005];


int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for (int i=1;i<=n;++i) {
        cin>>a[i];
    }
    for (int i=1;i<=n;++i) {
        int x;
        cin>>x;
        if (x==1) {
            ans+=a[i];
            a[i]=0;
        }
        b[i]=a[i];
        b[i]+=b[i-1];
        if (i>m) b[i]-=a[i-m];
        ans2=max(ans2,b[i]);
    }
    cout<<ans+ans2;
}