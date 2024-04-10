#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#include <bits/stdc++.h>
#define sz(a) int((a).size())
#define x first
#define y second
using namespace std;
typedef long long ll;
int n;
vector<int> num[4];
int main() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        char s[10];
        int x;
        cin >> s >> x;
        int g = (s[0] - '0') << 1 | (s[1] - '0');
        num[g].push_back(x);
    }
    for(int i = 0; i < 4; i++) sort(num[i].begin(), num[i].end(), greater<int> ());
    int sum = 0;
    for(int x : num[3]) sum += x;
    int len = min(sz(num[1]), sz(num[2]));
    for(int i = 0; i < len; i++) sum += num[1][i] + num[2][i];
    num[1].erase(num[1].begin(), num[1].begin() + len);
    num[2].erase(num[2].begin(), num[2].begin() + len);
    int cnt = sz(num[3]);
    num[3].clear();
    vector<int> now = sz(num[1]) < sz(num[2]) ? num[2] : num[1];
    now.insert(now.begin(), 0);
    num[0].insert(num[0].begin(), 0);
    for(int i = 1; i < sz(now); i++) now[i] += now[i - 1];
    for(int i = 1; i < sz(num[0]); i++) num[0][i] += num[0][i - 1];
    int ans = 0;
    for(int i = 0; i < sz(num[0]) && i <= cnt; i++) {
        if(cnt - i < sz(now)) ans = max(ans, sum + num[0][i] + now[cnt - i]);
        else ans = max(ans, sum + num[0][i] + now.back());
    }
    printf("%d\n", ans);
    return 0;
}