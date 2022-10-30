#include <bits/stdc++.h>
using namespace std;
int n,m;
int q[1000001];
int l,r,ll,rr;
int ans;
int a[1000001];

int main(){
    //fdasklfdsalk;fksaf
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    l=1;
    r=1;
    q[0]=0;
    for (int i=1;i<=n;++i){
        cin>>a[i];
        if (a[i]==1) {
            if (i-q[l-1]>ans) {
                ans=i-q[l-1];
                ll=q[l];
                rr=i;
            }
            continue;
        }
        ++r;
        q[r]=i;
        if (r-l+1>m) ++l;
        if (q[r]-q[l-1]>ans) {
            ans=i-q[l-1];
            ll=q[l];
            rr=i;
        }
    }
    if (m==0) {
        ans=0;
        int last=0;
        ll=0; rr=0;
        for (int i=1;i<=n;++i){
            if (a[i]==1) {
                ++last;
                ans=max(ans,last);
            } else last=0;
        }
    }
    cout<<ans<<'\n';
    for (int i=1;i<=n;++i)
        if (i>=ll && i<=rr) a[i]=1;
    for (int i=1;i<=n;++i)
        cout<<a[i]<<" ";
}