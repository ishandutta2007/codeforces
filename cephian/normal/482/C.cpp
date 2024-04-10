#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;
typedef long long ll;
typedef long double ld;

vector<string> s;

ll indis[1<<20]={0};

ld binom[55][55];

int main() {
  for(int a = 0; a <= 50; ++a) {
    for(int b = 0; b <= a/2; ++b) {
      if(b==0) binom[a][b] = 1;
      else binom[a][b] = binom[a-1][b-1] + binom[a-1][b];
    }
    for(int b = a; b > a/2; --b)
      binom[a][b] = binom[a][a-b];
  }

  int n,w;
  cin >> n;
  for(int i =0; i < n; ++i) {
    string s1;
    cin >> s1;
    s.push_back(s1);
  }
  w = s[0].size();
  for(int i = 0; i < n; ++i) {
    for(int j = i+1; j < n; ++j) {
      int m=0;
      for(int k = 0; k < w; ++k) {
        if(s[i][k] == s[j][k])
          m |= (1<<k);
      }
      indis[m] |= (1LL<<i) | (1LL<<j);
    }
  }

  ld ans = 0;
  for(int m = (1<<w)-1; m >=0; --m) {
    for(int i = 0; i < w; ++i) {
      if(m & (1LL << i)) {
        indis[m^(1LL<<i)] |= indis[m];
      }
    }
    ans += __builtin_popcountll(indis[m])/ld(n * binom[w][__builtin_popcount(m)]);
  }
  cout << setprecision(12) << fixed << ans << "\n";
  return 0;
}