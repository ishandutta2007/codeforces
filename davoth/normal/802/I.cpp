#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
#define F first
#define S second
#define fast_io ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
const int N=2e5+10,LN=20,SQ=550,M=1e9+10;
const ll INF=1e16;
const int MOD=1000000007 /*998244353*/;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using pll=pair<ll,ll>;
using pii=pair<int,int>;
#define ordered_set tree<pair<pll,ll>, null_type,less<pair<pll,ll>>, rb_tree_tag,tree_order_statistics_node_update>
ll pow(ll x, ll y, ll mod){
    ll ans=1;
    while (y != 0) {
        if (y & 1) ans = ans * x % mod;
        y >>= 1;
        x = x * x % mod;
    }
    return ans;
}
ll n,Rank[N][LN],pw,P[N],t,L[N],R[N],ans;
string S;
stack<pll> st;
bool cmp(int x, int y){
    if(Rank[x][pw-1]!=Rank[y][pw-1]) return Rank[x][pw-1]<Rank[y][pw-1];
    if(max(x, y)+(1<<(pw-1))>n) return x>y;
    return Rank[x+(1<<(pw-1))][pw-1]<Rank[y+(1<<(pw-1))][pw-1];
}
void BuildSuffixArray(){
    for(int i=1; i<=n; i++) Rank[i][0]=S[i-1], P[i]=i;
    for(pw=1; pw<LN; pw++){
        sort(P+1, P+n+1, cmp);
        Rank[P[1]][pw]=1;
        for (int i=2; i<=n; i++) Rank[P[i]][pw]=Rank[P[i-1]][pw] + cmp(P[i-1], P[i]);
    }
}
ll LCP(int x, int y){
    int res=0;
    for(int i=LN-1; i>=0; i--) if(Rank[x][i]==Rank[y][i] && max(x,y)-1<=n){
        x+=(1<<i);
        y+=(1<<i);
        res|=(1<<i);
    }
    return res;
}
int main(){
    fast_io;
    cin >> t;
    while(t--){
        cin >> S;
        n=S.size();
        ans=0;
        memset(Rank,0,sizeof Rank);
        BuildSuffixArray();
        while(!st.empty()) st.pop();
        for(ll i=1; i<n; i++){
            ll x=LCP(P[i],P[i+1]);
            while(!st.empty() && st.top().F>x) st.pop();
            L[i]=(st.empty() ? 0 : st.top().S);
            st.push({x,i});
        }
        while(!st.empty()) st.pop();
        for(ll i=n-1; i>=1; i--){
            ll x=LCP(P[i],P[i+1]);
            while(!st.empty() && st.top().F>=x) st.pop();
            R[i]=(st.empty() ? n : st.top().S);
            ans+=2*(R[i]-i)*(i-L[i])*x;
            st.push({x,i});
        }
        cout << ans+n*(n+1)/2 << '\n';
    }
    return 0;
}