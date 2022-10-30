#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int min(int a, int b) {
    if (a < b)
        return a;
    return b;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    vector<int> vals;
    for (int i = 0; i < n; ++i) {
        int tmp;
        scanf("%d", &tmp);
        vals.push_back(tmp);
    }
    sort(vals.begin(), vals.end());
    if (k >= n) {
        printf("%d", 2 * (vals[n - 1] - 1));
        fflush(stdout);
        return 0;
    }

    int cur = n - k;
    int cost = 0;
    while (cur + k - 1 >= 0) {
        cost += 2 * (vals[cur + k - 1] - 1);
        cur -= k;
    }
    printf("%d", cost);
    fflush(stdout);
}