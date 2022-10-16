#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

int count(const string& s, const string& p) {
    string t = ' ' + p + '#' + s;
    vector<int> k(t.size());
    int res = 0;
    for (int i = 2; i < t.size(); ++i) {
        int x = k[i-1];
        while (t[x + 1] != t[i] && x > 0) x = k[x];
        if (t[x + 1] == t[i]) k[i] = x + 1;
        if (k[i] == p.length()) res++;
    }
    return res;
}

void solve() {
    string s;
    int n;
    cin >> s;
    cin >> n;
    vector<string> p(n);
    vector<int> l(n);
    vector<int> r(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i] >> l[i] >> r[i];
    }
    
    int ans = 0;

    set<string> st;

    for (int o = 0; o < s.length(); ++o) {
        int L = 1;
        int R = s.length() - o;

        for (int i = 0; i < n; ++i) {
            while (L <= R && count(p[i], s.substr(o, L)) > r[i]) ++L;
            while (L <= R && count(p[i], s.substr(o, R)) < l[i]) --R;
        }
        ans += R - L + 1;
        for (int ln = L; ln <= R; ln++)
            st.insert(s.substr(o, ln));
    }

    cout << st.size() << endl;
}

int main() {
    solve();
    return 0;
}