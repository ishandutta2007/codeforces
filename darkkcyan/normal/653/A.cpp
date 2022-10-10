#include <bits/stdc++.h>
using namespace std;

#ifdef db 
#define de(msg) cerr << "line " << __LINE__ << " => " << msg << '\n'
#else
#define de(msg)
#endif
#define dev(var) de(#var << ' ' << var)
#define _ << ' ' <<

#define fi first
#define se second
#define be begin()
#define en end()
#define mp make_pair
#define ll l l

#define pii pair<int, int>
#define pilll pair<int, ll>
#define pllll pair<ll, ll>

#define ve vector
#define vv(t) ve<ve<t > >
#define vi ve<int>
#define vll ve<ll>

#define all(v) (v).be, (v).en
#define ap(a, b, p) {a = (p).fi; b = (p).se;}

#define tp template
#define tn1 typename t1
#define op operator

tp<tn1> ve<t1>& op << (ve<t1>& v, t1& elm) {
    v.push_back(elm);
    return v;
}


int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int i, f, g;  // count variable

    bitset<1000 + 10> bset;

    int n;
    cin >> n;
    for (i = 0; i < n; ++i) {
        int a;
        cin >> a;
        bset.set(a);
    }

    bool haveSol = false;
    for (i = 2; i <= 1000; ++i) {
        if (bset[i] and bset[i - 1] and bset[i - 2]) {
            haveSol = true;
            break;
        }
    }

    cout << (haveSol ? "YES" : "NO");
    return 0;
}