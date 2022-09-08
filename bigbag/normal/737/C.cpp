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

const int max_n = 222222, inf = 1111111111;

int n, num, ans, a[max_n];
vector<int> all[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &num);
    --num;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        if (i != num) {
            all[a[i]].push_back(i);
        } else {
            if (a[i]) {
                ++ans;
            }
        }
    }
    int last = 0, mx = n - 1;
    for (int i = 1; i < n; ++i) {
        //cout << i << " $ " << last << endl;
        if (all[i].size()) {
            if (last + 1 >= i) {
                all[i].clear();
                last = max(last, i);
            } else {
                //cout << "#" << i << endl;
                while (last + 1 < i && all[0].size()) {
                    all[0].pop_back();
                    ++last;
                    ++ans;
                    //cout << "#" << i << endl;
                }
                while (mx >= i) {
                    while (last + 1 < i && all[mx].size()) {
                        all[mx].pop_back();
                        ++last;
                        ++ans;
                    }
                    if (all[mx].size() == 0) {
                        --mx;
                    }
                    if (last + 1 >= i) {
                        break;
                    }
                }
                if (last + 1 >= i && all[i].size()) {
                    all[i].clear();
                    last = max(last, i);
                }
            }
        }
    }
    ans += all[0].size();
    printf("%d\n", ans);
    return 0;
}