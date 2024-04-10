#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <string>

#include <cmath>
#include <cstdio>
using namespace std;

typedef long long ll;

string s;
int ans, p;

int main() {
    ios_base::sync_with_stdio(false);
  // freopen("input.txt", "r", stdin);
  //  freopen("output.txt", "w", stdout);
    getline(cin, s);
    ans = 1;
    p = s.length();
    while (true) {
        --p;
        if (p < 0) break;
        int prev_p = p;
        while (s[p] == '0') --p;
        int l1 = p, l2 = prev_p - p + 1;
        bool good = false;
        if (l1 > l2) {
            good = true;
        } else if (l1 == l2) {
            good = true;
            for (int i = 0; i < l1; ++i)
                if (s[i] > s[p + i]) {
                    break;
                } else if (s[i] < s[p + i]) {
                    good = false;
                    break;
                }
        }
        if (!good) break;
        ++ans;
    }
    cout << ans << endl;
    return 0;
}