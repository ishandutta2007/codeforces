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

const int max_n = 111111, inf = 1011111111;

int n, a[max_n], mx[max_n];
set<int> q, w;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        q.insert(a[i]);
    }
    for (int i = 0; i < n; ++i) {
        w.insert(a[i]);
        while (w.size()) {
            int mx = *w.rbegin();
            if (mx >= *q.rbegin()) {
                printf("%d ", mx);
                q.erase(mx);
                w.erase(mx);
            } else {
                break;
            }
        }
        printf("\n");
    }
    return 0;
}