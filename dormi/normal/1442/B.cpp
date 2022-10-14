#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MAXN=2e5+1;
const ll mod =998244353;
vector<int> bad[MAXN];
int arr[MAXN];
int arr2[MAXN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        for(int i=0;i<n;i++){
            cin>>arr[i];
            bad[i+1]=vector<int>();
        }
        for(int i=0;i<n;i++){
            if(i-1>=0)bad[arr[i]].push_back(arr[i-1]);
            if(i+1<n)bad[arr[i]].push_back(arr[i+1]);
        }
        set<int> cnt;
        for(int i=0;i<k;i++){
            cin>>arr2[i];
            cnt.insert(arr2[i]);
        }
        ll ans=1;
        for(int i=0;i<k;i++){
            ll te=0;
            cnt.erase(arr2[i]);
            for(auto x:bad[arr2[i]]){
                if(!cnt.count(x))te++;
            }
            ans=ans*te%mod;
        }
        printf("%lli\n",ans);
    }
    return 0;
}