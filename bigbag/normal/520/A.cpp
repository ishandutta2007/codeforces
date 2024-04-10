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

int n;
string s;
set<char> q;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> s;
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] <= 'Z') {
            s[i] = s[i] - 'A' + 'a';
        }
        q.insert(s[i]);
    }
    if (q.size() == 26) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}