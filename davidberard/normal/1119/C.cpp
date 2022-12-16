#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
typedef long double ld;

int n, m;

const int NMAX = 505;

int A[NMAX][NMAX];
int B[NMAX][NMAX];
int D[NMAX][NMAX];

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m;
    for(int i=0;i<n;++i) {
        for(int j=0;j<m;++j) {
            cin >> A[i][j];
        }
    }
    for(int i=0;i<n;++i) {
        int rs = 0;
        for(int j=0;j<m;++j) {
            cin >> B[i][j];
            D[i][j] = A[i][j]^B[i][j];
            rs += D[i][j];
        }
        if(rs%2) {
            cout << "No" << endl;
            return 0;
        }
    }
    for(int j=0;j<m;++j) {
        int cs = 0;
        for(int i=0;i<n;++i) {
            cs += D[i][j];
        }
        if(cs%2) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}