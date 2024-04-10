#include <bits/stdc++.h>
using namespace std;
#define long int64_t
static_assert(sizeof(int) == 4 && sizeof(long) == 8);

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int R, C;
        cin >> R >> C;
        vector<string> grid(R);
        for (int i = 0; i < R; i++) {
            cin >> grid[i];
        }
        int red = -1, white = -1;
        bool bad = false;
        for (int i = 0; i < R && !bad; i++) {
            for (int j = 0; j < C && !bad; j++) {
                char c = grid[i][j];
                int parity = (i + j) & 1;
                if (c == 'R') {
                    if (red == -1) {
                        red = parity;
                        bad |= red == white;
                    } else if (red != parity) {
                        bad = true;
                    }
                } else if (c == 'W') {
                    if (white == -1) {
                        white = parity;
                        bad |= red == white;
                    } else if (white != parity) {
                        bad = true;
                    }
                }
            }
        }
        if (bad) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
            if (red == -1 && white == -1) {
                red = 0, white = 1;
            } else if (red == -1) {
                red = !white;
            } else {
                white = !red;
            }
            for (int i = 0; i < R; i++) {
                for (int j = 0; j < C; j++) {
                    int parity = (i + j) & 1;
                    if (parity == red) {
                        cout << 'R';
                    } else {
                        cout << 'W';
                    }
                }
                cout << '\n';
            }
        }
    }
    return 0;
}