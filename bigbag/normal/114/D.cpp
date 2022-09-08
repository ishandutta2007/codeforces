#include <map>
#include <set>
#include <stack>
#include <cmath>
#include <queue>
#include <vector>
#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

const int max_n = 2022;
const char min_c = 'a';
const long long p1 = 31, mod1 = 1000000007;
const long long p2 = 101, mod2 = 1000000009;

struct Hash {
    long long p, mod;
    long long h[max_n], pw[max_n];
    Hash() {
        p = mod = 1;
    }
    Hash(string s, long long P, long long Mod) {
        p = P;
        mod = Mod;
        pw[0] = 1;
        for (int i = 1; i < max_n; ++i) {
            pw[i] = (pw[i - 1] * p) % mod;
        }
        h[0] = s[0] - min_c + 1;
        for (int i = 1; i < s.length(); ++i) {
            h[i] = (p * h[i - 1] + s[i] - min_c + 1) % mod;
        }
    }
    long long get_hash(long long l, long long r) {
        long long x = h[r], y = 0;
        if (l != 0) {
            y = h[l - 1] * pw[r - l + 1];
        }
        return ((x - y) % mod + mod) % mod;
    }
};

string s, a, b;
int h1[2], h2[2];
Hash H[2];
vector<pair<int, int> > v;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> s >> a >> b;

    H[0] = Hash(a, p1, mod1);
    H[1] = Hash(a, p2, mod2);
    h1[0] = H[0].get_hash(0, a.length() - 1);
    h2[0] = H[1].get_hash(0, a.length() - 1);

    H[0] = Hash(b, p1, mod1);
    H[1] = Hash(b, p2, mod2);
    h1[1] = H[0].get_hash(0, b.length() - 1);
    h2[1] = H[1].get_hash(0, b.length() - 1);

    H[0] = Hash(s, p1, mod1);
    H[1] = Hash(s, p2, mod2);

    int mx = max(a.length(), b.length());
    for (int l = 0; l < s.length(); ++l) {
        for (int r = l + mx - 1; r < s.length(); ++r) {
            int H1 = H[0].get_hash(l, l + a.length() - 1);
            int H2 = H[0].get_hash(r - b.length() + 1, r);
            //cout << l << " " << r << "   " << H1 << " " << h1[0] << "    " << H2 << " " << h1[1] << endl;
            if (H1 == h1[0] && H2 == h1[1]) {
                int H11 = H[1].get_hash(l, l + a.length() - 1);
                int H22 = H[1].get_hash(r - b.length() + 1, r);
                //cout << l << " " << r << "  + " << H11 << " " << h2[0] << "    " << H22 << " " << h2[1] << endl;
                if (H11 == h2[0] && H22 == h2[1]) {
                    v.push_back(make_pair(H[0].get_hash(l, r), H[1].get_hash(l, r)));
                }
            }
        }
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    cout << v.size() << endl;
    return 0;
}