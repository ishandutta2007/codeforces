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

int get_sum(int x) {
    int res = 0;
    while (x) {
        res += x % 10;
        x /= 10;
    }
    return res;
}

vector<int> v;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = max(n - 11111, 0); i < n + 11111; ++i) {
        if (i + get_sum(i) == n) {
            v.push_back(i);
        }
    }
    printf("%d\n", v.size());
    for (int i = 0; i < v.size(); ++i) {
        printf("%d ", v[i]);
    }
    printf("\n");
    return 0;
}