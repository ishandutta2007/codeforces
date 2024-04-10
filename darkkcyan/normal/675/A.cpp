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

ll a, b, c;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int i, f, g;  // count variable

    cin >> a >> b >> c;
    dev(a _ b _ c);

    if (c == 0) {
        if (a == b) cout << "YES";
        else cout << "NO";
        return 0;
    }
    else if ((b - a) % c == 0) {
        if (((b - a) >= 0 and c >= 0) or (((b - a) <= 0 and c <= 0))) cout << "YES";
        else cout << "NO";
    } else cout << "NO";


    return 0;
}