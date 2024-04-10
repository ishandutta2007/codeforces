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

int a, b, ans;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> a >> b;
    while (true) {
        if (a > b) {
            swap(a, b);
        }
        if (a <= 0 || (a == 1 && b == 1)) {
            break;
        }
        ++a;
        b -= 2;
        ++ans;
    }
    cout << ans << endl;
    return 0;
}