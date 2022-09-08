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

int n;
pair<int, int> p[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &p[i].first, &p[i].second);
    }
    sort(p, p + n);
    int mx = p[n - 1].second;
    for (int i = n - 2; i >= 0; --i) {
        if (p[i].second > mx) {
            printf("Happy Alex\n");
            return 0;
        }
        mx = p[i].second;
    }
    printf("Poor Alex\n");
    return 0;
}