#include <bits/stdc++.h>
using namespace std;

const int N = 220000;

set< pair<int, int> > S;

int a[N], prv[N], nxt[N];
char s[N];

int main() {
    int n; scanf("%i%s", &n, s + 1);
    for (int i = 1; i <= n; i++) scanf("%i", &a[i]);
    for (int i = 1; i <= n; i++) prv[i] = i-1, nxt[i] = i+1;
    for (int i = 1; i < n; i++) {
        if (s[i] != s[i+1]) S.insert(make_pair(abs(a[i+1] - a[i]), i));
    }
    vector<pair<int, int> > ans;
    while (!S.empty()) {
        auto it = S.begin();
        int i = it->second, j = nxt[i];
        int l = prv[i], r = nxt[j];
        if (l > 0 && s[l] != s[i]) S.erase(make_pair(abs(a[l] - a[i]), l));
        if (r <= n && s[r] != s[j]) S.erase(make_pair(abs(a[r] - a[j]), j));
        if (l > 0 && r <= n && s[l] != s[r]) S.insert(make_pair(abs(a[r] - a[l]), l));
        if (l > 0) nxt[l] = r;
        if (r <= n) prv[r] = l;
        ans.push_back(make_pair(i, j));
        S.erase(it);
    }
    cout << ans.size() << endl;
    for (auto p : ans) printf("%d %d\n", p.first, p.second);
    return 0;
}