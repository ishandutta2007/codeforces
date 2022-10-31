#include <iostream>
#include <algorithm>
#include <map>
#include <cmath>

using namespace std;
typedef long long ll;

int a;
string s;
map<int, int> m;

int main() {
    cin >> a >> s;
    for(int i = 0; i < s.size(); ++i) {
        int sum = 0;
        for(int j = i; j < s.size(); ++j) {
            sum += s[j]-'0';
            ++m[sum];
        }
    }
    if(a == 0) {
        cout << ll(m[0])*ll(s.size())*ll(s.size()+1) - ll(m[0])*m[0] << "\n";
        return 0;
    }
    
    int sq = sqrt(a);
    ll ans = 0;
    for(int b = 1; b <= sq; ++b) {
        if(a % b == 0)
            ans += ll(m[b]) * ll(m[a/b]) * ((b == a/b)?1:2);
    }
    cout << ans << "\n";
}