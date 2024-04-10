#include <bits/stdc++.h>

using namespace std;

#define llong long long 
#define ii pair<int, int>
#define xx first
#define yy second
#define len(v) ((int)v.size())
#define rep(i,n) for (int i = -1; ++i < n; )
#define rep1(i,n) for (int i = 0; i++ < n; )

#define maxn 1000101
char s[maxn];
int n;
int z[maxn], cntz[maxn];
bool can[maxn];

int main() {
  scanf("%s", s);
  n = 0; while (s[n]) ++n;
  
  int l = 0, r = 0;
  z[0] = n;
  rep1(i, n - 1) {
    if (i > r) {for (l = r = i; r < n and s[r - l] == s[r]; ++r); z[i] = r-- - l;}
    else if (z[i - l] < r - i + 1) z[i] = z[i - l];
    else { for (l = i; r < n and s[r - l] == s[r]; ++r); z[i] = r-- - l;}
    cntz[z[i]]++;
    if (z[i] == n - i) can[z[i]] = 1;
  }
  
  for (int i = n; i-- > 0; ) {
    cntz[i] += cntz[i + 1];
    // if (can[i]) clog << i << ' ' << cntlcp[i] << endl;
    if (can[i] and cntz[i] > 1) {
      s[i] = 0;
      printf("%s", s);
      return 0;
    }
  }
  
  cout << "Just a legend";
    
  return 0;
}