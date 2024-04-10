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

const int max_n = 303333, inf = 1011111111;

int n, x, num, ans;
char s[10];
set<int> q;
vector<int> v;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < 2 * n; ++i) {
        scanf("\n%s", s);
        if (s[0] == 'a') {
            scanf("%d", &x);
            v.push_back(x);
        } else {
            int mn = inf;
            ++num;
            if (v.size()) {
                x = v.back();
            } else {
                x = *q.begin();
            }
            if (x == num) {
                if (v.size()) {
                    v.pop_back();
                } else {
                    q.erase(x);
                }
            } else {
                while (v.size()) {
                    q.insert(v.back());
                    v.pop_back();
                }
                ++ans;
                q.erase(*q.begin());
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}