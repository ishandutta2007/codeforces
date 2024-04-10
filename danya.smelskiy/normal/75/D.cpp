#include <bits/stdc++.h>
using namespace std;

int n,m;
long long ans=-1e18;
long long maxpref[5005],maxsuff[5005],sum[5005],maxans[5005];
int l;
long long x;
long long a[5005];
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for (int i=1;i<=n;++i) {
        cin>>l;
        long long s=0;
        long long ss=0;
        maxpref[i]=-1e18;
        maxans[i]=-1e18;
        for (int j=1;j<=l;++j) {
            cin>>a[j];
            sum[i]+=a[j];
            s+=a[j];
            ss+=a[j];
            maxans[i]=max(maxans[i],ss);
            ss=max(0ll,ss);
            maxpref[i]=max(maxpref[i],s);
        }
        s=0;
        for (int j=l;j>0;--j) {
            s+=a[j];
            maxsuff[i]=max(maxsuff[i],s);
        }
    }
    long long last=0;
    for (int i=1;i<=m;++i) {
        cin>>x;
        ans=max(ans,maxans[x]);
        ans=max(ans,last+maxpref[x]);
        last=max(0ll,max(maxsuff[x],last+sum[x]));
    }
    cout<<ans;
}