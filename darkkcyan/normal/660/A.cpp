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

tp<tn1> ve<t1>& op << (ve<t1>& v, const t1& elm) {
    v.push_back(elm);
    return v;
}

int d(int a, int b) {
    while (true) {
        a %= b;
        if (a == 0) return b;
        b %= a;
        if (b == 0) return a;
    }
}


int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int i, f, g;  // count variable

    int n;
    cin >> n;
    vi arr;

    int a;
    cin >> a;
    for (i = 0; i < n - 1; ++i) {
        int b;
        cin >> b;
        int t = d(a, b);
        arr << a;
        if (t > 1) arr << 1;
        a = b;
    }

    cin >> a;
    arr << a;

    cout << (arr.size() - n) << '\n';
    for (i = 0; i < arr.size(); ++i) {
        cout << arr[i] << ' ' ;
    }

    return 0;
}