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

const int max_n = 1, inf = 1111111111;

int k, r;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> k >> r;
    for (int i = 1; ; ++i) {
        if ((i * k) % 10 == 0 || (i * k) % 10 == r) {
            cout << i << endl;
            return 0;
        }
    }
    return 0;
}