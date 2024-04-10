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

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> s;
    for (int l = 0; l < s.length(); ++l) {
        for (int r = l; r < s.length(); ++r) {
            string q = s.substr(0, l) + s.substr(r + 1, s.length() - r - 1);
            if (q == "CODEFORCES") {
                cout << "YES" << endl;
                return 0;
            }
        }
    }
    cout << "NO" << endl;
    return 0;
}