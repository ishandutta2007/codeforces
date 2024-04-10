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

const int max_n = 111, inf = 111111111;

int n, max_sum, a, b;
string ans;
int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    max_sum = -inf;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s >> a >> b;
        int sum = 100 * a - 50 * b;
        for (int j = 0; j < 5; ++j) {
            int x;
            cin >> x;
            sum += x;
        }
        if (max_sum < sum) {
            max_sum = sum;
            ans = s;
        }
        //cout << sum << endl;
    }
    cout << ans << endl;
    return 0;
}