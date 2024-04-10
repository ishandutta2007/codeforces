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

const int max_n = 1111, inf = 1111111111;
const char a[] = {'B', 'G', 'R'};

int n;
string s;
set<char> q;
vector<char> ans;
multiset<char> q2;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> s;
    for (int i = 0; i < n; ++i) {
        q.insert(s[i]);
        q2.insert(s[i]);
    }
    if (q.size() == 3) {
        cout << "BGR" << endl;
    } else if (q.size() == 1) {
        cout << s[0] << endl;
    } else {
        if (n == 2) {
            for (int i = 0; i < 3; ++i) {
                if (!q.count(a[i])) {
                    cout << a[i] << endl;
                }
            }
        } else {
            char x = *q.begin();
            char y = *q.rbegin();
            if (q2.count(x) > 1 && q2.count(y) > 1) {
                cout << "BGR" << endl;
            } else {
                if (q2.count(x) > 1) {
                    swap(x, y);
                }
                ans.push_back(x);
                for (int i = 0; i < 3; ++i) {
                    if (!q.count(a[i])) {
                        ans.push_back(a[i]);
                    }
                }
                sort(ans.begin(), ans.end());
                cout << ans[0] << ans[1] << endl;
            }
        }
    }
    return 0;
}