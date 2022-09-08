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
vector<string> ans;
int n, p, q;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> p >> q >> s;
    for (int x = 0; x * p <= n; ++x) {
        if ((n - x * p) % q == 0) {
            int y = (n - x * p) / q;
            int poz = 0;
            for (int i = 0; i < x; ++i) {
                ans.push_back(s.substr(poz, p));
                poz += p;
            }
            for (int i = 0; i < y; ++i) {
                ans.push_back(s.substr(poz, q));
                poz += q;
            }
            cout << ans.size() << endl;
            for (int i = 0; i < ans.size(); ++i) {
                cout << ans[i] << endl;
            }
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}