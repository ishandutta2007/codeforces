#include <bits/stdc++.h>
#define int long long
using namespace std;
int check(int x, int y, int t, int v){
    return abs(x-t) + abs(y-v);
}
set<pair<int, int> > kek;
void add(int x, int y, int t, int v){
    //cout << x << " " << y << " " << t << " " << v << endl;
    for (int i=min(x, t); i <= max(x, t); i++) kek.insert({i, y});
    for (int i=min(y, v); i <= max(y, v); i++) kek.insert({t, i});
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int xa, ya, xb, yb, xc, yc;
    cin >> xa >> ya >> xb >> yb >> xc >> yc;
    pair<int, int> best = {-1, -1};
    int ans = 1e18;
    for (int i=-1000; i <= 2000; i++){
        for (int j=-1000; j <= 2000; j++){
            int here = check(i, j, xa, ya) + check(i, j, xb, yb) + check(i, j, xc, yc)+1;
            if (here < ans){
                ans = here;
                best = {i, j};
            }
        }
    }
    int A = best.first, B = best.second;
    add(A, B, xa, ya);
    add(A, B, xb, yb);
    add(A, B, xc, yc);
    cout << kek.size() << endl;
    for (auto it=kek.begin(); it != kek.end();it++){
        pair<int, int> p = *it;
        cout << p.first << " " << p.second << endl;
    }
    return 0;
}