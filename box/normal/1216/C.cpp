#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int x1, y1, x2, y2, x3, y3, x4, y4, x5, y5, x6, y6;
    cin >> x1 >> y1 >> x2 >> y2;
    cin >> x3 >> y3 >> x4 >> y4;
    cin >> x5 >> y5 >> x6 >> y6;
    bool a = (((x3 <= x1 && x2 <= x4) && (y3 <= y1 && y2 <= y4)) || \
              ((x5 <= x1 && x2 <= x6) && (y5 <= y1 && y2 <= y6)) || \
              ((x5 <= x4 && x3 <= x1 && x2 <= x6) && (y3 <= y1 && y2 <= y4) && (y5 <= y1 && y2 <= y6)) || \
              ((x3 <= x1 && x2 <= x4) && (x5 <= x1 && x2 <= x6) && (y5 <= y4 && y3 <= y1 && y2 <= y6)) || \
              ((x3 <= x6 && x5 <= x1 && x2 <= x4) && (y3 <= y1 && y2 <= y4) && (y5 <= y1 && y2 <= y6)) || \
              ((x3 <= x1 && x2 <= x4) && (x5 <= x1 && x2 <= x6) && (y3 <= y6 && y5 <= y1 && y2 <= y4)));
    if(a) cout << "NO" << endl;
    else cout << "YES" << endl;
}