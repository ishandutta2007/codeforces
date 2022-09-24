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
int main()
{
    int n ;
    cin >>  n;
    precalc();
  //  for(auto i : st) cout << i << " ";
  //  cout << "\n";
//    for(int i = 0; i < n; i++)
//    {
//        ll l , r;
//        cin >> l >> r;
//        if(r - l < 100)
//        {
//            ll x = 0;
//            ll ans = 0;
//            for(ll p = l; p <= r; p++)
//            {
//                if(ans < __builtin_popcount(p) )
//                {
//                    ans =  __builtin_popcount(p);
//                    x = p;
//                }
//            }
//            cout << x << "\n";
//            continue;
//        }
//        int x = upper_bound(st.begin(), st.end(), l) - st.begin() - 1;
//        int y = upper_bound(st.begin(), st.end(), r) - st.begin() - 1;
//        //cout << st[x] << " " << st[y] << "\n";
//
//       // if(
//    }
    int mx = -1;
    int ans = 0;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        mx = max(mx , a[i]);
        b[a[i]] = 1;
        a[i] = 0;
    }
    int cnt = 0;
    for(int i = 0; i < N; i++)
    {
        if(b[i])
        {
            a[cnt] = i;
            cnt++;
        }
    }
    n = cnt;
    vector<int> pref = {0};
    int x = 1;
    for(int i = 1; i < N; i++ , x++)
    {
        if(b[i])
        {
            pref.pb(i);
        }
        else
        {
            pref.pb(pref.back());
        }
    }
//    for(int i = 0; i < pref.size(); i++)
//    {
//        cout << pref[i] << " ";
//    }
    for(int i = 1; 2 * i < N; i++)
    {
        if(b[i])
        {
            for(int j = 2 * i; j < N; j+= i)
            {
                j--;
                ans = max(ans , pref[j] % i);
                j++;
            }
        }
    }
    cout << ans << "\n";
}