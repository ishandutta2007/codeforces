#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

const int N = 510;
string dp[N];
char s[N];
int n, k;

char nxt(char x) {
  return (char) ((x-'a'+1)%k + 'a');
}
char prv(char x) {
  return (char) ((x-'a'+k-1)%k + 'a');
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  int TT;
  cin >> TT;
  while (TT--) 
  {
    cin >> n >> k;
    cin >> (s+1);
    dp[1] = min(s[1], min(nxt(s[1]), prv(s[1])));
    for (int i=2; i<=n; ++i) {
      char curc = min(s[i], min(nxt(s[i]), prv(s[i])));
      dp[i] = dp[i-1] + curc;
      dp[i] = min(dp[i], dp[i-2] + curc + s[i-1]);
      {
        string p = dp[i-1];
        char z = p.back();
        p.pop_back();
        p += s[i];
        p += z;
        dp[i] = min(dp[i], p);
      }
      if (i >= 3) {
        string q = dp[i-2];
        char w = q.back();
        q.pop_back();
        q += s[i];
        q += w;
        q += s[i-1];
        dp[i] = min(dp[i], q);
      }
    }
    cout << dp[n] << "\n";
  }
  return 0;
}