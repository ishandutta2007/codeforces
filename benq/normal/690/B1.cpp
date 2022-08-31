#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mp make_pair
#define pb push_back
#define pii pair <int, int>
#define vi vector<int>

#define FOR(i, a, b) for (int i=a; i<b; i++)
#define F0R(i, a) for (int i=0; i<a; i++)

#define f first
#define s second
#define lb lower_bound
#define ub upper_bound

const int MOD = 1000000007;
double PI = 4*atan(1);

int main() {
    ios_base::sync_with_stdio(0);
    int n,arr[50][50]; cin >> n;
    int xl=51, yl=51, xh=-1,yh=-1;
    F0R(i,n) F0R(j,n) {
        char x; cin >> x;
        arr[j][i] = int(x-'0');
        if (arr[j][i] == 4) {
            xl=min(xl,j),xh = max(xh,j);
            yl = min(yl,i), yh = max(yh,i);
        }
    }
    F0R(i,n) F0R(j,n) {
        if (xl <= j && j <= xh && yl <= i && i <= yh) {
            if (arr[j][i] != 4) {
                cout << "No";
                return 0;
            }
        } else if ((j == xl-1 || j == xh+1) && yl <= i && i <= yh) {
            if (arr[j][i] != 2) {
                cout << "No";
                return 0;
            }
        } else if ((i == yl-1 || i == yh+1) && xl <= j && j <= xh) {
            if (arr[j][i] != 2) {
                cout << "No";
                return 0;
            }
        } else if ((i == yl-1 || i == yh+1) && (j == xl-1 || j == xh+1)) {
            if (arr[j][i] != 1) {
                cout << "No";
                return 0;
            }
        } else {
            if (arr[j][i] != 0) {
                cout << "No";
                return 0;
            }
        }
    }
    cout << "Yes";
}