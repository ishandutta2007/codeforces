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

const int max_n = 1, inf = 1011111111;

int used[2222];
string s, q;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> s;
    for (int i = 0; i < s.length(); ++i) {
        if (used[s[i]] == 0) {
            q += s[i];
            used[s[i]] = 1;
        }
    }
    for (int i = 0; i < q.length(); ++i) {
        if (q[i] != 'a' + i) {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    return 0;
}