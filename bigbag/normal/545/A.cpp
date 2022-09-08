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

int n, a;
set<int> q;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        q.insert(i);
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> a;
            if (a <= 0) {
                continue;
            }
            if (a == 1) {
                q.erase(i);
            } else if (a == 2) {
                q.erase(j);
            } else {
                q.erase(i);
                q.erase(j);
            }
        }
    }
    cout << q.size() << endl;
    while (q.size()) {
        a = *q.begin();
        cout << a << " ";
        q.erase(a);
    }
    return 0;
}