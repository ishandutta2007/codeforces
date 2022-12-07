#include <bits/stdc++.h>
using namespace std;
#define int long long
#define forn(i, a, n) for (int i = a; i < n; i++)
#define MAXN 200100
#define MOD 1000000007

vector <int> v;

bool func(int a, int b) {
    if(a==b) {
        v.push_back(a);
        return true;
    }
    if(a>b) return false;
    if(func(2*a, b) || func(10*a+1, b)) {
        v.push_back(a);
        return true;
    }
    return false;
}

void solve() {
    int a, b;
    cin >> a >> b;
    func(a, b);
    if(v.size()) {
        cout << "YES\n";
        cout << v.size() << endl;
        reverse(v.begin(), v.end());
        for(auto i : v) cout << i << " ";
    }
    else cout << "NO";
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // int t; cin >> t; while(t--)
    {solve();}
    return 0;
}