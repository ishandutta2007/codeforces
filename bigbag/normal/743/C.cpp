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

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    if (n == 1) {
        cout << -1 << endl;
        return 0;
    }
    cout << n << " " << n + 1 << " " << n * (n + 1) << endl;
    return 0;
}