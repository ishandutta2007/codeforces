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

int n, m, k;
list<int> items;


int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int i, f, g;  // count variable

    cin >> n >> m >> k;
    for (i = 0; i < k; ++i) {
        int a;
        cin >> a;
        items.pub(a);
    }

    list<int>::iterator it;

    ll result = 0;
    for (i = 0; i < n; ++i) {
        for (f = 0; f < m; ++f) {
            int num;
            cin >> num;
            g = 0;
            for (it = items.begin(); it != items.end(); ++it, ++g) {
                if (*it != num) continue;
                items.erase(it);
                items.puf(num);
                break;
            }
            dev(g);
            result += g + 1;
        }
    }

    cout << result;
    return 0;
}