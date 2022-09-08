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

int n, f[2][max_n];
string a[2];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> a[0] >> a[1] >> n;
    while (n--) {
        int t, num, q, c;
        char c1, c2;
        cin >> t >> c1 >> num >> c2;
        if (c1 == 'h') {
            q = 0;
        } else {
            q = 1;
        }
        if (c2 == 'y') {
            c = 1;
        } else {
            c = 2;
        }
        if (f[q][num] < 2) {
            f[q][num] += c;
            if (f[q][num] >= 2) {
                cout << a[q] << " " << num << " " << t << endl;
            }
        }
    }
    return 0;
}