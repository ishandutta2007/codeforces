#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define y1 y114514
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
#define all(a) a.begin(), a.end()
const int M = 1000000007;

const int maxn = 50005;
int T;
int n;
int r[maxn][5];

bool cmp(int x, int y) {
    int cnt = 0;
    for (int i = 0; i < 5; ++i) cnt += r[x][i] < r[y][i];
    return cnt >= 3;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> T;
    while (T--) {
        cin >> n;

        int cur = -1;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < 5; ++j) cin >> r[i][j];
            if (cur == -1 || cmp(i, cur)) cur = i;
        }
        bool flag = true;
        for (int i = 0; i < n && flag; ++i) flag &= i == cur || cmp(cur, i);
        cout << (flag ? cur + 1 : -1) << "\n";
    }

    return 0;
}