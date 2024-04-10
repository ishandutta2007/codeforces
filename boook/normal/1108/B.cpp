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
#define maxn 200
#define inf 0x3f3f3f3f

int n, x[maxn];

int32_t main(){
	cin.tie(0), cout.sync_with_stdio(0);
	cin >> n;
    for (int i = 1; i <= n; ++ i) cin >> x[i];
    int big = 0;
    for (int i = 1; i <= n; ++ i) big = max(big, x[i]);
    map<int, int> cc;
    for (int i = 1; i <= n; ++ i) cc[x[i]] ++;
    for (auto &to : cc) if (big % to.F == 0) to.S --;
    int sec = 0;
    for (auto to : cc) if (to.S != 0) sec = max(sec, to.F);
    cout << big << " " << sec << "\n";
    return 0;
}