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

const int max_n = 55, inf = 1111111111;

int n, u[max_n], v[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    for (int i = 0; i < n * n; ++i) {
        int a, b;
        cin >> a >> b;
        if (u[a] + v[b] == 0) {
            cout << i + 1 << " ";
            u[a] = v[b] = 1;
        }
    }
    cout << endl;
    return 0;
}