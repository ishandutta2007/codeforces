#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
#define null NULL
#pragma GCC optimize("Ofast")
//!rand ? ????! 
using namespace std;
typedef vector<pair<int, int> > base;

const int INF = 1e9;
const int mx = 300001;
int n, q;
vector<int> a, t[mx];

int count(int l, int r, int val) {
    vector<int>::iterator bg = t[val].begin(), en = t[val].end();
	return upper_bound(bg, en, r) - lower_bound(bg, en, l);
}

struct node {
    vector<base> a;
    node *l, *r;
    node(): a(vector<base> ()), l(null), r(null) {}
};

base best;
vector<int> roll, cnt;
const int maxk = 5;
node* T;

void add(int x) {
    cnt[x]++;
    roll.push_back(x);
    for (int i = 0; i < maxk; ++i) {
        if (best[i].second == x) {
            best.erase(best.begin() + i, best.begin() + i + 1);
            break;
        }
    }
    best.push_back({cnt[x], x});
    sort(best.begin(), best.end());
    if (best.size() > maxk)
        best.erase(best.begin(), best.begin() + 1);
}

void clear() {
    for (auto pos : roll) {
        cnt[pos]--;
    }
    roll.clear();
    best.clear();
    for (int i = 0; i < maxk; ++i) {
        best.push_back({0, 0});
    }
}

node* build(int tl, int tr) {
    if (tl == tr)
        return new node();
    else {
        node *res = new node();
        int tm = (tl + tr) >> 1;
        for (int i = tm; i >= tl; --i) {
            add(a[i]);
            (res->a).push_back(best);
        }
        clear();
        reverse((res->a).begin(), (res->a).end());
        for (int i = tm+1; i <= tr; ++i) {
            add(a[i]);
            (res->a).push_back(best);
        }
        clear();
        res->l = build(tl, tm);
        res->r = build(tm+1, tr);
        return res;
    }
}

int get(node *root, int l, int r, int k, int tl, int tr) {
    if (l == r) return a[l];
    int tm = (tl + tr) >> 1;
    if (r <= tm)
        return get(root->l, l, r, k, tl, tm);
    if (l >= tm + 1)
        return get(root->r, l, r, k, tm+1, tr);
    int ans = INF;
    base v1 = (root->a)[l - tl], v2 = (root->a)[r - tl];
    for (auto p : v1) {
        if (count(l, r, p.second) > k)
            ans = min(ans, p.second);
    }
    for (auto p : v2) {
        if (count(l, r, p.second) > k)
            ans = min(ans, p.second);
    }
    if (ans == INF)
        ans = -1;
    return ans;
}

int main()
{
    scanf("%d%d", &n, &q);
    a.resize(n);
    cnt.resize(n+1);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        t[a[i]].push_back(i);
    }
    clear();
    T = build(0, n-1);
    int l, r, k;
    for (int i = 0; i < q; ++i) {
        scanf("%d%d%d", &l, &r, &k);
        l--;
        r--;
        k = (r - l + 1) / k;
        printf("%d\n", get(T, l, r, k, 0, n-1));
    }
    return 0;
}