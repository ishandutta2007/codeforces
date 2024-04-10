#include <bits/stdc++.h>

using namespace std;

string t, a, b, c, ans;
string aa, bb, cc;
map<pair<char, pair<char, char>>, int> pos;

string query(const string &s) {
    cout << "? " << s << endl;
    string res;
    cin >> res;
    return res;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> t;
    for (char q = 'a'; q <= 'z'; ++q) {
        for (char w = 'a'; w <= 'z'; ++w) {
            for (char e = 'a'; e <= 'z' && a.length() < t.length(); ++e) {
                a += q;
                b += w;
                c += e;
            }
        }
    }
    aa = query(a);
    bb = query(b);
    cc = query(c);
    ans = t;
    for (int i = 0; i < t.length(); ++i) {
        pos[make_pair(a[i], make_pair(b[i], c[i]))] = i;
    }
    for (int i = 0; i < t.length(); ++i) {
        ans[pos[make_pair(aa[i], make_pair(bb[i], cc[i]))]] = t[i];
    }
    cout << "! " << ans << endl;
    return 0;
}