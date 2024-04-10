#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define forn(i, a, n) for (int i = a; i < n; i++)

const int MAXN = 200100;
const int MOD = 1000000007;
const int INF = 9100000000000000000;
const double EPS = 1E-7;

int n, m;
struct Dish {
    int a, b, id, x, y;
    pair<int, int> range;
};
vector <Dish> v;
int bal = 0;
int ans;
pair<int, int> pos;

void solve() {
    cin >> n >> m;
    v.clear();
    pos = {0, 0};
    bal = 0;
    forn(i, 0, n) {
        int t1, t2;
        cin >> t1 >> t2;
        bal += (t1 - t2);
        t1 = min(t1, m);
        t2 = min(t2, m);
        Dish temp;
        temp.a = t1; temp.b = t2; temp.id = i;
        temp.range.first = -temp.a + (m - temp.a);
        temp.range.second = temp.b - (m - temp.b);
        pos.first += temp.range.first;
        pos.second += temp.range.second;
        v.push_back(temp);
    }
    // We have our initial balance, and the range of "change" we can make is pos. 
    // We can make intermediate values of pos with jumps of 2.
    // Minimise the sum of balance + an intermediate value of pos. (absolute value) 
    // 3 cases.
    pos = {bal + pos.first, bal + pos.second};
    // cout << pos.first << " " << pos.second << endl;
    if(pos.first >= -1) {
        ans = abs(pos.first);
        forn(i, 0, n) {
            v[i].x = v[i].a;
            v[i].y = m - v[i].a;
        }
    }
    else if(pos.second <= 1) {
        ans = abs(pos.second);
        forn(i, 0, n) {
            v[i].x = m - v[i].b;
            v[i].y = v[i].b;
        }
    }
    else {
        // Find value closest to zero between pos.first and pos.second, with jumps of 2.
        int add = 0; // i.e. answer to be achieved is pos.first + (add * 2)
        if(pos.first % 2 == 0) {
            ans = 0;
        }
        else {
            ans = 1;
        }
        add = abs(pos.first)/2;
        forn(i, 0, n) {
            if(v[i].range.first + add * 2 >= v[i].range.second) {
                v[i].x = m - v[i].b;
                v[i].y = v[i].b;
                add -= (v[i].range.second - v[i].range.first)/2;
            }
            else if(add == 0) {
                v[i].x = v[i].a;
                v[i].y = m - v[i].a;
            }
            else {
                v[i].x = v[i].a - add;
                v[i].y = m - (v[i].a - add);
                add = 0;
            }
        }
    }
    cout << ans << endl;
    forn(i, 0, n) {
        cout << v[i].x << " " << v[i].y << endl;
    }
}

int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    
    int T = 1;
    cin >> T;
    for(int I = 1; I <= T; I++) {
        // cout << "Case #" << I << ": ";
        solve(); 
    }

    return 0;
}