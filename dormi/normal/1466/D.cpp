#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=1e5+1;
int deg[MN];
ll arr[MN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        for(int i=1;i<=n;i++)deg[i]=0,cin>>arr[i];
        int a,b;
        priority_queue<ll> vals;
        for(int i=1;i<n;i++){
            cin>>a>>b;
            deg[a]++,deg[b]++;
        }
        ll ans=0;
        for(int i=1;i<=n;i++){
            ans+=arr[i];
            for(int j=2;j<=deg[i];j++)vals.push(arr[i]);
        }
        for(int i=1;i<=n-1;i++){
            printf("%lli ",ans);
            if(i!=n-1) {
                ans += vals.top();
                vals.pop();
            }
        }
        printf("\n");
    }
    return 0;
}