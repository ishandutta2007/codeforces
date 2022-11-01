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

int n, a[300 * 1000], b[300 * 1000], p[300 * 1000];

set<pair<int, int> > aa[3], bb[3];
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
    forn (i, n) {
        p[i] = get_int();
    }
    forn (i, n) {
        a[i] = get_int();
        a[i]--;
        aa[a[i]].insert(mp(p[i], i));
    }
    forn (i, n) {
        b[i] = get_int();
        b[i]--;
        bb[b[i]].insert(mp(p[i], i));
    }
    int m = get_int();
    forn (i, m) {
        int c = get_int();c--;
        int ans = int(1e9) + 1, nu = -1;
        if (!aa[c].empty() && ans > (aa[c].begin()->fi)) {
            nu = 0;
            ans = (aa[c].begin()->fi);
        }
        if (!bb[c].empty() && ans > (bb[c].begin()->fi)) {
            nu = 1;
            ans = (bb[c].begin()->fi);
        }
        if (ans > int(1e9)) {
            printf("-1 ");
            continue;
        }
        printf("%d ", ans);
        if (nu == 0) {
            pair<int, int> q = (*aa[c].begin());
            aa[c].erase(q);
            bb[b[q.se]].erase(q);
        } else {
            pair<int, int> q = (*bb[c].begin());
            bb[c].erase(q);
            aa[a[q.se]].erase(q);
        }
    }
    re 0;
}