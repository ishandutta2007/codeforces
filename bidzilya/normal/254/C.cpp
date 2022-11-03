#include <bits/stdc++.h>
using namespace std;

const int kAlphabetSize = 26;

vector<int> GetRepr(const string& s)
{
    vector<int> res(kAlphabetSize, 0);
    for (int i = 0; i < (int) s.length(); ++i) {
        char c = s[i];
        ++res[c - 'A'];
    }
    return res;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    string t;

    cin >> s >> t;

    vector<int> rs = GetRepr(s);
    vector<int> rt = GetRepr(t);

    int ans = 0;
    for (int i = 0; i < kAlphabetSize; ++i) {
        ans += abs(rs[i] - rt[i]);
    }
    cout << ans / 2 << endl;

    int n = s.length();
    for (int i = 0; i < n; ++i) {
        int cc = s[i] - 'A';

        if (rs[cc] <= rt[cc]) {
            continue;
        }

        int nc;
        for (int c = 0; c < kAlphabetSize; ++c) {
            if (rs[c] < rt[c]) {
                nc = c;
                break;
            }
        }

        if (nc < cc || rt[cc] == 0) {
            --rs[cc];
            ++rs[nc];
            s[i] = (char)(nc + 'A');
        } else {
            --rs[cc];
            --rt[cc];
        }
    }

    cout << s << endl;

    return 0;
}