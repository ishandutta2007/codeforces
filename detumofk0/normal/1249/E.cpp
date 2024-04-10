#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    if(fopen("1.inp" ,"r")) freopen("1.inp", "r", stdin);

    int n, c;
    cin >> n >> c;
    int ansx = 0, ansy = c;

    vector < int > a(n - 1), b(n - 1);
    for(int &x : a) cin >> x;
    for(int &x : b) cin >> x;

    cout << 0 << " ";
    for(int i = 0; i < n - 1; ++i) {
        int x = min(ansx + a[i], ansy + b[i]);
        int y = min(ansy + b[i], ansx + a[i] + c);
        ansx = x;
        ansy = y;
        cout << min(ansx, ansy) << " ";
    }

    cout << endl;

    return 0;
}