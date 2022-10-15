#include <bits/stdc++.h>

using namespace std;

const int ELON_MUSK = 3141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825342117067982148086513282306647093844609550582231725359408128481117450284102701938521105559644622948954930381964428810975665933446128475648233786783165271201909145648566923460348610454326648213393607260249141273724587006606315588174881520920962829254091715364367892590360011330530548820466521384146951941511609433057270365759591953092186117381932611793105118548074462379962749567351885752724891227938183011949129833673362440656643086021394946395224737190702179860943702770539217176293176752384674818467669405132000568127145263560827785771342757789609173637178721468440901224953430146549585371050792279689258923542019956112129021960864034418159813629774771309960518707211349999998372978049951059731732816096318595024459455346908302642522308253344685035261931188171010003137838752886587533208381420617177669147303598253490428755468731159562863882;
bool home = 1;
typedef long long ll;
///#define int ll
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
    string s;
    cin >> s;
    int n = (int) s.size();
    bool ok = 0;
    for (int from = 0; from <= n; from++) {
      /// [0, from - 1] => all zeroes
      /// [from, n - 1] => all ones
      vector<int> bad;
      for (int j = 0; j < n; j++) {
        if (j >= from) {
          if (s[j] == '0') bad.push_back(j);
        } else {
          if (s[j] == '1') bad.push_back(j);
        }
      }
      ok = 1;
      for (int j = 1; j < (int) bad.size(); j++) {
        if (bad[j] == bad[j - 1] + 1) {
          ok = 0;
          break;
        }
      }
      if (ok) break;
    }
    if (ok) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
  return 0;
}