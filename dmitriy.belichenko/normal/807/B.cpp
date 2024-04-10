#include <bits/stdc++.h>

using namespace std;

set<int> gg;

void get(int p){
    for (int i = 0; i <= 474; ++i){
        int tmp = i;
        for (int j = 0; j < 25; ++j){
            tmp = (tmp * 96 + 42) % 475;
            if (p == (26 + tmp))
                gg.insert(i);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n, x, y;
    cin >> n >> x >> y;
    get(n);
    int ans = (int)1e9 + 7;
    for (int g: gg){
    int d = g - x / 50;
        if (d == 0)
            ans = min(ans, 0);
        else if (d > 0)
            if (y > x + d * 50){
                d += 475;
                ans = min(ans, d / 2 + (d % 2));
            }
            else{
                ans = min(ans, d / 2 + (d % 2));
            }
        else{
            if (y > x + d * 50){
                ans = min(ans, (475 - d) / 2);
            }
            else{
                ans = min(ans, 0);
            }
        }
    }
    cout << ans << '\n';
    return 0;
}