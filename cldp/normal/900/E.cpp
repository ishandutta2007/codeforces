#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 100010;
const int INF = 1000000007;
const double PI = acos(-1.0);

int cnt[MAXN];

void add(int x) {
    for (int i = x; i < MAXN; i += (i & (-i))) ++cnt[i];
}

int query(int l, int r) {
    int ans = 0;
    for (int i = r; i > 0; i -= (i & (-i))) ans += cnt[i];
    for (int i = l - 1; i > 0; i -= (i & (-i))) ans -= cnt[i];
    return ans;
}


int f[MAXN][2], h[MAXN][2];


int main() {
    ios_base::sync_with_stdio(false);
    int N, M;
    string Q;
    cin >> N >> Q >> M;
    for (int i = 0; i < N; ++i) {
        if (Q[i] == 'a') {
            f[i + 1][0] = 1;
            if (f[i][1] > 0) f[i + 1][0] = f[i][1] + 1;
        }
        if (Q[i] == 'b') {
            if (f[i][0] > 0) f[i + 1][1] = f[i][0] + 1;
        }
        if (Q[i] == '?') {
            add(i + 1);
            f[i + 1][0] = 1;
            if (f[i][1] > 0) f[i + 1][0] = f[i][1] + 1; 
            if (f[i][0] > 0) f[i + 1][1] = f[i][0] + 1; 
        }

      //  cout << i + 1 << " " << f[i + 1][0] << " " << f[i + 1][1] << endl;
    }
   // cout << endl;
    int op = (M - 1) & 1;
    for (int i = M; i <= N; ++i) {
        h[i][0] = h[i - 1][0];
        h[i][1] = h[i - 1][1];
        if (f[i][op] < M) continue;
        int a = h[i - M][0] + 1;
        int b = h[i - M][1] + query(i - M + 1, i);
        if (a > h[i][0] || (a == h[i][0] && b < h[i][1])) {
            h[i][0] = a;
            h[i][1] = b;
        }
      //  cout << i << " " << h[i][0] << " " << h[i][1] << endl;
    }
    cout << h[N][1] << endl;
    return 0;
}