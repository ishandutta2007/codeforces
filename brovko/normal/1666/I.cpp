#include <bits/stdc++.h>

using namespace std;
using li = long long;

const li INF64 = 1e18 + 13;
const int N = 200 + 13;

//int X1 = 10, Y1 = 4, X2 = 5, Y2 = 13;

int scan(int y, int x) {
    cout << "SCAN " << x + 1 << ' ' << y + 1 << endl;
    int res;
    cin >> res;
    return res;
}
//
int dig(int y, int x) {
    cout << "DIG " << x + 1 << ' ' << y + 1 << endl;
    int res;
    cin >> res;
    return res;
}

//int scan(int x, int y) {
////    cout << "SCAN " << x + 1 << ' ' << y + 1 << endl;
//    int res = abs(x - X1) + abs(x - X2) + abs(y - Y1) + abs(y - Y2);
////    cin >> res;
//    return res;
//}

//int dig(int x, int y) {
////    cout << "DIG " << x + 1 << ' ' << y + 1 << endl;
//    int res = (x == X1 && y == Y1 || x == X2 && y == Y2);
////    cout << res << endl;
////    cin >> res;
//    return res;
//}


void solve() {
    int n, m;
//    n = 16, m = 16;
    cin >> n >> m;

    vector<int> x = {0, 0, -1, -1};
    vector<int> y = {0, n - 1, -1, -1};

    vector<int> a(6);
    for(int i = 0; i < 2; i++)
        a[i] = scan(x[i], y[i]);
    a[2] = 2*(n+m - 2) - a[1];
    a[3] = 2*(n+m - 2) - a[0];
    a[4] = scan(0, (2*n + a[0] - a[1]) / 4);
    a[5] = scan((2*m + a[0] - a[2]) / 4, 0);
    int x1, x2, y1, y2;
    y1 = (a[0] - a[4])/2;
    y2 = (a[1] - a[4])/2;
    x1 = (a[0] - a[5])/2;
    x2 = (a[2] - a[5])/2;
    y2 = n - y2 - 1;
    x2 = m - x2 - 1;
    if(dig(x1, y1)){
        dig(x2, y2);
    }
    else{
        dig(x1, y2);
        dig(x2, y1);
    }

}

int main() {
    int t = 1;
    cin >> t;

    while(t--) {
        solve();
    }


}