#pragma GCC target ("avx2,fma")
#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops")
#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MAXN=3001;
ll dp[MAXN],dp2[MAXN];

int main(){//this should not pass..
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,k;
    cin>>n>>k;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        vector<ll> arr;
        arr.resize(a+1);
        for(int j=1;j<sz(arr);j++){
            cin>>arr[j];
            arr[j]+=arr[j-1];
        }
        for(int j=0;j<=k;j++){
            ll te=0;
            const int maxl=min(j,sz(arr)-1);
            for(int l=0;l<=maxl;l++){
                te=max(te,dp2[j-l]+arr[l]);
            }
            dp[j]=te;
        }
        for(int j=0;j<=k;j++)dp2[j]=dp[j];
    }
    printf("%lli\n",dp[k]);
    return 0;
}