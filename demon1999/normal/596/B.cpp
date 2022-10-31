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
ll n, k, a, ans;
int main() {
    iostream::sync_with_stdio(0);
    //ifstream cin("input.txt");
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> k;
        ans += abs(a - k);
        a = k;
    }
    cout << ans;
    re 0;
}