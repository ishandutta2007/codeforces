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

const int max_n = 44444, inf = 111111111;

int n, m, k, t;
vector<int> v;

int fun(int x, int y) {
    return (x - 1) * m + y;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d%d%d", &n, &m, &k, &t);
    for (int i = 0; i < k; ++i) {
        int x, y;
        scanf("%d%d", &x, &y);
        v.push_back(fun(x, y));
    }
    sort(v.begin(), v.end());
    while (t--) {
        int x, y;
        scanf("%d%d", &x, &y);
        int q = fun(x, y);
        vector<int>::iterator it = lower_bound(v.begin(), v.end(), q);
        if (it != v.end()) {
            if (*it == q) {
                printf("Waste\n");
            } else {
                --it;
                int cnt = it - v.begin() + 1;
                int f = q - cnt;
                //cout << "        " << cnt <<  ' ' << y << "   " << f << endl;
                if (f % 3 == 1) {
                    printf("Carrots\n");
                }
                if (f % 3 == 2) {
                    printf("Kiwis\n");
                }
                if (f % 3 == 0) {
                    printf("Grapes\n");
                }
            }
        } else {
            int cnt = v.size();
            int f = q - cnt;
            if (f % 3 == 1) {
                printf("Carrots\n");
            }
            if (f % 3 == 2) {
                printf("Kiwis\n");
            }
            if (f % 3 == 0) {
                printf("Grapes\n");
            }
        }
    }
    return 0;
}