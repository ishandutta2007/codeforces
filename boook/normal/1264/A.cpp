#include <bits/stdc++.h>
using namespace std;

const int maxn = 400000 + 10;

int t, n, x[maxn];
int main() {
    cin.tie(0), cout.sync_with_stdio(0);
    cin >> t;
    while (t --) {
        cin >> n;
        for (int i = 1; i <= n; ++ i) cin >> x[i];
        map<int, int> cc;
        for (int i = 1; i <= n; ++ i) cc[-x[i]] ++;
        int v1 = 0, v2 = 0, v3 = 0;
        for (auto to : cc) {
            if (v1 == 0) v1 = to.second;
            else if(v2 <= v1) v2 += to.second;
            else if(v3 <= v1) v3 += to.second;
            else if((v1 + v2 + v3 + to.second) * 2 <= n) v3 += to.second;
            else break;
        }
        if (v1 != 0 && v2 != 0 && v3 != 0 && v2 > v1 && v3 > v1 && (v1 + v2 + v3) * 2 <= n)
            cout << v1 << " " << v2 << " " << v3 << "\n";
        else cout << "0 0 0\n" ;
    }
    return 0;
}