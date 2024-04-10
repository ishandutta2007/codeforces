#include <iostream>
#include <fstream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>
#include <map>
#include <set>

#define forn(i, n) for(int i = 0; i < n; i++)
#define mp(i, j) make_pair(i, j)
#define rs(a, j) a.resize(j)
#define pb(a, j) a.push_back(j)
#define pp(a) a.pop_back()
#define len(s) (int)s.length()
#define sz(a) (int)a.size()
#define re  return
typedef long long ll;
typedef long double ld;
using namespace std;
int p, q, k1 = 0, k2 = 0, nu, a[2000000];
string s;
bool pal(int i) {
    s = "";
    while (i > 0) {
        s += char(i % 10 + '0');
        i /= 10;
    }
    for (int i = 0; i < len(s); i++)
        if (s[i] != s[len(s) - i - 1]) re false;
    re true;
}

int main(){
    a[1] = 1;
    cin >> p >> q;
    for (int i = 1; i < 2000000; i++) {
        if (pal(i)) k1++;
        if (a[i] == 0) {
            k2 ++;
            for (int j = 2 * i; j < 2000000; j+= i)
                a[j] = 1;
        }
        if (p * k1 / q >= k2) nu = i;
    }
    cout << nu;
    return 0;
}