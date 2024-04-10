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

int n, x;
set<int> q;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    while (n--) {
        scanf("%d", &x);
        while (x % 2 == 0) {
            x /= 2;
        }
        while (x % 3 == 0) {
            x /= 3;
        }
        q.insert(x);
    }
    if (q.size() == 1) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }
    return 0;
}