#include <bits/stdc++.h>

using namespace std;

int A[2][200200];


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int N, Q;
    cin >> N >> Q;
    int bad = 0;
    
    while(Q--) {
        int r, c;
        cin >> r >> c;
        --r;
        int r1 = 1 - r;
        A[r][c] = !A[r][c];
        if(A[r][c]) {
            bad += A[r1][c - 1] + A[r1][c] + A[r1][c + 1];
        } else {
            bad -= A[r1][c - 1] + A[r1][c] + A[r1][c + 1];
        }
        if(bad) {
            cout << "No\n";
        } else {
            cout << "Yes\n";
        }
    }
    
    return 0;
}