#include <iostream>
#include <cstdio>
#include <set>
#include <map>
#include <cmath>
#include <algorithm>
#include <fstream>
#include <vector>
#include <bitset>
//#include "grader.h"
#define forn(i,n) for(int i=0;i<n;i++)                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                     ---
#define sz(a) (int)a.size()
#define re return
#define fi first
#define se second
#define mp(a, b) make_pair(a, b)
using namespace std;
typedef long long ll;

typedef long double ld;
const ll mod = 1000000007, con = 2500000;
int n, xmi, xma, ymi, yma, x, y;
int main() {
    iostream::sync_with_stdio(0);
    //ifstream cin("input.txt");
    cin >> n >> x >> y;
    xmi = xma = x;
    ymi = yma = y;
    for (int i = 0; i < n - 1; i++) {
        cin >> x >> y;
        xmi = min(xmi, x);
        ymi = min(ymi, y);
        xma = max(xma, x);
        yma = max(yma, y);
    }
    if (xmi != xma && ymi != yma) cout << abs(xmi - xma) * abs(ymi - yma);
    else cout << -1;
    re 0;
}