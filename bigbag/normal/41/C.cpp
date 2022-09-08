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

string s, ans;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> s;
    string kk = s;
    ans = s;
    int l = s.length();
    for (int i = 1; i + 2 < l; ++i) {
        if (s[i] == 'a' && s[i + 1] == 't') {
            s.erase(i, 2);
            s.insert(i, "@");
            string k;
            k += s[0];
            //cout << s << endl;
            int j = 1;
            for (j = 1; j + 3 < l - 1; ++j) {
                if (s[j] == 'd' && s[j + 1] == 'o' && s[j + 2] == 't') {
                    k = k + '.';
                    j += 2;
                } else {
                    k = k + s[j];
                }
            }
            while (j < l - 1) {
                k = k + s[j];
                ++j;
            }
            //cout << k << endl;
            ans = min(ans, k);
            s = kk;
        }
    }
    cout << ans << endl;
    return 0;
}