#include <map>
#include <vector>
#include <deque>
#include <algorithm>
#include <bitset>
#include <cmath>
#include <string>
#include <iostream>
#include <set>
#include <iomanip>
#include <bitset>
#include <random>
#include <unordered_map>
#include <unordered_set>
#include <deque>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <map>

using namespace __gnu_pbds;
using namespace std;
#define pb push_back
#define ll long long
#define mp make_pair
#define fdeg firdeg
#define snd second
#define ld __float128
#define mt make_tuple
#define fst first
const int mod = static_cast<const int>(1e9 + 7);
const int maxN = static_cast<const int>(1e6 + 5);
unordered_map<string, int> hashMap;
tree<pair<ll,ll> ,null_type,less<pair<ll, ll> >,rb_tree_tag,tree_order_statistics_node_update> tr;
using namespace std;
const ll INF = 1e18;
int main()
{
    ll ans = 0;
    ll a = 0;
    ll sum = 0 , n , t;
    cin >> n >> t;
    for(ll i = 0; i < n; i++)
    {
        cin >> a;
        sum += a;
        ans += tr.size() - tr.order_of_key(mp(sum - t ,INF));
        tr.insert(mp(sum,i));
        if(sum < t) ans++;
    }
    cout << ans << "\n";
}