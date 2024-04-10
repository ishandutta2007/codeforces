#include "list"
#include <iostream>
#include <vector>
#include <fstream>
#include <map>
#include "algorithm"
#include <iomanip>
#include "cmath"
#include "set"
#include <climits>
#define int long long
using namespace std;

void PolnalyubviTop(){
    int n, p, k;
    cin >> n >> p >> k;
    string s;
    cin >> s;
    p--;
    int x, y;
    cin >> x >> y;
    vector<int> modk(k, 0);
    for (int i = p; i < n; ++i) {
        if(s[i] == '0')
            modk[i%k] += 1;
    }
    int ans = x * n;
    int pref = 0;
    for (int i = p; i < n; ++i) {
        ans = min(ans, pref + modk[i%k] * x);
        pref += y;
        if(s[i] == '0')
            modk[i%k]--;
    }
    cout << ans << endl;
}


signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        PolnalyubviTop();
    }
}