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

#define forn(i, n) for (int i = 0; i < int(n); i++)
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

struct T { ll m1, m2; };
T t = {1, 2};

const int ma = 2 * 131072;
ll n, m, l, r, k, day[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
string s1, s2;
int main(){
    iostream::sync_with_stdio(0); cin.tie(0);
    //freopen("round.in", "r",  stdin);
    cin >> k >> s1 >> s2;
    if (s2 == "week") {
        int sum = 1;
        int nu = 1;
        if (k >= 5) nu += k - 5;
        else nu += 2 + k;
        while (nu + 7 <= 366) {
            sum++;
            nu += 7;
        }
        cout << sum;
    }
    else {
        ll k1 = 0;
        forn(i, 12)
            if (day[i] >= k) k1++;
        cout << k1;
    }
    return 0;
}