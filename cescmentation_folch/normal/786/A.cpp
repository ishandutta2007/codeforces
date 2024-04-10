#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

vi A[2];
int n;
vi D;
vi R;

void makeg(int n) {
    D = vi(2*n, 0);
    R = vi(2*n, -1);
    for (int i = 1; i < n; ++i) {
        for (int k = 0; k <= 1; ++k) {
            D[i + k*n] = A[k].size();
        }
    }
    R[0] = 0;
    R[n] = 0;
    queue<int> Q;
    Q.push(0);
    Q.push(n);
    while (!Q.empty()) {
        int x = Q.front(); Q.pop();
        int k = (x/n);
        x -= k*n;
        int k1 = 1 - k;
//         k ^= 1;
        for (int i = 0; i < (int)A[k1].size(); ++i) {
            int y = (x - A[k1][i] + n)%(n);
            y += k1*n;
            if (R[y] == -1) {
                R[y] = 1;
                y -= k1*n;
                for (int j = 0; j < (int)A[k].size(); ++j) {
                    int w = (y - A[k][j] + n)%(n);
                    w += k*n;
                    --D[w];
                    if (R[w] == -1 and D[w] == 0) {
                        R[w] = 0;
                        Q.push(w);
                    }
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    int s1, s2;
    cin >> s1;
    A[0] = vi(s1);
    for (int i = 0; i < s1; ++i) cin >> A[0][i];
    cin >> s2;
    A[1] = vi(s2);
    for (int i = 0; i < s2; ++i) cin >> A[1][i];
    makeg(n);
    for (int i = 1; i < n; ++i) {
        if (i > 1) cout << ' ';
        if (R[i] == 1) cout << "Win";
        else if (R[i] == -1) cout << "Loop";
        else cout << "Lose";
    }
    cout << '\n';
    for (int i = 1; i < n; ++i) {
        if (i > 1) cout << ' ';
        if (R[i + n] == 1) cout << "Win";
        else if (R[i + n] == -1) cout << "Loop";
        else cout << "Lose";
    }
    cout << '\n';
}