#include <bits/stdc++.h>
using namespace std;


#define sz(c) (int)(c).size()
#define all(c) (c).begin(), (c).end()
int m;
int a, b, c;
vector<int> v[2];


int main() {
    ios_base::sync_with_stdio(false);
    cin >> a >> b >> c;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int val;
        string t;
        cin >> val >> t;
        if (t == "USB") {
            v[0].push_back(val);
        } else {
            v[1].push_back(val);
        }
    }
    sort(all(v[0]));
    reverse(all(v[0]));
    sort(all(v[1]));
    reverse(all(v[1]));
    long long sum = 0LL;
    int cnt = 0;
    while (sz(v[0]) > 0 && a > 0) {
        a--;
        cnt++;
        sum += v[0].back();
        v[0].pop_back();
    }
    while (sz(v[1]) > 0 && b > 0) {
        b--;
        cnt++;
        sum += v[1].back();
        v[1].pop_back();
    }
    multiset<int> s;
    for (auto x: v[0]) {
        s.insert(x);
    }
    for (auto x: v[1]) {
        s.insert(x);
    }
    while (!s.empty() && c > 0) {
        cnt++;
        c--;
        int d = *s.begin();
        s.erase(s.find(d));
        sum += d;
    }
    cout << cnt << ' ' << sum << endl;
    return 0;   
}