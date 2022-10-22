#include <bits/stdc++.h>
/*#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")*/
#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,fma")
using namespace std;
using ll = long long int;
#define F first
#define S second
#define pb push_back
#define lc v<<1
#define rc v<<1|1
#define fast_io ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
const int N=3e3+10,LN=20,M=5e1+1,SQ=600,inf=1e9;
const ll INF=1e18;
const int MH=1000696969,MOD=1000000007 /*998244353*/;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using pll=pair<ll,ll>;
using pii=pair<int,int>;
#define ordered_set tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update>
ll pow(ll x, ll y, ll mod){
    ll ans=1;
    while (y != 0) {
        if (y & 1) ans = ans * x % mod;
        y >>= 1;
        x = x * x % mod;
    }
    return ans;
}
ll t,n;
string s;
int main(){
    fast_io;
    cin >> t;
    while(t--){
        cin >> n >> s;
        ll x=0,y=0,z=0,w=0;
        string a="",b="";
        for(char c : s){
            if(c=='0') y++;
            else x++;
        }
        bool f=1;
        if(x%2){
            cout << "NO\n";
            continue;
        }
        x/=2;
        for(char c : s){
            if(c=='1'){
                if(x>0){
                    a+='(';
                    b+='(';
                    z++;
                    w++;
                }else{
                    a+=')';
                    b+=')';
                    z--;
                    w--;
                    if(w<0 || z<0) f=0;
                }
                x--;
            }else{
                if(y%2){
                    a+='(';
                    b+=')';
                    z++;
                    w--;
                    if(w<0) f=0;
                }else{
                    a+=')';
                    b+='(';
                    z--;
                    w++;
                    if(z<0) f=0;
                }
                y--;
            }
        }
        if(!f) cout << "NO\n";
        else cout << "YES\n" << a << '\n' << b << '\n';
    }
    return 0;
}