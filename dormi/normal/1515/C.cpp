#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        int n,m;
        ll x;
        cin>>n>>m>>x;
        set<pair<ll,int>> smallest;
        for(int i=0;i<m;i++)smallest.insert({0,i+1});
        ll a;
        printf("YES\n");
        for(int i=0;i<n;i++){
            cin>>a;
            pair<ll,int> val=*smallest.begin();
            smallest.erase(smallest.begin());
            smallest.insert({val.first+a,val.second});
            printf("%d%c",val.second," \n"[i==n-1]);
        }
    }
    return 0;
}