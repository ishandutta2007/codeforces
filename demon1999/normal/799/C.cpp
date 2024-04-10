#include <iostream>
#include <bits/stdc++.h>
 
 
using namespace std;
 
#define re return
#define mp make_pair
#define forn(i, n) for (int i = 0; i < n; i++)
#define sz(a) int(a.size())
#define fi first
#define se second
 
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int ma = 6 * 1000000;

int n, c, d, k1[200000], s1[200000], s2[200000], k2[200000];
vector<pii> aa, bb;

int get_int() {
    char c = getchar();
    int ans = 0 ;
    while (c < '0' || c > '9') c = getchar();
    while (c >= '0' && c <= '9') {
        ans = 10 * ans + c - '0';
        c = getchar();
    }
    re ans;
}

 
int main() {
    //iostream::sync_with_stdio(0), cin.tie(0);
    n = get_int();
    c = get_int();
    d = get_int();
    forn (i, n) {
        int b = get_int(), p = get_int();
        char c = getchar();
        while (c != 'C' && c != 'D') c = getchar();
        if (c == 'C') {
            aa.push_back(mp(b, p));
            if (k1[p] < b) {
                s1[p] = k1[p];
                k1[p] = b;
                continue;
            } else
                s1[p] = max(s1[p], b);
        } else {
            bb.push_back(mp(b, p));
            if (k2[p] < b) {
                s2[p] = k2[p];
                k2[p] = b;
                continue;
            } else
                s2[p] = max(s2[p], b);
        }
    }
    int ans = 0;
    for (int i = 1; i < 200000; i++) {
        if (k1[i] < k1[i - 1]) {
            s1[i] = max(s1[i], max(k1[i], s1[i - 1]));
            k1[i] = k1[i - 1];
        } else {
            s1[i] = max(s1[i], k1[i - 1]);
        }
        if (k2[i] < k2[i - 1]) {
            s2[i] = max(s2[i], max(k2[i], s2[i - 1]));
            k2[i] = k2[i - 1];
        } else {
            s2[i] = max(s2[i], k2[i - 1]);
        }
    }
    if (k1[c] && k2[d])
        ans = k1[c] + k2[d];
    for (auto v : aa) {
        if (v.se < c) {
            if (c - v.se < v.se) {
                if (k1[c - v.se])
                    ans = max(ans, k1[c - v.se] + v.fi);
            } else {
                if (k1[c - v.se] == v.fi) {
                    if (s1[c - v.se])
                        ans = max(ans, s1[c - v.se] + v.fi);
                } else
                    if (k1[c - v.se])
                        ans = max(ans, k1[c - v.se] + v.fi);
            }
        }
    }
    swap(c, d);
    for (auto v : bb) {
        if (v.se < c) {
            if (c - v.se < v.se) {
                if (k2[c - v.se])
                    ans = max(ans, k2[c - v.se] + v.fi);
            } else {
                if (k2[c - v.se] == v.fi) {
                    if (s2[c - v.se])
                        ans = max(ans, s2[c - v.se] + v.fi);
                } else
                    if (k2[c - v.se])
                        ans = max(ans, k2[c - v.se] + v.fi);
            }
        }
    }
    cout << ans;
    re 0;
}