#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define forn(i, a, n) for (int i = a; i < n; i++)

const int MAXN = 200100;
const int MOD = 1000000007;
const int INF = 9100000000000000000;
const double EPS = 1E-7;

vector <int> v;
vector <int> w;
map <int, int> p;

void pre() {
    set <int> f;
    int ft = 1;
    for(int i = 1; i < 20; i++) {
        ft *= i;
        if(ft > (int)1E12) break;
        v.push_back(ft);
    }
    for(auto i : f) v.push_back(i);
    // for(auto i : v) cout << i << " ";
    // cout << v.size() << endl;
    int n = v.size();
    for(int i = 0; i < (1<<n); i++) {
        int x = i;
        int bits = 0;
        int sum = 0;
        for(int j = 0; j < n; j++) {
            if(x % 2 == 1) {
                bits++;
                sum += v[j];
            }
            x /= 2;
        }
        if(p.find(sum) == p.end()) {
            p[sum] = bits;
        } else {
            p[sum] = min(p[sum], bits);
        }
    }
    // for(auto i : p) {
    //     if(i.first > 100) continue;
    //     cout << i.first << " " << i.second << endl;
    // }
}

void solve() {
    int n;
    cin >> n;
    int ans = __builtin_popcountll(n);
    for(auto i : p) {
        if(i.first > n) break;
        int temp = i.second;
        int z = n - i.first;
        temp += __builtin_popcountll(z);
        if(z % 2 == 1 && p.find(i.first - 1) != p.end() && p[i.first - 1] == i.second - 1) continue;
        if((z / 2) % 2 == 1 && p.find(i.first - 2) != p.end() && p[i.first - 2] == i.second - 1) continue;
        ans = min(ans, temp);
    }
    cout << ans << endl;
}

int32_t main() {

    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int T = 1;
    cin >> T;
    pre();
    for(int I = 1; I <= T; I++) {
        // cout << "Case #" << I << ": ";
        solve(); 
    }

    return 0;
}