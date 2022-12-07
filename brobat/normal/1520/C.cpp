//

#include <bits/stdc++.h>
#define forn(i, n) for (int i = 0; i < int(n); i++)
using namespace std;
#define MAXN 105
#define MOD 1000000007

int n;
int arr[MAXN][MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    int t;
    cin >> t;
while(t--) {
    int x = 1;
    cin >> n;
    forn(i, n) forn(j, n) arr[i][j] = 0;
    if(n%2==1) {
        arr[n/2][n/2] = 1;
        x = 2;
    }
    int done = 0;
    int z = n*n;
    forn(i, n) {
        forn(j, n) {
                if(i==0&&j==0) arr[i][j] = x;
                else if(arr[i][j]==1) {
                    continue;
                }
                else if(i==0&&j!=0) {
                    if(arr[i][j-1]==0) arr[i][j] = x;
                    else continue;
                }
                else if(i!=0) {
                    if(arr[i-1][j]==0) arr[i][j] = x;
                    else continue;
                }
                x += 1;
                if(x>z) done = 1;
                if(done) break;
            }
        if(done) break;
    }
    forn(i, n) {
        forn(j, n) {
            if(!arr[i][j]) {
                arr[i][j] = x;
                x += 1;
            }
        }
    }
    if(n==1) cout << 1 << endl;
    else if(n==2) cout << -1 << endl;
    else {
        forn(i, n) {
            forn(j, n) {
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }
    }
}
    return 0;
}