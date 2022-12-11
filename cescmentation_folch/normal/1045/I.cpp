#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair<int, int> ii;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    map <int,long long>m;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        int p = 0;
        for (int j = 0; j < s.size(); ++j) {
            p ^= (1<<(s[j]-'a'));
        }
        m[p]++;
    }
    long long ans = 0;
    for (auto it = m.begin(); it != m.end(); ++it) {
        ll a = it ->first;
        long long b = (it->second);
        ans += b*(b-1);
        for (int i = 0; i <= 'z'-'a'; ++i) {
            if (m.count(a^(1<<i))) ans += b*m[a^(1<<i)];
        }
    }
    cout << ans/2 << endl;
}