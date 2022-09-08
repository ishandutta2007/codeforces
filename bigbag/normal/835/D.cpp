#include <map>
#include <set>
#include <stack>
#include <cmath>
#include <ctime>
#include <queue>
#include <vector>
#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <ctime>

using namespace std;

const int max_n = 5055, inf = 1011111111;
const int p1 = 37, p2 = 39, mod = 1000000007;

struct Hash {

    //int pw1[max_n], h1[max_n];
    long long pw2[max_n], h2[max_n];

    Hash() {

    }

    Hash(const string &s) {
        //pw1[0] = 1;
        pw2[0] = 1;
        //h1[0] = s[0] - 'a' + 1;
        h2[0] = s[0] - 'a' + 1;
        for (int i = 1; i < max_n; ++i) {
            //pw1[i] = (1LL * pw1[i - 1] * p1) % mod;
            pw2[i] = pw2[i - 1] * p2;
            //h1[i] = (1LL * h1[i - 1] * p1 + s[i] - 'a' + 1) % mod;
            h2[i] = (1LL * h2[i - 1] * p2 + s[i] - 'a' + 1);
        }
    }

    long long /*pair<long long, int>*/ get_hash(int l, int r) {
        long long r2 = h2[r];//, r1 = h1[r];
        if (l) {
            r2 -= pw2[r - l + 1] * h2[l - 1];
            /*r1 -= (1LL * pw1[r - l + 1] * h1[l - 1]) % mod;
            r1 %= mod;
            if (r1 < 0) {
                r1 += mod;
            }*/
        }
        return r2;//make_pair(r2, r1);
    }
};

int n, ans[max_n];
string s, rs;
Hash h, rh;

bool pal(int l, int r) {
    return h.get_hash(l, r) == rh.get_hash(n - r - 1, n - l - 1);
}

double ST = clock();

double time() {
    return (clock() - ST) / CLOCKS_PER_SEC;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> s;
    n = s.length();
    rs = s;
    reverse(rs.begin(), rs.end());
    h = Hash(s);
    rh = Hash(rs);
    for (int i = 0; i < s.length(); ++i) {
        for (int j = i; j < s.length(); ++j) {
            int l = i, r = j;
            for (int k = 1; ; ++k) {
                if (pal(l, r)) {
                    ++ans[k];
                }
                if (l == r) {
                    break;
                }
                int l1, r1, l2, r2;
                l1 = l;
                r1 = (l + r - 1) / 2;
                l2 = (l + r) / 2 + 1;
                r2 = r;
                if (h.get_hash(l1, r1) == h.get_hash(l2, r2)) {
                    l = l1;
                    r = r1;
                } else {
                    break;
                }
            }
        }
    }
    for (int i = 1; i <= s.length(); ++i) {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}