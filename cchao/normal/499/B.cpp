#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    map<string, string> f;
    while(m--) {
        string a, b;
        cin >> a >> b;
        f[a] = f[b] = b.size() < a.size() ? b : a;
    }
    while(n--) {
        string s; cin >> s;
        cout << f[s] << ' ';
    }
    cout << endl;

    return 0;
}