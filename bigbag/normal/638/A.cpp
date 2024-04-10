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

int n, a;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> a;
    if (a % 2 == 1) {
        ++a;
    } else {
        a = n - a + 2;
    }
    cout << a / 2 << endl;
    return 0;
}