#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <vector>
#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

int l;
string s;
vector <int> v;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> s;
    long long ans = 0;
    l = s.length();
    for (int i = 0; i + 3 < l; ++i) {
        if (s[i] == 'b' && s[i + 1] == 'e' && s[i + 2] == 'a' && s[i + 3] == 'r') {
            //ans += (i + 1) * (l - i - 3);
            v.push_back(i);
        }
    }
    int poz = 0;
    for (int i = 0; i < l; ++i) {
        if (poz < v.size() && i > v[poz]) {
            ++poz;
        }
        if (poz < v.size()) {
            ans += (l - v[poz] - 3);
        }
        //cout << i << ' ' << ans << endl;
    }
    cout << ans << endl;
    return 0;
}