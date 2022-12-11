#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;

int main() {
    char A[4];
    char B[4];
    for (int i = 0; i < 4; ++i) cin >> A[i];
    for (int i = 0; i < 4; ++i) cin >> B[i];
    swap(A[2], A[3]);
    swap(B[2], B[3]);
    int ja = 0;
    int jb = 0;
    for (int i = 0; i < 4; ++i) {
        if (A[i] == 'A') ja = i;
        if (B[i] == 'A') jb = i;
    }
    for (int i = 0; i < 3; ++i) {
        if (A[ja] == 'X') ja = (ja + 1)%4;
        if (B[jb] == 'X') jb = (jb + 1)%4;
        if (A[ja] != B[jb]) {
            cout << "NO" << endl;
            return 0;
        }
        ja = (ja + 1)%4;
        jb = (jb + 1)%4;
    }
    cout << "YES" << endl;
}