#include<bits/stdc++.h>

using namespace std;

const int N = 1e6 + 10;
int D[3][3][N];
int V[N];


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        V[x]++;
    }
    
    for (int l1 = 0; l1 <= 2; ++l1) {
        for (int l2 = 0; l2 <= 2; ++l2) {
            D[l1][l2][0] = -1;
        }
    }
    D[0][0][0] = 0;
    

    for (int i = 1; i <= m; ++i) {
        for (int l1 = 0; l1 <= 2; ++l1) {
            for (int l2 = 0; l2 <= 2; ++l2) {
                D[l1][l2][i] = -1;
                for (int l3 = 0; l3 <= 2; ++l3) {
                    if (D[l2][l3][i-1] == -1) continue;
                    if (V[i] >= l1 + l2 + l3) {
                        int val = D[l2][l3][i-1] + l3 + (V[i] - (l1 + l2 + l3))/3;
                        D[l1][l2][i] = max(D[l1][l2][i], val);
                    }
                }
            }
        }
    }

    cout << D[0][0][m] << '\n';
}