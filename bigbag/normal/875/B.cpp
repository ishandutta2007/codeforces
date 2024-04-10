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

int n, x;
set<int> q;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i <= n; ++i) {
        q.insert(i);
    }
    printf("1 ");
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &x);
        q.erase(x);
        int c = n - *q.rbegin();
        printf("%d ", i - c + 1);
    }
    printf("\n");
    return 0;
}