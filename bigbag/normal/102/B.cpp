#include <map>
#include <set>
#include <stack>
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

string s;
int n;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> s;
    if (s.length() == 1) {
        cout << 0 << endl;
        return 0;
    }
    for (int i = 0; i < s.length(); ++i) {
        n += s[i] - '0';
    }
    int ans = 1;
    while (n >= 10) {
        int x = 0;
        while (n) {
            x += n % 10;
            n /= 10;
        }
        n = x;
        ++ans;
    }
    cout << ans << endl;
    return 0;
}