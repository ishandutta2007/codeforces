#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=1e5+1;
const ll MV=1e18+1;
ll arr[MN];
bool work;
vector<int> res;
void solve(ll n, ll k, int offset){
    if(n==0)return;
    for(ll i=n-1;i>=0;i--){
        if(arr[i]>=k){
            for(ll j=n-i;j>=1;j--){
                res.push_back(j+offset);
            }
            solve(n-(n-i),k,offset+(n-i));
            return;
        }
        k-=arr[i];
    }
    work=false;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    arr[1]=arr[0]=1;
    for(int i=2;i<=1e5;i++){
        arr[i]=arr[i-1]*2;
        arr[i]=min(arr[i],MV);
    }
    while(t--){
        ll n,k;
        cin>>n>>k;
        res=vector<int>();
        work=true;
        solve(n,k,0);
        if(!work)printf("-1\n");
        else{
            for(auto x:res)printf("%d ",x);
            printf("\n");
        }
    }
    return 0;
}