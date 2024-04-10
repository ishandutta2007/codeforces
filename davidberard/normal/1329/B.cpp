#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

ll cnt[32];

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  int TT;
  cin >> TT;
  while (TT--) {
    ll d, m;
    cin >> d >> m;
    for (int i=0; i<32; ++i) {
      cnt[i] = max(0LL, min(d, (1LL<<(i+1))-1) - ((1LL<<i)-1));
      //cerr << " CNT " << i << " :: " << cnt[i] << endl;
    }
    //ll ans = 0;
    ll cur = 1;
      for (int j=0; j<32; ++j) {
        cur = (cur*(cnt[j]+1))%m;
        //ans += cur;
      }
    cur += m-1;
    cout << cur%m << "\n";
  }
  return 0;
}