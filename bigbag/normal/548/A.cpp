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

int k;
string s;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> s >> k;
    if (s.length() % k) {
        cout << "NO" << endl;
        return 0;
    }
    k = s.length() / k;
    for (int i = 0; i < s.length(); i += k) {
        for (int j = 0; j < k; ++j) {
            if (s[i + j] != s[i + k - j - 1]) {
                cout << "NO" << endl;
                return 0;
            }
        }
    }
    cout << "YES" << endl;
    return 0;
}