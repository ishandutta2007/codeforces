#include <bits/stdc++.h>
/*#pragma GCC optimize("Ofast,unroll-loops")
#pragma comment(linker, "/stack:200000000")
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
#define mp make_pair
#define lc v<<1
#define rc v<<1|1
#define fast_io ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
const int N=1e5+10,LN=20,M=1e6+10,SQ=350,B=737,inf=1e9;
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
        if (y & 1) ans = ans * x % mod;
        y >>= 1;
        x = x * x % mod;
    }
    return ans;
}
int n,q,b[SQ][N],c,t[N],ls;
vector<int> a[SQ];
int main(){
    fast_io;
    cin >> n;
    for(int i=0; i<n; i++){
        int x;
        cin >> x;
        a[i/SQ].pb(x);
        b[i/SQ][x]++;
    }
    cin >> q;
    for(int i=0; i<q; i++){
        if(i==SQ){
            q-=SQ;
            c=i=0;
            for(int j=0; j<SQ; j++){
                for(int x : a[j]){
                    t[c++]=x;
                    b[j][x]--;
                }
                a[j]={};
            }
            for(int j=0; j<n; j++){
                a[j/SQ].pb(t[j]);
                b[j/SQ][t[j]]++;
            }
        }
        int w,l,r;
        cin >> w >> l >> r;
        l=(l+ls-1)%n+1;
        r=(r+ls-1)%n+1;
        if(l>r) swap(l,r);
        if(w==1){
            int k=0,f=0,x=0,y=0,g;
            while(x+a[k].size()<l){
                x+=a[k].size();
                k++;
            }
            f=k;
            y=x;
            while(y+a[f].size()<r){
                y+=a[f].size();
                f++;
            }
            g=a[f][r-y-1];
            b[f][g]--;
            b[k][g]++;
            a[f].erase(a[f].begin()+r-y-1);
            a[k].insert(a[k].begin()+l-x-1,g);
        }else{
            int k,f=0,g,x=0,y;
            cin >> k;
            k=(k+ls-1)%n+1;
            while(x+a[f].size()<l){
                x+=a[f].size();
                f++;
            }
            g=f;
            y=x;
            while(y+a[g].size()<r){
                y+=a[g].size();
                g++;
            }
            ls=0;
            if(f==g){
                for(int j=l-x-1; j<r-x; j++) if(a[f][j]==k) ls++;
            }else{
                for(int j=l-x-1; j<a[f].size(); j++) if(a[f][j]==k) ls++;
                for(int j=0; j<r-y; j++) if(a[g][j]==k) ls++;
                for(int j=f+1; j<g; j++) ls+=b[j][k];
            }
            cout << ls << '\n';
        }
    }
    return 0;
}