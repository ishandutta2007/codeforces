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

int ans;
string s;
set<string> q;

string pow1(string s) {
    string res = s;
    res[0] = s[3];
    res[1] = s[0];
    res[2] = s[1];
    res[3] = s[2];
    return res;
}

string pow2(string s) {
    string res = s;
    res[3] = s[4];
    res[5] = s[3];
    res[1] = s[5];
    res[4] = s[1];
    return res;
}

string pow3(string s) {
    string res = s;
    res[5] = s[2];
    res[2] = s[4];
    res[4] = s[0];
    res[0] = s[5];
    return res;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> s;
    sort(s.begin(), s.end());
    do {
        q.insert(s);
    } while (next_permutation(s.begin(), s.end()));
    while (!q.empty()) {
        ++ans;
        string a = *q.begin();
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                for (int k = 0; k < 4; ++k) {
                    q.erase(a);
                    //cout << a << endl;
                    a = pow1(a);
                }
                a = pow2(a);
            }
            a = pow3(a);
        }
    }
    cout << ans << endl;
    return 0;
}