#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
typedef long double ld;

string solve() {
    string s;
    cin >> s;
    vector<char> e, o;
    for (auto& c : s) {
        if (c%2) {
            o.push_back(c);
        } else {
            e.push_back(c);
        }
    }
    string t;
    int i=0, j=0;
    for(; i<e.size() || j<o.size();) {
        if (i == e.size() || (j != o.size() && e[i] > o[j])) {
            t += o[j++];
        } else {
            t += e[i++];
        }
    }
    return t;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int TT;
    cin >> TT;
    for (int tt=0; tt<TT;++tt) {
        cout << solve() << "\n";
    }
    return 0;
}