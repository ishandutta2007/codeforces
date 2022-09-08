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

long long used[255];
string s;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> s;
    for (int i = 0; i < s.length(); ++i) {
        ++used[s[i]];
    }
    long long ans = 0;
    for (int i = 0; i < 255; ++i) {
        ans += used[i] * used[i];
    }
    cout << ans << endl;
    return 0;
}