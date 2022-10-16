#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int n, a, b;
    cin >> n >> a >> b;
    
    typedef vector<int> row;
    typedef vector<row> table;
    
    table seats(a, row(b));
    
    int odd = 1;
    int even = 2;
    for (int r = 0; r < a; ++r) {
        for (int c = 0; c < b; ++c) {
            if ((r + c) % 2 == 1) {
                if (even <= n) {
                    seats[r][c] = even;
                    even += 2;
                }
            } else {
                if (odd <= n) {
                    seats[r][c] = odd;
                    odd += 2;
                }
            }
        }
    }
    
    if (even <= n || odd <= n) {
        cout << -1 << endl;
    } else {
        for (int r = 0; r < a; ++r) {
            for (int c = 0; c < b; ++c) {
                if (c > 0) cout << ' ';
                cout << seats[r][c];
            }
            cout << endl;
        }
    }
}

int main() {
    solve();
    return 0;
}