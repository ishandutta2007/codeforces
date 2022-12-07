#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define forn(i, a, n) for (int i = a; i < n; i++)

const int MAXN = 200100;
const int MOD = 1000000007;
const int INF = 9100000000000000000;
const double EPS = 1E-7;

int n, t1, t2, t3;

struct Dish {
    int x, y, m, id;
};
Dish temp;

int var = 0; // variety
map<int, vector<vector<int>>> m; // m[sum] = {id, x_min, x_max}
map<int, int> p; // m[id] = x_needed
vector <Dish> v; // stores dishes by their id

void solve() {
    cin >> n;
    m.clear();
    var = 0;
    p.clear();
    v.clear();
    forn(i, 0, n) {
        cin >> temp.x >> temp.y >> temp.m;
        temp.id = i;
        v.push_back(temp);
        int xmin = max(temp.x - temp.m, 0ll);
        int xmax = temp.x + temp.y - temp.m - max(temp.y - temp.m, 0ll);
        m[temp.x + temp.y - temp.m].push_back({i, xmin, xmax});
    }
    for(auto j : m) {
        vector <vector<int>> v = j.second;
        sort(v.begin(), v.end(), [&](vector<int> A, vector<int> B) {
            return A[2] < B[2];
        });
        int temp = 0;
        p[v[temp][0]] = v[temp][2];
        int n = v.size();
        var++;
        forn(i, 1, n) {
            if(v[i][1] > v[temp][2]) {
                var++;
                temp = i;
                p[v[temp][0]] = v[temp][2];
            }
            else {
                p[v[i][0]] = v[temp][2];
            }
        }
    }
    cout << var << endl;
    for(auto i : v) {
        // p[i.id] --> x_needed
        int first = i.x - p[i.id];
        int second = i.m - first;
        cout << first << " " << second << endl;
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