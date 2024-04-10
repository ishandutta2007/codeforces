#include <bits/stdc++.h>
using namespace std;
#define forn(i, n) for (long long i = 0; i < n; i++)
#define ld long double
#define MAXN 200100
#define MOD 1000000007
#define BIGINF 1000000000000000000

ld v;
ld zero;
ld two;
ld one;

ld func(ld c, ld m, ld p, ld e) {
    // cout << c << " " << m << " " << p << " " << e << endl;
    ld ans = p*e;
    // C = 0, M = 0
    if(c==zero&&m==zero) return ans;
    // C = 0, M != 0
    if(c==zero&&m>zero) {
        ld temp = func(zero, max(m-v, zero), p + m - max(m-v, zero), e + one);
        ans += m*temp;
        return ans;
    }
    if(m==zero&&c>zero) {
        ld temp = func(max(c-v, zero), zero, p + c - max(c-v, zero), e+one);
        ans += c*temp;
        return ans; 
    } 
    ld a1 = func(max(c-v, zero), m + (c - max(c-v, zero))/two, p + (c - max(c-v, zero))/two, e+one);
    a1 = a1*c;
    ld a2 = func(c + (m - max(m-v, zero))/two, max(m-v, zero) ,p + (m - max(m-v, zero))/two , e+one);
    a2 = a2*m;
    return ans+a1+a2;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(numeric_limits<long double>::max_digits10);
    zero = 0.000000001l;
    two = 2.0l;
    one = 1.0l;
    int t; cin >> t; while(t--)
{
    // Code goes here
    ld c, m, p;
    cin >> c >> m >> p >> v;
    ld e = 0; // e will increase each time function value is called.
    cout << func(c, m, p, e+one) << endl;
}
    return 0;
}