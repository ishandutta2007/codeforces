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
typedef long long ll;
typedef long double ld;
using namespace std;
ll n, m, k, ans = 0;
ll a[100][100], b[100][100];
string s;
int main(){
    //ifstream cin("input.txt");
    cin >> n >> m;
    forn(i, n){
      cin >> s;
      forn(j, m)
        if(s[j] == 'W')a[i][j] = 1;
        else a[i][j] = -1;
    }
    for(int i = n - 1; i >= 0; i--)
        for(int j = m - 1; j >= 0; j--)
           if(b[i][j] != a[i][j]){
             k = -b[i][j] + a[i][j];
             //cout << k << endl;
             forn(k1, i + 1)
             forn(k2, j + 1)b[k1][k2] += k;
             ans++;
           }
    cout << ans;
    return 0;
}