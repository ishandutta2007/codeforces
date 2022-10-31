#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

const ll MOD = 1e9+7;
ll good[2005][2005];

vector<int> divis[2005];

int main() {
  for(int a = 1; a <= 2000; ++a) {
    for(int b = 1; b <= a; ++b) {
      if(a%b==0)
        divis[a].push_back(b);
    }
  }
  for(int a = 1; a <= 2000; ++a)
    good[a][1] = 1;
  for(int k = 2; k <= 2000; ++k) {
    for(int a = 1; a <= 2000; ++a) {
      good[a][k] = 0;
      for(int l = 0; l < divis[a].size(); ++l) {
        good[a][k] = (good[a][k]+good[divis[a][l]][k-1])%MOD;
      }
    }

  }
  int n,k;
  cin >> n >> k;
  ll ans = 0;
  for(int a = 1; a <= n; ++a)
    ans = (ans+good[a][k])%MOD;
  cout << ans << endl;
}