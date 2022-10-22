#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 100010;
const int INF = 1000000007;
const double PI = acos(-1.0);

bool z[26];
bool cz[26];
char c[MAXN];
string Q[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    int N;
    cin >> N;
    for (int i = 0; i < 26; ++i) z[i] = true;
    int pos = -1;
    for (int i = 0; i < N; ++i) {
        cin >> c[i] >> Q[i];
        memset(cz, 0, sizeof(cz));
        for (int j = 0; j < Q[i].size(); ++j) cz[Q[i][j] - 'a'] = true;
        if (c[i] == '.') {
            for (int j = 0; j < 26; ++j) {
                if (cz[j]) z[j] = false;
            }
        }
        if (c[i] == '?') {
            if (i != N - 1) z[Q[i][0] - 'a'] = false;
        }
        if (c[i] == '!') {
            for (int j = 0; j < 26; ++j) {
                if (!cz[j]) z[j] = false;
            }
        }
        if (pos != -1) continue;
        int cnt = 0;
        for (int j = 0; j < 26; ++j) {
            if (z[j]) ++cnt;
        }
        if (cnt == 1) pos = i;
    }

    if (pos == -1) {
        cout << 0 << endl;
        return 0;
    }

    int ans = 0;
    for (int i = pos + 1; i < N; ++i) {
        if (c[i] == '!') {
            ++ans;
            continue;
        }
        if (c[i] == '.') continue;
        if (c[i] == '?') {
            if (Q[i] == Q[N - 1]) continue;
            ++ans;
        }
    }

    cout << ans << endl;
    return 0;
}