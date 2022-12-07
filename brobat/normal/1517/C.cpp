//

#include <bits/stdc++.h>
#define forn(i, n) for (int i = 0; i < int(n); i++)
#define debug(x) cout << #x << " is " << x << endl
using namespace std;
#define MAXN 505
#define MOD 1000000007

int n;
int p[MAXN];
int arr[MAXN][MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    cin >> n;
    forn(i, n) cin >> p[i];
    forn(i, n) {
        forn(j, n) {
            arr[i][j] = 0;
        }
    }
    forn(k, n) {
        int i = k;
        int j = k;
        int b = p[k];
        while(b>0) {
            b--;
            arr[i][j] = p[k];
            if(j==0) {
                i += 1;
                continue;
            }
            if(arr[i][j-1]!=0) {
                i += 1;
                continue;
            }
            j -= 1;
        }
    }
    forn(i, n) {
        forn(j, i+1) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}