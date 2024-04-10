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

int n, cnt[max_n], sum[max_n];
multiset<pair<int, int> > s;
vector<int> v[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    int x = 0, ans = 0;
    for (int i = 0; i < n; ++i) {
        int a, b;
        scanf("%d%d", &a, &b);
        if (a == 0) {
            ++x;
        } else {
            ans += b;
            s.insert(make_pair(b, a));
        }
    }
    int xx = ans;
    for (int i = n - 1; i >= x; --i) {
        int q = cnt[i] + 1;
        xx += sum[i];
        //cout << i << "  " << q << " " << xx << endl;
        while (q != 0 && s.size()) {
            pair<int, int> p = *s.rbegin();
            s.erase(s.find(p));
            if (v[p.second].size() + 1 < i) {
                xx -= p.first;
                --q;
                v[p.second].push_back(p.first);
                ++cnt[v[p.second].size()];
                sum[v[p.second].size()] += p.first;
            }
        }
        if (s.size() == 0) {
            if (q == 0) {
                //cout << i << " " << xx << endl;
                ans = min(ans, xx);
            }
            break;
        }
        //cout << i << " " << xx << endl;
        ans = min(ans, xx);
    }
    printf("%d\n", ans);
    return 0;
}