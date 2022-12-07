//

#include <bits/stdc++.h>
#define forn(i, n) for (int i = 0; i < int(n); i++)
#define debug(x) cout << #x << " is " << x << endl
using namespace std;
#define MAXN 105
#define MOD 1000000007

int n, m;
int arr[MAXN][MAXN];
int grr[MAXN][MAXN];

struct Path {
    int x, y, length;
};

Path p[MAXN*MAXN];
Path minp[MAXN];

bool compLength(Path a, Path b) {
    return a.length < b.length;
}

bool compIJ(Path a, Path b) {
    if(a.x==b.x) return a.y<b.y;
    else return a.x<b.x;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    int t;
    cin >> t;
while(t--) {
    cin >> n >> m;
    forn(i, n) {
        forn(j, m) {
            grr[i][j] = 0;
        }
    }
    int k = 0;
    forn(i, n) {
        forn(j, m) {
            cin >> arr[i][j];
            p[k].x = i;
            p[k].y = j;
            p[k].length = arr[i][j];
            k += 1;
        }
    }
    sort(p, p+(n*m), compLength);
    forn(i, m) {
        minp[i].x = p[i].x;
        minp[i].y = p[i].y;
        minp[i].length = p[i].length;
    }
    sort(minp, minp+m, compIJ);
    // forn(i, m) cout << minp[i].x << " " << minp[i].y << " " << minp[i].length << endl;
    forn(j, m) {
        int z = minp[j].x;
        grr[z][j] = minp[j].length;
    }
    // forn(i, n) {
    //     forn(j, m) {
    //         cout << grr[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    forn(i, n) {
        sort(arr[i], arr[i]+m);
    }
    forn(i, n) {
        int k = m-1;
        forn(j, m) {
            if(grr[i][j]==0) {
                grr[i][j] = arr[i][k];
                k -= 1;
            }
        }
    }
    forn(i, n) {
        forn(j, m) {
            cout << grr[i][j] << " ";
        }
        cout << endl;
    }
}
    return 0;
}