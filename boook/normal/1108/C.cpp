/*input

 */
// #include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
#include <bits/stdc++.h>
using namespace std;
#define PII pair<int, int>
#define F first
#define S second
#define endl "\n"
//--------------------------------------
#define maxn 
#define inf 0x3f3f3f3f

int n, ans;
string s, p;

int32_t main(){
    cin.tie(0), cout.sync_with_stdio(0);
    cin >> n >> s;
    ans = inf;
    for (auto v1 : {'R', 'G', 'B'})
        for (auto v2 : {'R', 'G', 'B'}) if (v1 != v2)
            for (auto v3 : {'R', 'G', 'B'}) if (v1 != v3 && v2 != v3){
                string tmp = s;
                int cnt = 0;
                for (int i = 0; i < tmp.size(); ++ i) {
                    if (i % 3 == 0) cnt += tmp[i] != v1, tmp[i] = v1;
                    if (i % 3 == 1) cnt += tmp[i] != v2, tmp[i] = v2;
                    if (i % 3 == 2) cnt += tmp[i] != v3, tmp[i] = v3;
                }
                if (cnt < ans) {
                    p = tmp;
                    ans = cnt;
                }
            }
    cout << ans << "\n" << p << "\n";
    return 0;
}