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
#define l1 l11
#define r1 r11
using namespace std;
typedef long long ll;
typedef long double ld;
const long ma11 = 524288, ma1 = 16;
int a, b, n, k, kk = 0;
vector<int> b1[200], bp, bp1[200];
vector<int> use, use1;
void dfs(int nu){
    use[nu] = 1;
    for(int i = 0; i < sz(b1[nu]); i++)
      use[b1[nu][i]] = 1;
}
int main(){
    //ifstream cin("i.in");
    cin >> n >> k;
    map<int, int> qq;
    for(int i = 0; i < n; i++){
      cin >> a >> b;
      if(qq[a] == 0){
        kk++;
        qq[a] = kk; bp.push_back(a);
      }
      if(qq[b] == 0){
        kk++;
        qq[b] = kk; bp.push_back(b);
      }
      b1[qq[a] - 1].push_back(qq[b] - 1);
      b1[qq[b] - 1].push_back(qq[a] - 1);
    }n = kk ;
    for(int i = 0; i < n; i++){
      use.assign(n, 0);
      dfs(i);use1 = use;
      for(int j = 0; j < n; j++){
        if(use1[j] == 0){
          use.assign(n, 0);
          dfs(j);
          int k1 = -1, k2 = 0, k3 = -1;
          for(int jj = 0; jj < n; jj++){
            if(use1[jj] == 1)k1++;
            if(use[jj] == 1)k3++;
            if(use1[jj] == 1 && use[jj] == 1)k2++;
          }
          if(100 * k2 >= k1 * k )bp1[i].push_back(bp[j]);
        }
      }
      sort(bp1[i].begin(), bp1[i].end());
    }
    for(int i = 0; i < n; i++)
      for(int j = 0; j < n - 1; j++)
        if(bp[j] > bp[j + 1]){
          swap(bp[j], bp[j + 1]);
           swap(bp1[j], bp1[j + 1]);
        }
    for(int i = 0; i < n; i++){
      cout << bp[i] << ": " << sz(bp1[i]);
      for(int j = 0; j < sz(bp1[i]); j++)cout << " " << bp1[i][j];
      cout << "\n";
    }
    return 0;
}