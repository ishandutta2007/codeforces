#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <ctime>
#include <unordered_set>
#include <string>
#include <map>
#include <unordered_map>
#include <random>
#include <set>
#include <cassert>
#include <functional>
#include <iomanip>
#include <queue>
#include <numeric>
#include <bitset>
#include <iterator>
#define double long double
#define ll long long
#define pb push_back
using namespace std;
const double PI = acos(-1);
const int N = 2e6 + 10;
int a[N] , b[N];
vector<ll> st;
void precalc()
{
    st.pb(0);
    for(ll i = 1; i <= 63; i++)
    {
        st.pb((1 << i) - 1) ;
    }
}
ll solve_small(ll l , ll r)
{
    ll x = 0;
    ll ans = 0;
    for(ll p = l; p <= r; p++)
    {
        if(ans < __builtin_popcount(p) )
        {
            ans =  __builtin_popcount(p);
            x = p;
        }
    }
    return x;
}
ll rec(ll l , ll r)
{
    int ans = 0;
    ll p = l;
    ll last = l;
    for(int i = 0; i <= 100 && p <= r; i++)
    {
        p += ~p&-~p;
        if(p <= r) last = p;
    }
    // cout << ans << "\n";
    return last;
}

int main()
{
    int n ;
    cin >>  n;
    precalc();
    //    for(auto i : st) cout << i << " ";
    //    cout << "\n";
    while (n--)
    {
        ll l , r;
        cin >> l >> r;
        //        if( r - l < 100)
        //        {
        //            cout << solve_small(l, r) << "\n";
        //            continue;
        //        }
        cout << rec(l, r) << "\n";
    }
    
}