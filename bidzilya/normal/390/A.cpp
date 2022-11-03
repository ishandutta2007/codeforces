#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    vector<int> x(101, 0);
    vector<int> y(101, 0);
    for (int i = 0; i < n; ++i) {
        int cx, cy;
        cin >> cx >> cy;
        x[cx] = 1;
        y[cy] = 1;
    }
    int ansx = 0;
    int ansy = 0;
    for (int i = 0; i <= 100; ++i) {
        ansx += (x[i] > 0);
        ansy += (y[i] > 0);
    }
    
    cout << min(ansx, ansy) << endl;
    
    return 0;
}