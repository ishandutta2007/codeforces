#include <bits/stdc++.h>
using namespace std;



int n;
long long a[100005];
long long b[100005];
long long cnt[100005];
long long q[100005];
long long ans[100005];


int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;++i) {
        cin>>a[i];
    }
    for (int i=1;i<=n;++i) {
        cin>>b[i];
        b[i]+=b[i-1];
    }
    for (int i=1;i<=n;++i) {
        if (b[i]-b[i-1]>=a[i]) {
            ans[i]+=a[i];
            continue;
        }
        int l=i;
        int r=n;
        while (l<r-1) {
            int mid=(l+r)>>1;
            if (b[mid]-b[i-1]<=a[i]) l=mid;
            else r=mid;
        }
        if (b[r]-b[i-1]<=a[i]) l=r;
        q[i]+=a[i];
        ++cnt[i];
        --cnt[l+1];
        long long x=a[i]-(b[l]-b[i-1]);
        ans[l+1]+=x;
    }
    for (int i=1;i<=n;++i) {
        cnt[i]+=cnt[i-1];
    }
    for (int i=1;i<=n;++i) {
        cout<<cnt[i]*(b[i]-b[i-1])+ans[i]<<" ";
    }
}