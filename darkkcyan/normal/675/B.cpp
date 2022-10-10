#include <bits/stdc++.h>

using namespace std;

#ifdef db 
#define de(msg) cerr << "line " << __LINE__ << " => " << msg << '\n'
#else
#define de(msg)
#define at operator[]
#endif

#define dev(var) de(#var << ' ' << var)
#define _ << ' ' <<

#define fi first
#define se second
#define mp make_pair
#define ll long long 
#define pub push_back
#define puf push_front
#define pob pop_back
#define pof pop_front

#define pii pair<int, int>
#define pilll pair<int, ll>
#define pllll pair<ll, ll>

#define ve vector
#define vi ve<int>
#define vll ve<ll>

#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define ap(a, b, p) {a = (p).fi; b = (p).se;}

ll n, a, b, c, d;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int i, f, g;  // count variable

    cin >> n >> a >> b >> c >> d;

    ll ans = 0;
    for (f = 1; f <= n; ++f) {
        ll s = a + b + f;
        ll x = s - b - d;
        ll y = s - c - d;
        ll z = s - a - c;
        if (x <= 0 or y <= 0 or z <= 0 or x > n or y > n or z > n) continue;
        ++ans;
    }

    cout << ans * n;

    return 0;
}