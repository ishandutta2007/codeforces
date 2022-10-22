#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define fi first
#define se second
#define ld long double
#define pb push_back
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
vector<int>p ;
void solve(){
    int N;
    cin>>N;
    int ans=0;
    for(int i=p.size()-1;i>=0;i--){
        while(N>=p[i]){
            ans++;
            N-=p[i];
        }
    }
    if(N==0)cout<<ans<<'\n';
    else cout<<-1<<'\n';
}
signed main() {
	ios::sync_with_stdio(false);cin.tie(0);
    p.pb(2050);for(int i=0;i<30;i++){
        p.pb(p.back()*10);
        if(p.back()>1e18)break;
    }
    int T=1;
    cin>>T;
    while(T--)solve();
}