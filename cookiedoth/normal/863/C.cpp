#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007

using namespace std;

ll k, clen;
pair<ll, ll> score = {0, 0}, scorec = {0, 0};
pair<ll, ll> start, cur;
map<pair<ll, ll>, pair<ll, ll> > p;
map<pair<ll, ll>, ll> pa, pb;
map<pair<ll, ll>, pair<ll, ll> > used;
map<pair<ll, ll>, ll> len;

pair<ll, ll> f(pair<ll, ll> pr) {
    ll a = pr.first, b = pr.second;
    if (a == b + 1)
        return {1, 0};
    if (b == a + 1)
        return {0, 1};
    if (a == 0 && b == 2)
        return {1, 0};
    if (b == 0 && a == 2)
        return {0, 1};
    return {0, 0};
}

pair<ll, ll> operator + (pair<ll, ll> a, pair<ll, ll> b) {
    return {a.first + b.first, a.second + b.second};
}

pair<ll, ll> operator - (pair<ll, ll> a, pair<ll, ll> b) {
    return {a.first - b.first, a.second - b.second};
}

int main()
{
    cin >> k >> start.first >> start.second;
    start.first -= 1;
    start.second -= 1;
    for (ll i = 0; i < 3; ++i) {
        for (ll j = 0; j < 3; ++j) {
            ll tmp;
            cin >> tmp;
            tmp--;
            pa[{i, j}] = tmp;
        }
    }
    for (ll i = 0; i < 3; ++i) {
        for (ll j = 0; j < 3; ++j) {
            ll tmp;
            cin >> tmp;
            tmp--;
            pb[{i, j}] = tmp;
        }
    }
    for (ll i = 0; i < 3; ++i) {
        for (ll j = 0; j < 3; ++j) {
            p[{i, j}] = {pa[{i, j}], pb[{i, j}]};
            used[{i, j}] = {-1, -1};
            len[{i, j}] = -1;
        }
    }
    used[start] = {0, 0};
    len[start] = 0;
    cur = start;
    score = score + f(start);
    scorec = scorec + f(start);
    k -= 1;
    clen += 1;
    cur = p[cur];
    while (len[cur] == -1 && k > 0) {
        used[cur] = scorec;
        len[cur] = clen;
        score = score + f(cur);
        scorec = scorec + f(cur);
        k -= 1;
        clen += 1;
        cur = p[cur];
    }
    scorec = scorec - used[cur];
    clen -= len[cur];
    ll c1 = k / clen;
    k = k % clen;
    scorec.first *= c1;
    scorec.second *= c1;
    score = score + scorec;
    while (k > 0) {
        score = score + f(cur);
        scorec = scorec + f(cur);
        k -= 1;
        clen += 1;
        cur = p[cur];
    }
    cout << score.first << " " << score.second << endl;
    return 0;
}