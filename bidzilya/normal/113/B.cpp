#include <cstdio>
#include <cstring>

#include <vector>
#include <algorithm>
#include <iomanip>
#include <queue>
#include <map>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair<int, int> pii;

const int max_int = (1LL << 31) - 1;

//#define LOCAL

#ifdef LOCAL
#include <fstream>
ifstream cin("input.txt");
ofstream cout("output.txt");
#else
#include <iostream>
#endif

const int max_len = 2e3 + 100;
const int max_alp = 26;

string s, s1, s2;

int a[max_len], b[max_len], t[max_len];
int pnum[max_len][max_alp], us[max_len];
int c;

int main() {
    ios_base::sync_with_stdio(false); 
    cin >> s >> s1 >> s2;
    for (int i = 0; i <= (int) (s.length() - s1.length()); ++i) {
        bool f = 1;
        for (int j = 0; j < (int) s1.length(); ++j)
            if (s[i + j] != s1[j]) {
                f = 0;
                break;
            }
        a[i] = f;
    }
    for (int i = 0; i <= (int) (s.length() - s2.length()); ++i) {
        bool f = 1;
        for (int j = 0; j < (int) s2.length(); ++j)
            if (s[i + j] != s2[j]) {
                f = 0;
                break;
            }
        b[i + s2.length() - 1] = f;
    }
    c = 1;
    int ans = 0;
    for (int len = 1; len <= (int) s.length(); ++len) {
        for (int i = 0; i < c; ++i)
            for (int j = 0; j < max_alp; ++j)
                pnum[i][j] = -1;
        c = 0;
        for (int i = 0; i + len <= (int) s.length(); ++i)
            if (pnum[t[i]][s[i + len - 1] - 'a'] == -1) {
                pnum[t[i]][s[i + len - 1] - 'a'] = c;
                t[i] = c;
                ++c;
            } else {
                t[i] = pnum[t[i]][s[i + len - 1] - 'a'];
            }
        if (len < (int) max(s1.length(), s2.length())) continue;
        for (int i = 0; i < c; ++i)
            us[i] = 0;
        for (int i = 0; i + len <= (int) s.length(); ++i)
            if (!us[t[i]] && a[i] && b[i + len - 1]) {
                ++ans;
                us[t[i]] = 1;
            }
    }
    cout << ans << endl;
    return 0;
}