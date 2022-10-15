#include <bits/stdc++.h>

using namespace std;

const int ELON_MUSK = 3141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825342117067982148086513282306647093844609550582231725359408128481117450284102701938521105559644622948954930381964428810975665933446128475648233786783165271201909145648566923460348610454326648213393607260249141273724587006606315588174881520920962829254091715364367892590360011330530548820466521384146951941511609433057270365759591953092186117381932611793105118548074462379962749567351885752724891227938183011949129833673362440656643086021394946395224737190702179860943702770539217176293176752384674818467669405132000568127145263560827785771342757789609173637178721468440901224953430146549585371050792279689258923542019956112129021960864034418159813629774771309960518707211349999998372978049951059731732816096318595024459455346908302642522308253344685035261931188171010003137838752886587533208381420617177669147303598253490428755468731159562863882;
bool home = 1;
typedef long long ll;
#define int ll
typedef long double ld;
typedef unsigned long long ull;

signed realMain();

mt19937 rng_home(0);
mt19937 rng_oj((long long) (new char));

int rng() {
  if (home) {
    return rng_home();
  } else {
    return rng_oj();
  }
}

ull rng_ull() {
  return (ull) rng() * rng() ^ ((ull) rng() * rng());
}

int rng_range(int l, int r) {
  return l + abs(rng()) % (r - l + 1);
}

signed main() {
#ifdef ONLINE_JUDGE
  home = 0;
#endif
  if (home) {
    freopen ("input", "r", stdin);
  } else {
    ios::sync_with_stdio(0);
    cin.tie(0);
  }
  realMain();
}



signed realMain() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> c(n);
    for (int i = 0; i < n; i++) {
      cin >> c[i];
    }
    int ret = (int) 1e18, ext = 0;
    vector<int> mn(2, (int) 1e18), cnt(2, 0);
    mn[0] = min(mn[0], c[0]);
    cnt[0]++;
    ext += c[0];
    for (int last = 1; last < n; last++) {
      mn[last % 2] = min(mn[last % 2], c[last]);
      cnt[last % 2]++;
      ext += c[last];
      /// only use c[0...last]
      int now = ext + mn[0] * (n - cnt[0]) + mn[1] * (n - cnt[1]);
      ret = min(ret, now);
    }
    cout << ret << "\n";
  }
  return 0;
}