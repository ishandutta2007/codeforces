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
int n, m, ans = 1;
vector<int> a;
unordered_map<int, int> qq;
map<pair<int, int>, int> b;
signed main(){
    iostream::sync_with_stdio(0); cin.tie(0);
    //assert(freopen("qq.in", "r",  stdin));
    //freopen(".out", "w", stdout);
    cin >> n;
    a.resize(n);
    forn (i, n) {cin >> a[i];qq[a[i]]++;}
    sort(a.begin(), a.end());
    int pp[1001], nu;
    forn (i, n) {
        forn (j, n) {
            if (i != j && !b[mp(a[i], a[j])]) {
                b[mp(a[i], a[j])] = 1;
                qq[a[i]]--;
                qq[a[j]]--;
                nu = 2;
                int s1 = a[i], s2 = a[j];
                pp[0] = a[i];
                pp[1] = a[j];
                while (qq[s1 + s2]) {
                    qq[s1 + s2]--;
                    pp[nu] = s1 + s2;
                    nu++;
                    s1 = s2; s2 = pp[nu - 1];
                }
                if (nu > ans) ans = nu;
                forn (i, nu)
                    qq[pp[i]]++;
            }
        }
    }
    cout << ans;
    return 0;
}