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
#define forn(i, n) for(int i = 0; i < int(n); i++)
#define mp(i, j) make_pair(i, j)
#define rs(j) resize((j))
#define pb push_back
#define pp pop_back
#define len(s) (int)s.length()
#define sz(a) (int)a.size()
#define re  return
#define fi first
#define se second
typedef long long ll;
typedef long double ld;
using namespace std;

struct T { double x, m, v; int nu;};
ll n, a1, b1, ans, dp[1000000][32], bq[60], bq1[60], bd[60], bd1[60];
vector<ll> a;
vector<int> q1;
int main(){
    iostream::sync_with_stdio(0); cin.tie(0);
    //freopen("a.in", "r",  stdin);
    //freopen(".out", "w", stdout);
    cin >> n >> a1 >> b1;
    ans = a1 * (n - 1);
    a.resize(n);
    forn (j, n) {
        cin >> a[j];
    }
    int kk = a[0];
    for (int i = 2; i * i <= kk; i++) {
        if (kk % i == 0) {
            q1.push_back(i);
        }
        while (kk % i == 0) kk /= i;
    }
    if (kk > 1) q1.push_back(kk);
    kk = a[0] + 1;
    for (int i = 2; i * i <= kk; i++) {
        if (kk % i == 0) {
            q1.push_back(i);
        }
        while (kk % i == 0) kk /= i;
    }
    if (kk > 1) q1.push_back(kk);
    kk = a[0] - 1;
    if (kk % 2 == 0) kk /= 2;
    for (int i = 2; i * i <= kk; i++) {
        if (kk % i == 0) {
            q1.push_back(i);
        }
        while (kk % i == 0) kk /= i;
    }
    if (kk > 1) q1.push_back(kk);

    kk = a[n - 1];
    for (int i = 2; i * i <= kk; i++) {
        if (kk % i == 0) {
            q1.push_back(i);
        }
        while (kk % i == 0) kk /= i;
    }
    if (kk > 1) q1.push_back(kk);
    kk = a[n - 1] + 1;
    for (int i = 2; i * i <= kk; i++) {
        if (kk % i == 0) {
            q1.push_back(i);
        }
        while (kk % i == 0) kk /= i;
    }
    if (kk > 1) q1.push_back(kk);
    kk = a[n - 1] - 1;
    if (kk % 2 == 0) kk /= 2;
    for (int i = 2; i * i <= kk; i++) {
        if (kk % i == 0) {
            q1.push_back(i);
        }
        while (kk % i == 0) kk /= i;
    }
    if (kk > 1) q1.push_back(kk);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < sz(q1); j++) {
            if (i != 0) dp[i][j] = dp[i - 1][j];
            if (bd[j] == 1) {
                dp[i][j] += a1;
                continue;
            }
            if (a[i] % q1[j] == 0) {
                continue;
            }
            if ((a[i] - 1) % q1[j] == 0 || (a[i] + 1) % q1[j] == 0) {
                dp[i][j] += b1;
            }
            else {
                bd[j] = 1;
                dp[i][j] += a1;
            }
        }
    }
    forn (i, n)
        forn (j, sz(q1)) {
            if (i == 0) dp[i][j] = min(dp[i][j], a1);
            else dp[i][j] = min(dp[i - 1][j] + a1, dp[i][j]);
        }
    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j < sz(q1); j++) {
            bq1[j] = bq[j] + a1;
            if (bd1[j] == 1) {
                bq[j] += a1;
            }
            else {
                if ((a[i] - 1) % q1[j] == 0 || (a[i] + 1) % q1[j] == 0)
                    bq[j] += b1;
                else
                if (a[i] % q1[j]) {
                    bq[j] += a1;
                    bd1[j] = 1;
                }
            }
            bq1[j] = min(bq1[j], bq[j]);
            if (i > 0) ans = min(ans, bq1[j] + dp[i - 1][j]);
            else ans = min(ans, bq1[j]);
            if (i == n - 1)
                ans = min(ans, dp[i][j]);
        }
    }
    cout << ans;
    return 0;
}