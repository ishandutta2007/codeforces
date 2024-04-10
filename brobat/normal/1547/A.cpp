#include <bits/stdc++.h>
using namespace std;
#define forn(i, n) for (long long i = 0; i < n; i++)
#define ll long long
#define MAXN 200100
#define MOD 1000000007
#define BIGINF 1000000000000000000

ll n;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    int t; cin >> t; while(t--)
{
    // Code goes here
    int x1, y1, x2, y2, x3, y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    if(x1==x2&&x1==x3) {
        if((y3>y1&&y3<y2)||(y3<y1&&y3>y2)) {
            cout << abs(y2-y1) + 2;
        }
        else cout << abs(x2-x1) + abs(y2-y1);
    }
    else if(y1==y2&&y1==y3) {
        if((x3>x1&&x3<x2)||(x3<x1&&x3>x2)) {
            cout << abs(x2-x1) + 2;
        }
        else cout << abs(x2-x1) + abs(y2-y1);
    }
    else {
        cout << abs(x2-x1) + abs(y2-y1);
    }
    cout << endl;
}
    return 0;
}