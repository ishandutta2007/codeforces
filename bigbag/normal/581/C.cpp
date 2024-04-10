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

const int max_n = 111111, inf = 1111111111;

int n, k, x, ans, sum;
vector<int> v;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &k);
    while (n--) {
        scanf("%d", &x);
        sum += 10 - x / 10;
        if (x % 10) {
            v.push_back(10 - x % 10);
            --sum;
        }
        ans += x / 10;
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); ++i) {
        if (k >= v[i]) {
            ++ans;
            k -= v[i];
        } else {
            break;
        }
    }
    cout << ans + min(sum, k / 10) << endl;
    return 0;
}