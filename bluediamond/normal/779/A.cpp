#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int a[6],b[6];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,x;
    cin>>n;
    for(int i=1;i<=n;i++) {
        cin>>x;
        a[x]++;
    }
    for(int i=1;i<=n;i++) {
        cin>>x;
        b[x]++;
    }
    int ans=0;
    for(int i=1;i<=5;i++) {
        if((a[i]+b[i])%2==1) {
            cout<<"-1\n";
            return 0;
        }
        ans+=max(a[i],b[i])-(a[i]+b[i])/2;
    }
    cout<<ans/2<<"\n";
    return 0;
}