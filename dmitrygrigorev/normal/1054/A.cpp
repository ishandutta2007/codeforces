#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("1.txt", "r", stdin);
    int x, y, z, t1, t2, t3;
    cin >> x >> y >> z >> t1 >> t2 >> t3;
    int ladder = abs(x-y)*t1;
    int lf = 3*t3 + t2 * (abs(x-z) + abs(x-y));
    if (lf <= ladder) cout << "YES";
    else cout << "NO";

}