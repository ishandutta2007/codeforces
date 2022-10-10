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
#define ll long long 

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
    int h1, h2;
    int a, b;

    cin >> h1 >> h2
        >> a >> b
    ;

    dev(h1 _ h2 _ a _ b);


    ll result = 0;

    while (true) {
        h1 += a * 8;
        if (h1 >= h2) break;
        if (a <= b) return cout << "-1", 0;
        h1 -= b * 12;
        h1 += a * 4;
        ++result;
    }

    cout << result;

    return 0;
}