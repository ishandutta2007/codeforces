#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int const maxn = 1e6 + 5;
int a[maxn];
int prime[maxn];
int L[maxn];
vector < int > pos[maxn];

inline void add(int x, int l) {
    L[l] = l;
    while (x > 1) {
        pos[prime[x]].push_back(l);
        x /= prime[x];
    }
}

inline void del(int x, int l) {
    if (x == 1) {
        L[l] = l;
        return;
    }
    L[l] = l;
    while (x > 1) {
        if ((int)pos[prime[x]].size() == 0) {
            L[l] = 0;
            return;
        }
        L[l] = min(L[l], pos[prime[x]].back());
        pos[prime[x]].pop_back();
        x /= prime[x];
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];

    for (int i = 2; i < maxn; ++i) {
        if (prime[i] == 0) {
            prime[i] = i;
            if (i > 1000) continue;
            for (int j = i * i; j < maxn; j += i) {
                prime[j] = i;
            }
        }
    }

    char type;
    for (int i = 1; i <= n; ++i) {
        cin >> type;
        if (type == '*') add(a[i], i);
        else del(a[i], i);
    }

    ll answer = 0;
    vector < pair < int, int > > f_min;
    for (int i = n; i >= 1; --i) {
        int cnt = 1;
        while ((int)f_min.size() > 0 && f_min.back().first >= L[i]) {
            cnt += f_min.back().second;
            f_min.pop_back();
        }
        f_min.push_back({L[i], cnt});
        if (L[i] == i) answer += (ll)cnt;
    }
    cout << answer << '\n';
    return 0;
}