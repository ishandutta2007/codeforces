#include <iostream>
#include <fstream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>
#include <map>
#include <set>
#include <cassert>
#include <bits/stdc++.h>
#define forn(i, n) for(ll i = 0; i < int(n); i++)
#define mp(i, j) make_pair(i, j)
#define rs(j) resize((j))
#define pb push_back
#define pp pop_back
#define len(s) (int)s.length()
#define sz(a) (int)a.size()
#define re  return
#define fi first
#define se second
//#define int long long

typedef long long ll;
typedef long double ld;
using namespace std;
const int kk = 1000000;
int n, m, k, mi[21][kk], ma[21][kk], len[kk + 1];
vector<int> q;

int fc(int l, int r) {
    re max(ma[len[r - l + 1]][l], ma[len[r - l + 1]][r - (1 << len[r - l + 1]) + 1]);
}

int fc1(int l, int r) {
    re min(mi[len[r - l + 1]][l], mi[len[r - l + 1]][r - (1 << len[r - l + 1]) + 1]);
}
signed main(){
    iostream::sync_with_stdio(0); cin.tie(0);
    //assert(freopen("qq.in", "r",  stdin));
    //freopen("abba.out", "w", stdout);
    cin >> n >> k;
    forn (i, n) {
        cin >> ma[0][i];
        ma[0][i] *= 100;
    }
    forn (i, n) {
        cin >> mi[0][i];
    }
    int kkkk = 1, st = 0;
    for (int i = 1; i <= n; i++) {
        if (2 * kkkk == i) {
            kkkk <<= 1;
            st++;
        }
        len[i] = st;
        //cout << i << " " << len[i] << " " << k << endl;
    }
    for (int j = 1; j <= 20; j++) {
        int kkkk = (1 << (j - 1));
        for (int i = 0; i + kkkk < n; i++) {
            mi[j][i] = min(mi[j - 1][i], mi[j - 1][i + kkkk]),
            ma[j][i] = max(ma[j - 1][i], ma[j - 1][i + kkkk]);
        }
        for (int i = max(0, n - kkkk); i < n; i++) {
            mi[j][i] = mi[j - 1][i];
            ma[j][i] = ma[j - 1][i];
        }
    }
    int l, r, mid;
    forn (i, n) {
        l = i, r = n;
        while (r - l > 1) {
            mid = (l + r) / 2;
            if (fc(i, mid) > fc1(i, mid)) r = mid;
            else l = mid;
        }
        int qq = fc(i, l), qq2 = fc1(i, l);
        q.push_back(min(qq, qq2));
        if (l + 1 < n) q[i] = max(q[i], min(max(qq, ma[0][l + 1]), min(qq2, mi[0][l + 1])));
        //cout << q[i] << " ";
    }
    //cout << q[20] << endl;
    ld ans = 0, qq = ld(k) / ld(n);
    int p = n, c = n - k + 1;
    sort(q.begin(), q.end());
    forn (i, n) {
        //cout << q[i] << " ";
        p--; c--;
        if (c < 0) break;
        ans += ld(q[i]) * qq;
        qq = (qq * ld(c)) / ld(p);
    }

    cout.precision(30);
    cout << ans;
    return 0;
}