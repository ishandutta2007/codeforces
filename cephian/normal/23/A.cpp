#include <iostream>
#include <map>
#include <algorithm>

using namespace std;
typedef long long ll;

map<string, int> m;

int main() {
    string s;
    cin >> s;
    for(int i = 0; i < s.size(); ++i)
        for(int j = 0; i+j <= s.size(); ++j)
            ++m[s.substr(i, j)];
    int ans = 0;
    for(auto k : m)
        if(k.second > 1) ans = max(ans, (int)k.first.size());
    cout << ans << '\n';
    return 0;
}