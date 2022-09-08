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

const int max_n = 333333, inf = 1111111111;

int n, m, ans;
char s[max_n];
set<pair<int, int> > q;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d%s", &n, &m, s);
    for (int i = 0; i < n; ++i) {
        int poz = i;
        while (i < n && s[i] == '.') {
            ++i;
        }
        if (poz <= i - 1) {
            q.insert(make_pair(poz, i - 1));
            ans += i - poz - 1;
        }
    }
    q.insert(make_pair(-2, -2));
    q.insert(make_pair(n + 1, n + 1));
    while (m--) {
        int poz;
        char c;
        scanf("%d%c%c", &poz, &c, &c);
        --poz;
        pair<int, int> p1 = *(--q.upper_bound(make_pair(poz, inf)));
        pair<int, int> p2 = *(q.upper_bound(make_pair(poz, inf)));
        if (s[poz] == '.' && c != '.') {
            ans -= (p1.second - p1.first);
            //cout << p1.first << "   " << p1.second << endl;
            q.erase(p1);
            if (p1.first <= poz - 1) {
                q.insert(make_pair(p1.first, poz - 1));
                ans += poz - 1 - p1.first;
            }
            if (poz + 1 <= p1.second) {
                q.insert(make_pair(poz + 1, p1.second));
                ans += p1.second - poz - 1;
            }
        }
        if (s[poz] != '.' && c == '.') {
            int l = poz;
            int r = poz;
            if (p1.second + 1 == poz) {
                ans -= (p1.second - p1.first);
                q.erase(p1);
                l = p1.first;
            }
            if (poz + 1 == p2.first) {
                ans -= (p2.second - p2.first);
                q.erase(p2);
                r = p2.second;
            }
            //cout << "!"  << l << " " << r << endl;
            q.insert(make_pair(l, r));
            ans += r - l;
        }
        s[poz] = c;
        /*for (set<pair<int, int> > ::iterator it = q.begin(); it != q.end(); ++it) {
            pair<int, int> p = *it;
            printf("[%d %d] ", p.first, p.second);
        }*/
        printf("%d\n", ans);
    }
    return 0;
}