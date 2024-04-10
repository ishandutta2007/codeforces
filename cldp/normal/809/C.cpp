#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 1010;
const int INF = 1000000007;

int sum[32][2][2][2], cnt[32][2][2][2];

void add(int &a, int b) {
    a = (a + b) % INF;
}

void sub(int &a, int b) {
    a = (a - b + INF) % INF;
}

int mul(int a, int b) {
    return 1LL * a * b % INF;
}

int query(int aa, int bb, int cc) {
    if (aa < 0 || bb < 0 || cc < 0) return 0;
    memset(sum, 0, sizeof(sum));
    memset(cnt, 0, sizeof(cnt));
    vector<int> A, B, C;
    for (int i = 0; i < 31; ++i) {
        A.push_back(aa % 2); aa /= 2;
        B.push_back(bb % 2); bb /= 2;
        C.push_back(cc % 2); cc /= 2;
    }
    reverse(A.begin(), A.end());
    reverse(B.begin(), B.end());
    reverse(C.begin(), C.end());
    cnt[0][1][1][1] = 1;
    sum[0][1][1][1] = 0;

    for (int i = 0; i < 31; ++i) {
        for (int a = 0; a < 2; ++a)
        for (int b = 0; b < 2; ++b) 
        for (int c = 0; c < 2; ++c) 
        for (int x = 0; x < 2; ++x)
        for (int y = 0; y < 2; ++y) {
            int z = x ^ y;
            if (a == 1 && A[i] == 0 && x == 1) continue;
            if (b == 1 && B[i] == 0 && y == 1) continue;
            if (c == 1 && C[i] == 0 && z == 1) continue;

            add(cnt[i + 1][a & (A[i] == x)][b & (B[i] == y)][c & (C[i] == z)], cnt[i][a][b][c]);
            add(sum[i + 1][a & (A[i] == x)][b & (B[i] == y)][c & (C[i] == z)], sum[i][a][b][c]);
            add(sum[i + 1][a & (A[i] == x)][b & (B[i] == y)][c & (C[i] == z)], 1LL * cnt[i][a][b][c] * (z << (30 - i)) % INF);
            
        }
    } 

    int ans = 0;
    for (int a = 0; a < 2; ++a)
    for (int b = 0; b < 2; ++b)
    for (int c = 0; c < 2; ++c) {
        add(ans, sum[31][a][b][c]);
        add(ans, cnt[31][a][b][c]);
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    int N;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        int x1, y1, x2, y2, K;
        cin >> x1 >> y1 >> x2 >> y2 >> K;
        --x1, --y1, --x2, --y2, --K;
        int ans = query(x2, y2, K);
        add(ans, query(x1 - 1, y1 - 1, K));
        sub(ans, query(x1 - 1, y2, K));
        sub(ans, query(x2, y1 - 1, K));
        cout << ans << endl;
    }
    return 0;
}