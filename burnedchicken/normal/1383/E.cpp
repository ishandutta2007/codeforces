#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define int long long
#define ull unsigned long long
#define ld long double
#define rep(a) rep1(i,a)
#define rep1(i,a) rep2(i,0,a)
#define rep2(i,b,a) for(int i=(b); i<((int)(a)); i++)
#define rep3(i,b,a) for(int i=(b); i>=((int)(a)); i--)
#define all(a) a.begin(),a.end()
#define pii pair<int,int>
#define pb push_back
#define mp make_pair
//#define inf 2000000000
#define inf 8000000000000000000
#define pi 3.14159265358979323846264338328
#define eps 1e-9
#define sz(a) ((int)a.size())
#define pow2(x) (1ll<<(x))
#define ceiling(a,b) (((a)+(b)-1)/(b))
#define print0(a) cout << (a) << ' '
#define print1(a) cout << (a) << '\n'
#define print2(a,b) cout << (a) << ' ',print1(b)
#define print3(a,b,c) cout << (a) << ' ',print2(b,c)
#define print4(a,b,c,d) cout << (a) << ' ',print3(b,c,d)
#define ykh mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#ifdef i_am_noob
#define debug(a) print2(#a,a)
#else
#define debug(a)
#endif
#define ordered_set tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>

using namespace std;
using namespace __gnu_pbds;

const int Mod=1000000007,Mod2=998244353;
const int MOD=Mod;

inline int add(int a, int b){return (a+b>=MOD?a+b-MOD:a+b);}
inline int sub(int a, int b){return (a+MOD-b>=MOD?a-b:a+MOD-b);}
int Pow(int a, int b){
	if(!b) return 1;
	int tmp=Pow(a*a%MOD,b>>1);
	return (b&1?tmp*a%MOD:tmp);
}
inline int inverse(int n){return Pow(n,MOD-2);}

const int maxn=105;
//i_am_noob
int t,n,a[maxn],k=0,l=0,x;
string str;
vector<int> cnt0,cnt1,dp0,dp1,vec;

signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin >> str;
    rep(sz(str)){
        if(str[i]=='0'){
            if(i==0||str[i-1]!=str[i]) cnt0.pb(1);
            else cnt0.back()++;
        }
        else{
            if(i==0||str[i-1]!=str[i]) cnt1.pb(1);
            else cnt1.back()++;
        }
    }
    if(str[0]=='0'){
        rep(10000000){
            if(i==sz(cnt0)) break;
            while(1){
                if(vec.empty()){
                    vec.pb(i);
                    k=add(k,cnt0[i]*(i?dp1[i-1]:0)%MOD);
                    break;
                }
                x=vec.back();
                if(cnt0[x]>=cnt0[i]){
                    k=sub(k,cnt0[i]*(x?dp1[x-1]:0)%MOD);
                    k=add(k,cnt0[i]*(i?dp1[i-1]:0)%MOD);
                    vec.pb(i);
                    break;
                }
                k=sub(k,cnt0[x]*(x?dp1[x-1]:0)%MOD);
                vec.pop_back();
                if(!vec.empty()) k=add(k,cnt0[x]*(vec.back()?dp1[vec.back()-1]:0)%MOD);
            }
            dp0.pb(add(k,cnt0[0]));
            if(i==sz(cnt1)) break;
            l=add(l,cnt1[i]*(1+dp0[i])%MOD);
            dp1.pb(l);
        }
    }
    else{
        rep(10000000){
            if(i==sz(cnt1)) break;
            l=add(l,cnt1[i]*(1+(i?dp0[i-1]:0))%MOD);
            dp1.pb(l);
            if(i==sz(cnt0)) break;
            while(1){
                if(vec.empty()){
                    vec.pb(i);
                    k=add(k,cnt0[i]*dp1[i]%MOD);
                    break;
                }
                x=vec.back();
                if(cnt0[x]>=cnt0[i]){
                    k=sub(k,cnt0[i]*dp1[x]%MOD);
                    k=add(k,cnt0[i]*dp1[i]%MOD);
                    vec.pb(i);
                    break;
                }
                k=sub(k,cnt0[x]*dp1[x]%MOD);
                vec.pop_back();
                if(!vec.empty()) k=add(k,cnt0[x]*dp1[vec.back()]%MOD);
            }
            dp0.pb(k);
        }
    }
    //for(auto i: dp0) print0(i);
    //cout << "\n";
    //for(auto i: dp1) print0(i);
    //cout << "\n";
    if(dp1.empty()) print1(sz(str));
    else if(str.back()=='0') print1((1+cnt0.back())*dp1.back()%MOD);
    else print1(dp1.back());
    return 0;
}