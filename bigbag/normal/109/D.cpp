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

bool ok(int x) {
    while (x) {
        if (x % 10 != 4 && x % 10 != 7) {
            return false;
        }
        x /= 10;
    }
    return true;
}

int n, poz = -1, a[max_n];
set<pair<int, int> > q;
vector<pair<int, int> > ans;

void my_swap(int p) {
    ans.push_back(make_pair(poz, p));
    q.erase(make_pair(a[p], p));
    q.erase(make_pair(a[poz], poz));
    swap(a[p], a[poz]);
    q.insert(make_pair(a[p], p));
    q.insert(make_pair(a[poz], poz));
    swap(p, poz);
}

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("input.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        q.insert(make_pair(a[i], i));
        if (ok(a[i])) {
            poz = i;
        }
    }
    /*cout << n << endl;
    for (int i = 0; i < n; ++i) {
        cout << a[i] << " ";
    }
    cout << endl;*/
    if (poz == -1) {
        for (int i = 0; i + 1 < n; ++i) {
            if (a[i] > a[i + 1]) {
                printf("-1\n");
                return 0;
            }
        }
        printf("0\n");
        return 0;
    }
    int fff = 0;
    for (int i = 0; i < n; ++i) {
        if (poz != i) {
            my_swap(i);
            //cout << i << endl;
        }
        pair<int, int> p = *q.begin();
        if (p.second == poz) {
            if (fff == 0) {
                fff = 1;
                continue;
            }
            if (q.size() == 1) {
                continue;
            }
            p = *(++q.begin());
        }
        //cout << i << " " << p.first << " " << p.second << endl;
        if (poz != p.second) {
            my_swap(p.second);
            //cout << i << endl;
        }
        if (poz != i) {
            q.erase(make_pair(a[i], i));
        }
    }
    printf("%d\n", ans.size());
    for (int i = 0; i < ans.size(); ++i) {
        printf("%d %d\n", ans[i].first + 1, ans[i].second + 1);
    }
    return 0;
}