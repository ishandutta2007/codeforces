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

int n, m;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> m;
    for (int cnt = n / 2; cnt >= 0; --cnt) {
        int x = n - cnt * 2;
        if ((x + cnt) % m == 0) {
            cout << x + cnt << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}