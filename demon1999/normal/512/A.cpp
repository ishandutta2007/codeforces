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
int n;
string s, s1;
vector<int> use(26, 0), a[26];
string ans;
void dfs(int i11){
  use[i11] = 1;
  forn(j, sz(a[i11])){
    if(use[a[i11][j]] == 1){
        cout << "Impossible"; exit(0);
    }
    if(use[a[i11][j]] == 0)dfs(a[i11][j]);
  }
  ans += char(i11 + 'a');
  use[i11] = 2;
}
int main(){
    cin >> n;
    cin >> s1;
    for(int i = 1; i < n; i++){
        cin >> s;
        bool ok = true;
        for(int i = 0; i < len(s) && i < len(s1); i++){
            if(s[i] != s1[i]){
                ok = false;
                a[s[i] - 'a'].push_back(s1[i] - 'a');
                break;
            }
        }
        if(ok && len(s) < len(s1)){
             cout << "Impossible"; exit(0);
        }
        s1 = s;
    }
    for(int i = 0; i < 26; i++)
        if(use[i] == 0)dfs(i);
    cout << ans << endl;
    return 0;
}