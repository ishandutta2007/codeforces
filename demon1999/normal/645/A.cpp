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

struct T { int x, y; };
T t = {1, 2};

string s, s1;
char c0, c1, c2, c3;
int main(){
    iostream::sync_with_stdio(0); cin.tie(0);
//    assert(freopen("qqq.in", "r",  stdin));
    cin >> c0 >> c1 >> c3 >> c2;
    s = "";
    if (c0 != 'X') s += c0;
    if (c1 != 'X')s  += c1;
    if (c2 != 'X')s  += c2;
    if (c3 != 'X')s += c3;
    cin >> c0 >> c1 >> c3 >> c2;
    s1 = "";
    if (c0 != 'X') s1 += c0;
    if (c1 != 'X')s1  += c1;
    if (c2 != 'X')s1  += c2;
    if (c3 != 'X')s1 += c3;
    forn (i, 3) {
        if (s[0] == s1[i] && s[1] == s1[(i + 1) % 3] && s[2] == s1[(i +2 ) % 3]) {
            cout << "YES";re 0;
        }
    }
    cout << "NO";
    return 0;
}