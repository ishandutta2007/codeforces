// Created by calabash_boy on 18-10-18.
#pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
#ifdef __LOCAL_DEBUG__
# define _debug(fmt, ...) fprintf(stderr, "\033[91m[%s %3d]: " fmt "\n\033[0m", \
  __func__,__LINE__, ##__VA_ARGS__)
#else
# define _debug(...) (void(0))
#endif
#define PB(x) push_back(x)
#define rep(i,l,r) for (int i = l,_ = r;i< _;i++)
#define REP(i,l,r) for (int i=l,_=r;i<=_;i++)
#define leave(x) do {cout<<#x<<endl;fflush(stdout);return 0;}while (0);
#define untie do{ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);}while (0)
#define range(x) x.begin(),x.end()
typedef long long LL;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef long double db;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const int inf = 0x3f3f3f3f;
const ll inf_ll = 0x3f3f3f3f3f3f3f3fLL;
/************* header ******************/


set<ll > ans;
ll n;
ll calc(ll x){
    ll a1 = 1;
    ll an = (1 - x + n);
    ll ans = (a1 + an) * (1+(an - a1) / x)/ 2;
    //cerr<<a1<<" "<<an<<" "<<x<<endl;
    return ans;
}
int main(){
    cin >> n;
    ans.insert(1);
    for (ll k=1;k * k<=n;k++){
        if (n % k == 0){
            ans.insert(calc(k));
            if(n/k != k){
                ans.insert(calc(n/k));
            }
        }
    }
    for (ll x : ans){
        printf("%lld ",x);
    }
    puts("");
    return 0;
}