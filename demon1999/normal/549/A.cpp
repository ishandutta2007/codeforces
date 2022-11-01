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
ll n, m, k, ans;
char a[50][50];
string s2;
int main(){
    //ifstream cin("input.txt");
    cin >> n >> m;
    forn(i, n){
      cin >> s2;
      forn(j, m)a[i][j] = s2[j];
    }
    forn(i, n - 1)
      forn(j, m - 1){
        vector<char> s;
        s.push_back(a[i][j]);
        s.push_back(a[i + 1][j]);
        s.push_back(a[i][j + 1]);
        s.push_back(a[i + 1][j+1]);
        sort(s.begin(), s.end());
        if(s[0] == 'a' && s[1] == 'c' && s[2] == 'e' && s[3] == 'f')ans++;
      }
    cout << ans;

    return 0;
}