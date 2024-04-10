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

long long a, b, ans;

int main() {
    cin >> a >> b;
    while (a) {
        ans += b / a;
        b %= a;
        swap(a, b);
    }
    cout << ans << endl;
    return 0;
}