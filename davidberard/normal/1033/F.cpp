#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

const int T12 = 531441;

int conv[T12+10];
int amt[1<<12];
int w, n, m;

int count(int cur, int k, const string& s) {
  if (k == w) {
    return conv[cur];
  }
  if (s[k] == 'A') {
    return count(cur*3  , k+1, s)+count(cur*3+1, k+1, s);
  } else if (s[k] == 'O') {
    return count(cur*3, k+1, s);
  } else if (s[k] == 'X') {
    return count(cur*3  , k+1, s)+count(cur*3+2, k+1, s);
  } else if (s[k] == 'a') {
    return count(cur*3+2, k+1, s);
  } else if (s[k] == 'o') {
    return count(cur*3+1, k+1, s)+count(cur*3+2, k+1, s);
  } else if (s[k] == 'x') {
    return count(cur*3+1, k+1, s);
  }
  assert(false);
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  cin >> w >> n >> m;
  for (int i=0; i<n; ++i) {
    int a;
    cin >> a;
    ++amt[a];
  }
  for (int i=0; i<(1<<w); ++i) {
    for (int j=0; j<(1<<w); ++j) {
      int cur = 0;
      for (int k=w-1; k>=0; k--) {
        int x = ((i>>k)&1) + ((j>>k)&1);
        cur = cur*3 + x;
      }
      conv[cur] += amt[i]*amt[j];
    }
  }
  for (int i=0; i<m; ++i) {
    string s;
    cin >> s;
    //reverse(s.begin(), s.end());
    cout << count(0, 0, s) << "\n";
  }
  return 0;
}