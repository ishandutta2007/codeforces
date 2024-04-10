#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,unroll-loops")
/*#pragma comment(linker, "/stack:200000000")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma,tune=native")*/
/*#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,fma")*/
using namespace std;
using ll=long long int;
using ld=long double;
using pll=pair<ll,ll>;
using pii=pair<int,int>;
#define F first
#define S second
#define pb push_back
//#define mp make_pair
#define lc v<<1
#define rc v<<1|1
#define fast_io ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
const int N=1e5+10,LN=38,M=5e6,SQ=350,B=737,inf=1e9+10;
const ll INF=1e18;
const ld ep=1e-7;
const int MH=1000696969,MD=998244353,MOD=1000000007;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<pll, null_type,less<pll>, rb_tree_tag,tree_order_statistics_node_update>
ll pow(ll x, ll y, ll mod){
    ll ans=1;
    while (y != 0) {
        if (y & 1) ans=ans * x % mod;
        y >>= 1;
        x=x * x % mod;
    }
    return ans;
}
vector<ll> vec[35];
ll n,pr[100005],nx[100005],cl[100005],cr[100005],L[25][100005],R[25][100005],g[100005],alp[35],sl[25][100005],sr[25][100005],ans;
string str;
int main(){
    fast_io;
    cin >> str;
    n=str.size();
    for (int i=0; i<n; i++){
        vec[str[i]-'a'].push_back(i);
        cl[i]=cr[i]=i;
    }
    for (int c=0; c<26; c++){
        for (int i=0; i<vec[c].size(); i++){
            pr[vec[c][i]]=i ? vec[c][i-1] : 0;
            nx[vec[c][i]]=i+1 == vec[c].size() ? n-1 : vec[c][i+1];
        }
    }
    for (int lim=1; lim <= 26; lim++){
        multiset<int> msl,msr;
        for (int l=0,r=0,cur=0; l<n; l++){
            while (r<n && cur+!alp[str[r]-'a']<=lim){
                msl.insert(pr[r]);
                msr.insert(nx[r]);
                R[0][r]=*--msr.end();
                cur+=!alp[str[r++]-'a']++;
            }
            g[l]=r;
            L[0][l]=*msl.begin();
            sl[0][l]=l;
            sr[0][l]=n-l-1;
            cur-=!--alp[str[l]-'a'];
            msl.erase(msl.find(pr[l]));
            msr.erase(msr.find(nx[l]));
        }
        for (int i=1; i<20; i++){
            for (int j=0; j<n; j++){
                L[i][j]=L[i-1][L[i-1][j]];
                R[i][j]=R[i-1][R[i-1][j]];
                sl[i][j]=sl[i-1][j]+sl[i-1][L[i-1][j]];
                sr[i][j]=sr[i-1][j]+sr[i-1][R[i-1][j]];
            }
        }
        for (int i=0; i<n; i++){
            for (int j=19; j>=0; j--){
                if (R[j][cr[i]]<g[L[j][cl[i]]]){
                ans+=sr[j][cr[i]]+sl[j][cl[i]];
                cl[i]=L[j][cl[i]];
                cr[i]=R[j][cr[i]];
                }
            }
            if (cr[i]<g[cl[i]]){
                ans+=sr[0][cr[i]]+sl[0][cl[i]];
                cl[i]=L[0][cl[i]];
                cr[i]=R[0][cr[i]];
            }
        }
    }
    cout << ans << '\n';
    return 0;
}