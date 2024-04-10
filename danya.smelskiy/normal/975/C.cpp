#include <bits/stdc++.h>
using namespace std;


int n,m;
long long a[200005];
long long x;


int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for (int i=1;i<=n;++i) {
        cin>>a[i];
        a[i]+=a[i-1];
    }
    long long last=0;
    int l,r;
    for (int i=1;i<=m;++i) {
        cin>>x;
        last+=x;
        if (last>=a[n]) {
            last=0;
            cout<<n<<'\n';
            continue;
        }
        l=1;
        r=n;
        while (l<r-1) {
            int mid=(l+r)>>1;
            if (a[mid]<=last) l=mid;
            else r=mid;
        }
        if (a[r]<=last) l=r;
        if (a[l]<=last) cout<<n-l<<'\n';
        else cout<<n-l+1<<'\n';
    }
}