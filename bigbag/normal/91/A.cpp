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

const int max_n = 1111111, inf = 1111111111;

int u1[33], u2[33];
string s1, s2;
vector<int> pozs[33];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> s1 >> s2;
    for (int i = 0; i < s1.length(); ++i) {
        u1[s1[i] - 'a'] = 1;
    }
    for (int i = 0; i < s2.length(); ++i) {
        u2[s2[i] - 'a'] = 1;
    }
    for (int i = 0; i < 33; ++i) {
        if (u2[i] == 1 && u1[i] == 0) {
            cout << -1 << endl;
            return 0;
        }
    }
    for (int i = 0; i < s1.length(); ++i) {
        pozs[s1[i] - 'a'].push_back(i);
    }
    int ans = 1, poz = -1;
    for (int i = 0; i < s2.length(); ++i) {
        vector<int>::iterator it = upper_bound(pozs[s2[i] - 'a'].begin(), pozs[s2[i] - 'a'].end(), poz);
        if (it == pozs[s2[i] - 'a'].end()) {
            ++ans;
            poz = -1;
            --i;
        } else {
            poz = *it;
        }
    }
    cout << ans << endl;
    return 0;
}