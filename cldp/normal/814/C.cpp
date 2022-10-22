#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 2010;
const int INF = 1000000007;
const double PI = acos(-1.0);

char ch(int a) {
    return a + 'a';
}

int ans[26][MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    int N;
    cin >> N;
    string P;
    cin >> P;

    for (int i = 0; i < 26; ++i) {
        vector<int> X, Y;
        int j = 0;
        if (P[0] != ch(i)) X.push_back(0);
        while (j < N) {
            int k = j;
            if (P[j] == ch(i)) {
                while (k < N && P[k] == ch(i)) ++k;
                X.push_back(k - j);
                j = k;
            } else {
                while (k < N && P[k] != ch(i)) ++k;
                Y.push_back(k - j);
                j = k;
            }
        }
        if (P[N - 1] != ch(i)) X.push_back(0);


        for (int j = 1; j <= N; ++j) {
            for (int k = 0; k < X.size(); ++k) ans[i][j] = max(ans[i][j], X[k] + j);

            int L = 0, R = 0, used = 0, cnt = X[0];
            while (R + 1 < X.size()) {
                while (R + 1 < X.size() && used + Y[R] <= j) {
                    used += Y[R];
                    cnt += Y[R] + X[R + 1];
                    ++R;
                }
                ans[i][j] = max(ans[i][j], cnt + j - used);
                if (L < R) {
                    used -= Y[L];
                    cnt -= X[L] + Y[L];
                    ++L;
                } else {
                    L = R = L + 1;
                    used = 0;
                    cnt = X[L];
                }
            }
            ans[i][j] = min(ans[i][j], N);
        }
    }

    int M;
    cin >> M;
    for (int i = 0; i < M; ++i) {
        int a;
        char b;
        cin >> a >> b;
        cout << ans[b - 'a'][a] << endl;
    }
    return 0;
}