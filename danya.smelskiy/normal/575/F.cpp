#include <bits/stdc++.h>
using namespace std;
long long n,x;
vector<long long> v;
long long l[20005];
long long r[20005];
long long dp1[20005];
long long dp2[20005];
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>x;
    for (int i=1;i<=n;++i) {
        cin>>l[i]>>r[i];
        v.push_back(l[i]);
        v.push_back(r[i]);
    }
    v.push_back(x);
    sort(v.begin(),v.end());
    for (int i=0;i<v.size();++i) {
        dp1[i]=abs(x-v[i]);
    }
    for (int i=1;i<=n;++i) {
        long long ll=l[i];
        long long rr=r[i];
        for (int j=0;j<v.size();++j){
            dp2[j]=dp1[j];
            if (v[j]<ll) dp2[j]+=ll-v[j];
            else if (v[j]>rr) dp2[j]+=v[j]-rr;
        }
        for (int j=0;j<v.size()-1;++j)
            if (v[j]<ll && dp2[j]<dp2[j+1]) dp2[j+1]=dp2[j];
        for (int j=v.size()-1;j>0;--j)
            if (v[j]>rr && dp2[j]<dp2[j-1]) dp2[j-1]=dp2[j];
        for (int j=0;j<v.size();++j)
            dp1[j]=dp2[j];
    }
    long long ans=1e18;
    for (int i=0;i<v.size();++i)
        ans=min(ans,dp1[i]);
    cout<<ans;
}