#include <bits/stdc++.h>

using namespace std;

#define long int64_t

// Based on editorial

int main() {
    ios::sync_with_stdio(false);
    unsigned T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;
        vector<string> grid(N);
        for (int i = 0; i < N; i++) {
            cin >> grid[i];
        }

        int count[2][3] = {};

        int K = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (grid[i][j] != '.') {
                    count[grid[i][j] == 'X'][(i + j) % 3]++;
                    K++;
                }
            }
        }

        for (int a : {0, 1, 2}) {
            for (int b : {0, 1, 2}) {
                if (a != b && count[0][a] + count[1][b] <= K / 3) {
                    for (int i = 0; i < N; i++) {
                        for (int j = 0; j < N; j++) {
                            if (grid[i][j] != '.') {
                                int c = (i + j) % 3;
                                if (a == c) {
                                    grid[i][j] = 'X';
                                } else if (b == c) {
                                    grid[i][j] = 'O';
                                }
                            }
                        }
                    }
                    goto write_answer;
                }
            }
        }

    write_answer:
        for (int i = 0; i < N; i++) {
            cout << grid[i] << endl;
        }
    }
    return 0;
}