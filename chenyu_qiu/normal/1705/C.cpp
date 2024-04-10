#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define fast ios_base::sync_with_stdio(0);cout.tie(nullptr);cin.tie(nullptr);cout << fixed << setprecision(6);
#define done cout<<"Successful\n";
#define stop getchar();
#define input(gggg,n) for(int xd=0;xd<n;xd++)cin>>gggg[xd];
#define output(gggg) for(auto x: gggg){cout<<x<<sp;}
#define print(x) cout<< #x <<" = "<< x<<"\n";
#define nl "\n"
#define sp " "
 
string s;
ll n,c,q;
vector<pair<ll,ll>> operation, segment;
 
char query(ll id){
    if(id>=1 && id<=n){
        return s[id];
    }
    for(ll i=0; i<c; i++){
        if(id>=segment[i].first && id<=segment[i].second){
            return query(operation[i].first+(id-segment[i].first));
        }
    }
}
 
void solve(){
    cin>>n>>c>>q;
    cin>>s;
    s = " "+s;
    operation.resize(c);
    segment.resize(c);
    ll last = n;
    for(ll i=0; i<c; i++){
        cin>>operation[i].first>>operation[i].second;
        segment[i].first = last+1;
        segment[i].second = last+operation[i].second-operation[i].first+1;
        last = segment[i].second;
    }
    while(q--){
        ll k;
        cin>>k;
        cout<<query(k)<<nl;
    }
}
int main(){
    fast;
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}