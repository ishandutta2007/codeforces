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

const int max_n = 111111, inf = 111111111;

int n, m, a[max_n], b[max_n];
string s[max_n], name;
map<string, int> f;
multiset<int> q;
vector<pair<int, string> > v;

bool cmp(pair<int, string> a, pair<int, string> b) {
    return a.first > b.first || a.first == b.first && a.second < b.second;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> s[i] >> a[i];
        f[s[i]] = a[i];
    }
    cin >> m;
    for (int i = 0; i < m; ++i) {
        cin >> b[i];
        q.insert(b[i]);
    }
    for (int i = m; i < n; ++i) {
        q.insert(0);
    }
    cin >> name;
    for (int i = 0; i < n; ++i) {
        if (s[i] != name) {
            v.push_back(make_pair(a[i], s[i]));
        }
    }
    sort(v.begin(), v.end(), cmp);
    multiset<int> qk = q;
    int minx = *q.begin();
    int ans2 = 1, x = f[name] + minx;
    q.erase(q.find(minx));
    //cout << x << endl;
    for (int i = 0; i < v.size(); ++i) {
        if (v[i].second < name) {
            int o = x - v[i].first;
            if (o <= *q.rbegin()) {
                ++ans2;
                set<int>::iterator it = q.lower_bound(o);
                //cout << v[i].second << ' ' << v[i].first << "  _!  " << *it << endl;
                q.erase(it);
            } else {
                break;
            }
        } else {
            int o = x - v[i].first;
            if (o < *q.rbegin()) {
                ++ans2;
                set<int>::iterator it = q.upper_bound(o);
                //cout << v[i].second << ' ' << v[i].first << "  _  " << *it << endl;
                q.erase(it);
            } else {
                break;
            }
        }
    }
    //cout << "!" << ans2 << endl;
    q = qk;
    int maxx = *q.rbegin();
    int ans1 = n;
    x = f[name] + maxx;
    q.erase(q.find(maxx));
    for (int i = 0; i < v.size(); ++i) {
        if (v[i].second < name) {
            int o = x - v[i].first;
            if (o > *q.begin()) {
                --ans1;
                set<int>::iterator it = q.lower_bound(o);
                --it;
                //cout << v[i].second << ' ' << v[i].first << "  _!  " << *it << endl;
                q.erase(it);
            } else {
                q.erase(q.find(*q.rbegin()));
            }
        } else {
            int o = x - v[i].first;
            if (o >= *q.begin()) {
                --ans1;
                set<int>::iterator it = q.upper_bound(o);
                --it;
                //cout << v[i].second << ' ' << v[i].first << "  _  " << *it << endl;
                q.erase(it);
            } else {
                q.erase(q.find(*q.rbegin()));
            }
        }
    }
    cout << ans1 << ' ' << ans2 << endl;
    return 0;
}