#include <bits/stdc++.h>
using namespace std;

int n,m;
int q[100005];
int qq[100005];
int dp1[100005];
int ans;
int sz=0;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for (int i=1;i<=n;++i) {
        int x,y;
        cin>>x>>y;
        ++q[x];
        --q[y+1];
    }
    for (int i=1;i<=m;++i) {
        q[i]+=q[i-1];
    }
    sz=0;
    for (int i=1;i<=m;++i) {
        if (sz==0 || qq[sz]<=q[i]) {
            qq[++sz]=q[i];
        } else {
            int l=1;
            int r=sz;
            while (l<r-1) {
                int mid=(l+r)>>1;
                if (qq[mid]>q[i]) r=mid;
                else l=mid;
            }
            if (qq[l]>q[i]) r=l;
            if (qq[r]>q[i]) qq[r]=q[i];
        }
        dp1[i]=sz;
    }
    sz=0;
    for (int i=m;i>0;--i) {
        if (sz==0 || qq[sz]<=q[i]) {
            qq[++sz]=q[i];
        } else {
            int l=1;
            int r=sz;
            while (l<r-1) {
                int mid=(l+r)>>1;
                if (qq[mid]>q[i]) r=mid;
                else l=mid;
            }
            if (qq[l]>q[i]) r=l;
            if (qq[r]>q[i]) qq[r]=q[i];
        }
        ans=max(ans,dp1[i-1]+sz);
    }
    ans=max(ans,dp1[m]);
    cout<<ans;
}