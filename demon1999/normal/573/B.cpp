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
#define len(s) s.length()
#define sz(a) a.size()
#define re  return
#define i1 i123
#define j1 j123
typedef long long ll;
typedef long double ld;
using namespace std;
const  int ma = 131072;
int n, k, i1, j1, mitr1[2 * ma], mitr2[2 * ma];
vector<int> a;

int min1(int l, int r) {
    if (l > r) re 2000000000;
    if (l % 2) re min(mitr1[l], min1(l + 1, r));
    if (r % 2 == 0) re min(mitr1[r], min1(l, r - 1));
    re min1(l / 2, r / 2);
}

int min2(int l, int r) {
    if (l > r) re 2000000000;
    if (l % 2) re min(mitr2[l], min2(l + 1, r));
    if (r % 2 == 0) re min(mitr2[r], min2(l, r - 1));
    re min2(l / 2, r / 2);
}

int main(){
    //ifstream cin("input.txt");
    iostream::sync_with_stdio(0);
    cin >> n;
    a.resize(n);
    forn (i, n) {
        cin >> a[i];
        mitr1[i + ma] = a[i] + i;
        mitr2[i + ma] = a[i] + n - i - 1;
    }
    for (int i = ma - 1; i > 0; i--)
        mitr1[i] = min(mitr1[2 * i], mitr1[2 * i + 1]),
        mitr2[i] = min(mitr2[2 * i], mitr2[2 * i + 1]);
    k = 0;
    j1 = n - 1;
    forn(i, n) {
        while (i1 < n && (min1(i1 + ma, n + ma - 1) <= k + i1 || min2(ma, i1 + ma) <= k + (n - i1 - 1))) i1++;
        while (j1 >= 0 && (min1(j1 + ma, n + ma - 1) <= k + j1 || min2(ma, j1 + ma) <= k + (n - j1 - 1))) j1--;
        //cout << i1 << " " << j1 << endl;
        if (i1 == n || i1 > j1) {
            break;
        }
        k++;
        i1++;
        j1--;
    }
    cout << k;
    return 0;
}