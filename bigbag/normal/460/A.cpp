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
    int i;
    for (i = 1; n; ++i) {
        --n;
        if (i % m == 0) ++n;
        //cout << i << " " << n << endl;
    }
    cout << i - 1 << endl;
    return 0;
}