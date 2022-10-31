#include <bits/stdc++.h>
using namespace std;




int n,m;
long long a[200005];
long long x;

int main() {
//    freopen("input.in","r",stdin);
  //  freopen("output.out","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for (int i=1;i<=n;++i) {
        cin>>a[i];
        a[i]+=a[i-1];
    }
    int l,r;
    for (int i=1;i<=m;++i) {
        cin>>x;
        l=1;
        r=n;
        while (l<r-1) {
            int mid=(l+r)>>1;
            if (a[mid]>=x) r=mid;
            else l=mid;
        }
        if (a[l]>=x) r=l;
        cout<<r<<" "<<x-a[r-1]<<'\n';
    }
}