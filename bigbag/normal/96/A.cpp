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

char last;
string s;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> s;
    last = s[0];
    int cnt = 1;
    for (int i = 1; i < s.length(); ++i) {
        if (s[i] == last) {
            ++cnt;
        } else {
            last = s[i];
            cnt = 1;
        }
        if (cnt >= 7) {
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
    return 0;
}