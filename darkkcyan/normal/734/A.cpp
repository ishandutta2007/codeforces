#include <bits/stdc++.h>

using namespace std;

#define fn "main"
#define long long long
#define ve vector
#define xx first
#define yy second
#define bb begin()
#define ee end()
#define rbb rbegin()
#define ree rend()
#define sz(v) ((int) v.size())
#define inf(type) (numeric_limits<type>::max() - 10)
#define vi ve<int>
#define ii pair<int, int>

int main() {
    #ifndef ONLINE_JUDGE
    freopen(fn".inp", "r", stdin);
    freopen(fn".out", "w", stdout);
    #endif // ONLINE_JUDGE

    int n;
    cin >> n;
    static string a; cin >> a;
    int at = count(a.bb, a.ee, 'A');
    if (at > (n - at)) cout << "Anton";
    else if (at < (n - at)) cout << "Danik";
    else cout << "Friendship";


    return 0;
}