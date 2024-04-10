#pragma GCC optimize("Ofast")
#pragma GCC target("avx2")
#include <iostream>
#include <vector>
#include <string>
using namespace std;
 
 
string s;
int n;
int p[200005];
vector<int> v[200005];
int used[200005];
long long ans;
 
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> s;
    n = s.size();
    s = "#" + s;
    for (int i = 1; i <= n; ++i) {
        p[i] = p[i - 1] + (s[i] - '0');
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = i; j <= n; j += i) {
            v[j].push_back(i);
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int x : v[i])
            used[x] = 1;
        for (int j = i; j <= n; ++j)
            ans += used[p[j] - p[j - i]];
        for (int x : v[i])
            used[x] = 0;
    }
    cout << ans << '\n';
    return 0;
} // nice