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

int n, m, k;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> m >> k;
    for (int i = n; i >= 1; --i) {
        int l = (i - 1) * 2 * m + 1;
        int r = i * 2 * m;
        //cout << i << " " << l << " " << r << endl;
        if (k >= l) {
            k -= l;
            cout << i << " " << k / 2 + 1 << " ";
            if (k % 2 == 0) {
                cout << "L" << endl;
            } else {
                cout << "R" << endl;
            }
            return 0;
        }
    }
    return 0;
}