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

const int max_n = 11, inf = 1111111111;

int n;
map<string, int> ans;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    for (int i = 1989; i <= 13098; ++i) {
        string q;
        int x = i;
        while (x) {
            q += x % 10 + '0';
            x /= 10;
        }
        reverse(q.begin(), q.end());
        for (int j = 1; j <= q.length(); ++j) {
            string w = q.substr(q.length() - j);
            if (!ans.count(w)) {
                ans[w] = i;
                break;
            }
        }
    }
    cin >> n;
    while (n--) {
        string q;
        cin >> q;
        q = q.substr(4);
        if (ans.count(q)) {
            cout << ans[q] << endl;
        } else {
            int pw = 10000, x = 3098;
            for (int i = 4; i < q.length(); ++i) {
                x += pw;
                pw *= 10;
            }
            int qq = 0;
            for (int i = 0; i < q.length(); ++i) {
                qq = qq * 10 + q[i] - '0';
            }
            if (qq <= x) {
                cout << 1 << q << endl;
            } else {
                cout << q << endl;
            }
        }
    }
    return 0;
}