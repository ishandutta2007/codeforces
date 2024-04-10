#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mp make_pair
#define pb push_back
#define pii pair <int, int>
#define vi vector<int>

#define FOR(i, a, b) for (int i=a; i<b; i++)
#define F0R(i, a) for (int i=0; i<a; i++)

#define f first
#define s second

const int MOD = 1000000007;
const int MAX = 10000005;

int main() {
    ll c,d, ans=0;
    cin >> c >> d;
    for (ll a = 0; a <= 63; ++a) {
        for (ll b = 0; b <= a-2; ++b) {
        	ll x1 = pow(2,a)-pow(2,b)-1;
            if (x1 >= c && x1 <= d) {
                ans++;
            }
        }
    }
 
    cout << ans;
}