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
#define m_p(i, j) make_pair(i, j)
#define rs(a, j) a.resize(j)
#define pb(a, j) a.push_back(j)
#define pp(a) a.pop_back()
#define len(s) s.length()
#define sz(a) a.size()
#define re  return
typedef long long ll;
typedef long double ld;
using namespace std;
struct poi{
  int x, y;
};
int n, m;
char a[100][100];
int main(){
    //ifstream cin("input.txt");
    cin >> n >> m;
    swap(n, m);
    forn(i, n)
      for(int j = 0; j < m; j++) cin >> a[j][i];

    forn(i, m){
        forn(k, 2){
      forn(j, n)cout << a[i][j] << a[i][j];
      cout << endl;
        }
    }
    return 0;
}