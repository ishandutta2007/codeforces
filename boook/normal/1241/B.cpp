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

int t;
string s1, s2;

int32_t main(){
	cin.tie(0), cout.sync_with_stdio(0);
	cin >> t;
    while (t --) {
        cin >> s1 >> s2;
        int ok = 0;
        for (auto v1 : s1) {
            for (auto v2 : s2) {
                if (v1 == v2) ok = 1;
            }
        }
        cout << (ok ? "YES" : "NO") << "\n";
    }
    return 0;
}