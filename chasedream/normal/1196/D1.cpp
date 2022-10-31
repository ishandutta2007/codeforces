#include <bits/stdc++.h>
using namespace std;
 
const int N = 1000005;
char kel[3] = {'R', 'G', 'B'};
string s;
int n, k;
 
void work() {
  int ans = INT_MAX;
  scanf("%d%d", &n, &k);
  cin >> s; s = ' ' + s;
  for (int i = 0; i < 3; i++) {
    string qq = "";
    for (int j = 1; j <= k; j++) {
      char newc = kel[(i + j) % 3];
      qq += newc;
    }
    //cerr<<qq<<'\n';
    for (int j = 1; j <= n - k + 1; j++) {
      int co = 0;
      for (int p = j; p <= j + k - 1; p++)
        if (qq[p - j] != s[p]) co++;
      ans = min(ans, co);
    }
    //cerr<<ans<<'\n'; 
  }
  printf("%d\n", ans);
}
 
int main(){
  int t; scanf("%d", &t);
  while (t--) {
    work();
  }
  return 0;
} 
//