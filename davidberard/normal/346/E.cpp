#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pii;

/**
 * If the problem has a*n < p, then it's easy to calculate:
 *   max(a, p-a*n) is the largest gap.
 * Otherwise you can split the problem into subproblems:
 *  - Note that [0, a) is the same as [k*a, (k+1)*a), except for maybe one number
 *    which occurs in [0, a) and not in [k*a, (k+1)*a).
 *  - There's also the case [floor(p/a)*a, p). However, this segment will
 *    never have a larger gap than [(floor(p/a)-1)*a, floor(p/a)*a); suppose there
 *    is some missing number q in [floor(p/a)*a, p). Then r = (q+a)%p is the next
 *    number in the sequence, r = q+a-p, or p-q = a-r.  So if level q doesn't exist,
 *    level r also doesn't exist. So if gap is [f..g) in [floor(p/a)*a, p), then
 *    gap [(a+f-p)..(a+g-p)) will also occur in previous segments.
 *  - So, solve for the segment [(floor(p/a)-1)*a, floor(p/a)*a).
 *  - In order to make it logn, if a*2 > p, then solve a' = p-a, p' = p, n' = n.
 */
bool solve(ll a, ll p, ll n, ll h) {
    a = a%p;
    if (n*a < p) {
        return max(a, p-n*a) <= h;
    }
    if (a*2 > p) {
        return solve(p-a, p, n, h);
    }
    ll bar = (p/a-1)*a;
    ll q = a*n%p;
    ll nprime = q > bar ? a*n/p : (a*n)/p-1;
    ll aprime = (a-1)*p%a;
    return solve(aprime, a, nprime, h);
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int TT;
    cin >> TT;
    while (TT--) {
        ll a, p, n, h;
        cin >> a >> n >> p >> h;
        a = a%p;
        if (h >= a) {
            cout << "YES\n";
        } else {
            cout << (solve(a, p, n, h) ? "YES" : "NO") << "\n";
        }
    }
    
    return 0;
}