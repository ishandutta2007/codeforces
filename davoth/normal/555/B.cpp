#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define F first
#define S second
#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
const int N=2e5+10;
ll L[N],R[N],A[N],ans[N];
set<pair<ll,ll> > ss;
set<pair<pair<ll,ll>,ll> > st;
int main() {
    fast_io;
    int n,m;
    cin >> n >> m;
    for(int i=0; i<n; i++) cin >> L[i] >> R[i];
    for(int i=0; i<m; i++) cin >> A[i],ss.insert({A[i],i});
    for(int i=0; i<n-1; i++) st.insert({{R[i+1]-L[i],L[i+1]-R[i]},i});
    for(auto p : st){
        auto i = ss.lower_bound({p.F.S,-1});
        if(i==ss.end() || i->first>p.F.F) return cout<<"No",0;
        ans[p.S]=i->S+1;
        ss.erase(*i);
    }
    cout << "Yes\n";
    for(int i=0; i<n-1; i++) cout << ans[i] << ' ';
    return 0;
}