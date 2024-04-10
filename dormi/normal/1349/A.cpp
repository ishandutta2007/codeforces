#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    map<ll,vector<ll>> pfs;
    ll a;
    for(int i=0;i<n;i++){
        cin>>a;
        for(ll j=2;j*j<=a;j++){
            ll am=1;
            while(a%j==0){
                am*=j;
                a/=j;
            }
            if(am>1)pfs[j].push_back(am);
        }
        if(a>1)pfs[a].push_back(a);
    }
    ll ans=1;
    for(auto x:pfs){
        sort(pfs[x.first].begin(),pfs[x.first].end());
        if(sz(pfs[x.first])==n-1){
            ans*=pfs[x.first][0];
        }
        else if(sz(pfs[x.first])==n){
            ans*=pfs[x.first][1];
        }
    }
    printf("%lli\n",ans);
    return 0;
}