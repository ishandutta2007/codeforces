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

const int max_n = 111, inf = 1111111111;

int n;
map<string, int> m;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    m.clear();
    for (int i = 0; i < n; ++i) {
        string q;
        cin >> q;
        if (q == "typeof") {
            //cout << "                                        ";
            string a;
            cin >> a;
            int cnt1 = 0, cnt2 = 0;
            for (int i = 0; i < a.length() && a[i] == '&'; ++i) {
                ++cnt1;
            }
            for (int i = a.length() - 1; i >= 0 && a[i] == '*'; --i) {
                ++cnt2;
            }
            a.erase(0, cnt1);
            a.erase(a.length() - cnt2, cnt2);
            if (a == "void") {
                if (cnt1 <= cnt2) {
                    cout << a;
                    for (int i = 0; i < cnt2 - cnt1; ++i) {
                        cout << '*';
                    }
                    cout << endl;
                } else {
                    cout << "errtype" << endl;
                }
            } else if (!m.count(a)) {
                cout << "errtype" << endl;
            } else {
                int x = m[a] + cnt2 - cnt1;
                if (m[a] < 0 || x < 0) {
                    cout << "errtype" << endl;
                } else {
                    cout << "void";
                    for (int i = 0; i < x; ++i) {
                        cout << '*';
                    }
                    cout << endl;
                }
            }
        } else {
            string a, b;
            cin >> a >> b;
            int cnt1 = 0, cnt2 = 0;
            for (int i = 0; i < a.length() && a[i] == '&'; ++i) {
                ++cnt1;
            }
            for (int i = a.length() - 1; i >= 0 && a[i] == '*'; --i) {
                ++cnt2;
            }
            //cout << cnt1 << ' ' << cnt2 << endl;
            a.erase(0, cnt1);
            a.erase(a.length() - cnt2, cnt2);
            if (a == "void") {
                m[b] = cnt2 - cnt1;
            } else {
                if (!m.count(a)) {
                    m[b] = -1;
                } else {
                    int x = m[a];
                    if (x >= 0 && x + cnt2 - cnt1 >= 0) {
                        m[b] = x + cnt2 - cnt1;
                    } else {
                        m[b] = -1;
                    }
                }
            }
        }
    }
    return 0;
}