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

int n, a;
long long ans;
vector<int> v;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    while (n--) {
        scanf("%d", &a);
        if (a % 2 == 0) {
            ans += a;
        } else {
            v.push_back(a);
        }
    }
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    if (v.size() % 2) {
        v.pop_back();
    }
    for (int i = 0; i < v.size(); ++i) {
        ans += v[i];
    }
    cout << ans << endl;
    return 0;
}