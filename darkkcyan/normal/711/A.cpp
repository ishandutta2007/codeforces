#include <bits/stdc++.h>

using namespace std;

#ifndef ONLINE_JUDGE
#define log clog << __LINE__ << ": "
#define _ << ' ' <<
#endif

#define long long long
#define ii pair<int, int>
#define ve vector
#define sz(v) ((int) v.size())
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define xx first
#define yy second
#define pb push_back


int main() {
    #ifndef ONLINE_JUDGE
    freopen("inp.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif
    int i;

    int n; cin >> n;
    char a, b, c, d;
    stringstream ss;
    bool f = false;
    for (i = 0; i < n; ++i) {
        cin >> ws; scanf("%c%c|%c%c", &a, &b, &c, &d);
        if (!f and a == 'O' and b == 'O') a = b = '+', f = true;
        else if (!f and c == 'O' and d == 'O') c = d = '+', f = true;
        ss << a << b << '|' << c << d << endl;
    }

    if (!f) cout << "NO";
    else {
        cout << "YES\n";
        cout << ss.str();
    }

    return 0;
}