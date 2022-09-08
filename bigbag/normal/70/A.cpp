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

const int max_n = 1111, inf = 111111111;

int n;

int get_ans(int n) {
    if (n == 1) {
        return 1;
    }
    return 3 * get_ans(n / 2);
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    int res = 1;
    for (int i = 1; i < n; ++i) {
        res = (res *3) % 1000003;
    }
    cout << res << endl;
    //cout << get_ans((1 << n) - 1) << endl;
    return 0;
}