#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const ll mod=998244353;
const int MN=2e5+1;
ll arr[MN];
ll psaoff[MN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        ll sum=0;
        for(int i=0;i<n;i++){
            cin>>arr[i];
            sum+=arr[i];
            psaoff[i]=arr[i]+(i-2>=0?psaoff[i-2]:0);
        }
        ll atmost=(sum-1)/2;
        ll ans=1;
        ll cur=0;
        for(int i=1;i<n;i++){
            cur+=arr[i-1];
            if(cur<=atmost){
                int lo=0,hi=(n-i-1)/2;
                while(lo!=hi){
                    int mid=(lo+hi+1)/2;
                    if(psaoff[i-1+mid*2]-psaoff[i-1]+cur<=atmost)lo=mid;
                    else hi=mid-1;
                }
                ans=(ans+(lo+1))%mod;
                if(cur+arr[n-1]<=atmost) {
                    lo = 0, hi = max(0,(n - i - 2) / 2);
                    while (lo != hi) {
                        int mid = (lo + hi + 1) / 2;
                        if (psaoff[i - 1 + mid * 2] - psaoff[i - 1] + cur + arr[n - 1] <= atmost)lo = mid;
                        else hi = mid - 1;
                    }
                    ans = (ans + (lo + 1)) % mod;
                }
            }
        }
        cur = 0;
        for (int i = 2; i < n; i++) {
            cur += arr[i - 1];
            if (cur <= atmost) {
                int lo=0,hi=(n-i-1)/2;
                while(lo!=hi){
                    int mid=(lo+hi+1)/2;
                    if(psaoff[i-1+mid*2]-psaoff[i-1]+cur<=atmost)lo=mid;
                    else hi=mid-1;
                }
                ans=(ans+(lo+1))%mod;
                if(cur+arr[n-1]<=atmost&&n-1-(i-1)>1) {
                    lo = 0, hi = max(0,(n - i - 2) / 2);
                    while (lo != hi) {
                        int mid = (lo + hi + 1) / 2;
                        if (psaoff[i - 1 + mid * 2] - psaoff[i - 1] + cur + arr[n - 1] <= atmost)lo = mid;
                        else hi = mid - 1;
                    }
                    ans = (ans + (lo + 1)) % mod;
                }
            }
        }
        cur=0;
        for(int i=n-1;i>=0;i--){
            cur+=arr[i];
            if(cur<=atmost){
                ans++;
                ans%=mod;
            }
        }
        printf("%lli\n",ans);
    }
    return 0;
}