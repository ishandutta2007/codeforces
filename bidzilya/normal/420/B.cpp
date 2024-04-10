#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <queue>
   
#include <cassert>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <bitset>
using namespace std;

typedef long long ll;

const int max_m = 1e5;

int n, m;
vector<vector<int> > g;
pair<char, int> a[max_m];
int s[max_m];
vector<int> ans;
int us[max_m];
int bad[max_m];
int sbad[max_m];

int get_sbad(int l, int r)
{
    if (l > r) return 0;
    if (l == 0) return sbad[r];
    return sbad[r] - sbad[l - 1];
}

bool good_agent(const vector<int>& pos)
{
    if (pos.empty()) return true;
    vector<pair<int, int> > t;
    int i = 0;
    if (a[pos[i]].first == '-') {
        t.push_back(make_pair(-1, pos[i]));
        ++i;
    }
    while (i + 1 < (int) pos.size()) {
        t.push_back(make_pair(pos[i], pos[i + 1]));
        i += 2;
    }
    if (i < (int) pos.size() && a[pos[i]].first == '+') {
        t.push_back(make_pair(pos[i], m));
    }
    if (t[0].first != 0 && t[0].first != -1) return false;
    if (t.back().second != m && t.back().second != m - 1) return false;
    for (int i = 1; i < (int) t.size(); ++i)
        if (t[i].first - 1 != t[i - 1].second)
            return false;
    for (int i = 1; i < (int) t.size(); ++i)
        if (get_sbad(t[i].first + 1, t[i].second - 1) > 0)
            return false;
    if (t[0].first != -1) {
        if (get_sbad(t[0].first + 1, t[0].second - 1) > 0)
            return false;
    }
    for (int i = 0; i + 1 < (int) t.size(); ++i)
        if (s[t[i].second] > 0) 
            return false;
    if (t.back().second != m) {
        if (s[t.back().second] > 0)
            return false;
    }
    return true;
}

int main()
{
 //   freopen("input.txt", "r", stdin);
  //  freopen("output.txt", "w", stdout);
    
    scanf("%d%d\n", &n, &m);
    g.resize(n);
    for (int i = 0; i < m; ++i) {
        scanf("%c %d\n", &a[i].first, &a[i].second);
        --a[i].second;
        g[a[i].second].push_back(i);
    }
    s[0] = 0;
    if (a[0].first == '+') {
        ++s[0];
        us[a[0].second] = 1;
    } else {
        bad[0] = 1;
    }
    
    for (int i = 1; i < m; ++i) {
        s[i] = s[i - 1];
        if (a[i].first == '+') {
            us[a[i].second] = 1;
            ++s[i];
        } else {
            if (us[a[i].second]) {
                --s[i];
                us[a[i].second] = 0;
            } else {
                bad[i] = 1;
            }
        }
    }
    
    sbad[0] = bad[0];
    for (int i = 1; i < m; ++i) 
        sbad[i] = sbad[i - 1] + bad[i];
        
    for (int i = 0; i < n; ++i)
        if (good_agent(g[i])) {
            ans.push_back(i + 1);
        }
    
    printf("%d\n", (int) ans.size());
    for (int i = 0; i < (int) ans.size(); ++i)
        printf("%d ", ans[i]);
    printf("\n");
    
    return 0;
}