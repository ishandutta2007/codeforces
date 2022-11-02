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

int n;
string s;
int32_t main(){
	cin.tie(0), cout.sync_with_stdio(0);
	cin >> n >> s;
    int ans = 0;
    for (int i = 1; i < s.size(); ++ i) {
        if (s[i] == s[i - 1]) {
            ans ++;
            if (i + 1 == s.size() || s[i - 1] == s[i + 1]) 
                s[i] = (s[i - 1] == 'R' ? 'B' : 'R');
            else s[i] = 'B' ^ 'R' ^ 'G' ^ s[i + 1] ^ s[i - 1];
        }
    }
    cout << ans << "\n" << s << "\n";
    return 0;
}