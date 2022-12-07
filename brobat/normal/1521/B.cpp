//

#include <bits/stdc++.h>
#define forn(i, n) for (int i = 0; i < int(n); i++)
using namespace std;
#define MAXN 200100
#define MOD 1000000007

int n;

struct Arrey {
    int x;
    int y;
};

bool comp(Arrey a, Arrey b) {
    return a.x < b.x;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    int t;
    cin >> t;
while(t--) {
    cin >> n;
    Arrey arr[n];
    forn(i, n) {
        cin >> arr[i].x;
        arr[i].y = i;
    }
    sort(arr, arr+n, comp);
    cout << n-1 << endl;
    // forn(i, n) cout << arr[i].x << " " << arr[i].y << endl;
    forn(i, n-1) {
        int a, b, c, d;
        a = arr[0].y + 1;
        b = arr[i+1].y + 1;
        c = arr[0].x;
        d = c + abs(arr[i+1].y - arr[0].y);
        cout << a << " " << b << " " << c << " " << d << endl;
    }
}
    return 0;
}