//
// Created by calabash_boy on 18-10-18.
//
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
ll a,b;
vector<ll> ansa,ansb;
bool check(ll n){
    ansa.clear();
    ansb.clear();
    ll sum = a+b;
    ll tot = n * (n+1)/2;
    if (tot >sum)return false;
    ll B = b;
    ll A = a;
    for (ll i=n;i>=1;i--){
        if (A > B){
            if (A>= i){
                A -= i;
                ansa.push_back(i);
            }else{
                if (B>=i){
                    ansb.push_back(i);
                }else{
                    return false;
                }
            }
        }else{
            if (B>=i){
                B-= i;
                ansb.push_back(i);
            }else{
                if (A>=i){
                    ansa.push_back(i);
                }else{
                    return false;
                }
            }
        }
    }
    return true;
}

int main(){
    cin>>a>>b;
    ll l = 0,r = a+b;
    while (r-l>1){
        ll mid = r+l >>1;
        if(check(mid)){
            l = mid;
        }else{
            r = mid;
        }
    }
    if (!check(r))check(l);
    cout<<ansa.size()<<endl;
    for (auto x: ansa){
        cout<<x<<" ";
    }
    cout<<endl;
    cout<<ansb.size()<<endl;
    for (auto y : ansb){
        cout<<y<<" ";
    }
    cout<<endl;
    return 0;
}