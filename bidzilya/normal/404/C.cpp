#include <cstdio>
#include <cmath>
#include <cstring>
#include <cassert>
#include <cstdlib>
#include <ctime>

#include <algorithm>
#include <iomanip>
#include <iostream>
#include <vector>
#include <set>
#include <map>

using namespace std;

typedef long long ll;

const int max_n = 1e5 + 100;

pair<int, int> a[max_n];
int t[max_n];
int n, k;

vector<pair<int, int> > ans;

int main() {
   // freopen("input.txt", "r", stdin);
  //  freopen("output.txt", "w", stdout);
    
    while (scanf("%d%d", &n, &k) != EOF) {
        for (int i = 0; i < n; ++i) {
            scanf("%d", &a[i].first);
            a[i].second = i;
        }
        sort(a, a + n);
        
        if (a[0].first != 0) {
            printf("-1\n");
            continue;
        }
        if (a[1].first == 0) {
            printf("-1\n");
            continue;
        }
        for (int i = 1; i < n; ++i) {
            t[i] = k - 1;
        }
        t[0] = k;
        ans.clear();
        bool good = true;
        for (int y1 = 0, y2 = 1; y2 < n; ) {
            if (y1 >= y2) {
                good = false;
                break;
            }
            if (t[y1] == 0 || a[y1].first + 1 != a[y2].first) {
                ++y1;
                continue;
            }
            ans.push_back(make_pair(a[y1].second, a[y2].second));
            ++y2;
            --t[y1];
        }
        if (!good) {
            printf("-1\n");
            continue;
        }
        printf("%d\n", (int) ans.size());
        for (int i = 0; i < (int) ans.size(); ++i)
            printf("%d %d\n", ans[i].first + 1, ans[i].second + 1);
    }

    return 0;
}