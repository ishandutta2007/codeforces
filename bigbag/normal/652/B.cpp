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

const int max_n = 1111, inf = 1111111111;

int n, x;
multiset<int> q;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &x);
        q.insert(x);
    }
    for (int i = 0; i < n; ++i) {
        if (i % 2 == 0) {
            x = *q.begin();
        } else {
            x = *q.rbegin();
        }
        q.erase(q.find(x));
        printf("%d ", x);
    }
    printf("\n");
    return 0;
}