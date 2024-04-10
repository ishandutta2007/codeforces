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

int n;
set<string> q;
string s;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    while (n--) {
        cin >> s;
        if (q.count(s)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
        q.insert(s);
    }
    return 0;
}