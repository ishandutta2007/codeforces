#include <bits/stdc++.h>
#define int long long
using namespace std;
int INF = 1e9;
signed main()
{
//freopen("1.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int max_x=-INF, min_x=INF, max_y=-INF, min_y=INF;
    for (int i=0; i < 4; i++){
        int x, y;
        cin >> x >> y;
        max_x = max(max_x, x);
        min_x = min(min_x, x);
        max_y = max(max_y, y);
        min_y = min(min_y, y);
    }
    int Max_x=-INF, Min_x=INF, Max_y=-INF, Min_y=INF;
    for (int i=0; i < 4; i++){
        int x, y;
        cin >> x >> y;
        Max_x = max(Max_x, x-y);
        Min_x = min(Min_x, x-y);
        Max_y = max(Max_y, x+y);
        Min_y = min(Min_y, x+y);
    }
    for (int x=-100; x <= 100; x++){
        for (int y=-100; y <= 100; y++){
            if (!(x >= min_x && x <= max_x && y >= min_y && y <= max_y)) continue;
            int X = x-y, Y = x+y;
            if (!(X >= Min_x && X <= Max_x && Y >= Min_y && Y <= Max_y)) continue;
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO";
    return 0;
}