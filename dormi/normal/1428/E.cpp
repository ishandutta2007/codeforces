#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MAXN=1e5+1;
ll arr[MAXN];
ll optimal(ll am, ll rabbits){
    if(rabbits==0){
        if(am>0)return 1e18;
        return 0;
    }
    if(am<rabbits)return 1e18;
    ll norm=am/rabbits;
    return (norm+1)*(norm+1)*(am%rabbits)+norm*norm*(rabbits-(am%rabbits));
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    ll k;
    cin>>n>>k;
    ll ans=0;
    priority_queue<pair<ll,pii>> q;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        ans+=arr[i]*arr[i];
        q.push({optimal(arr[i],1)-optimal(arr[i],2),{i,2}});
    }
    for(int i=0;i<k-n;i++){
        auto cur=q.top();
        q.pop();
        ans-=cur.first;
        q.push({optimal(arr[cur.second.first],cur.second.second)-optimal(arr[cur.second.first],cur.second.second+1),{cur.second.first,cur.second.second+1}});
    }
    printf("%lli\n",ans);
    return 0;
}