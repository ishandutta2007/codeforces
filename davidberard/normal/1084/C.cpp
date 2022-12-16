#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const ll MOD = 1e9+7;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    string s;
    cin >> s;
    s+='b';
    ll ans = 0;
    char last = 'c';
    int cnt = 0;
    bool sawb = false;
    for(int i=0;i<s.size();++i) {
        if(s[i] == 'b') { 
            sawb = true;
            if(cnt != 0) {
                ans = (ans + cnt*ans+cnt)%MOD;
            }
            cnt = 0;
        }
        if(s[i] == 'a') {
            ++cnt;
        }
    }
    cout << ans << endl;
    return 0;
}