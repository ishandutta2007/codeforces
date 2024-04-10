#include <bits/stdc++.h>
#pragma GCC target ("sse4.2")

using namespace std;

bool home = 1;
typedef long long ll;
///#define int ll

signed realMain();

signed main() {
#ifdef ONLINE_JUDGE
  home = 0;
#endif
  if (home) {
    freopen ("tony_stark", "r", stdin);
  } else {
    ios::sync_with_stdio(0); cin.tie(0);
  }
  realMain();
}


const int M = (int) 1e9 + 7;

int add(int a, int b) {
  a += b;
  if (a >= M) return a - M;
  if (a < 0) return a + M;
  return a;
}

int mul(int a, int b) {
  return a * (ll) b % M;
}

const int N = 5000 + 7;
int n, a[N];
string s;
int comb[N][N], cnt[N], f[26], last[26], pre[N][N]; /// dp[i][len]

int sum(int len, int l, int r) {
  return add(pre[r][len], -pre[l - 1][len]);
}

signed realMain() {
  cin >> n >> s;
  for (int i = 0; i <= n; i++) {
    comb[i][0] = 1;
    for (int j = 1; j <= i; j++) {
      comb[i][j] = add(comb[i - 1][j], comb[i - 1][j - 1]);
    }
  }
  /**
  thinking time :>
  ma gandesc la stringurile compresate
  mereu fie se sterge un caracter, fie ramane la fel
  deci daca vreau sa ajung de la s la t trebuie ca comp(t) sa apartina lui comp(s)
  ceea ce e si suficient... adica na, ma joc cu marginile.
  spre exemplu:
  aaabbb
  abbbbb => aici e evident cum fac

  acum cand calculez cate subsecvente de caractere distincte sunt in s de lungime l trebuie sa inmultesc cu comb(n-1,l-1) ca sa nu mai fie vorba de stringuri
  compresate
  **/
  
  for (int i = 1; i <= n; i++) {
    a[i] = s[i - 1] - 'a';
  }
  for (int i = 1; i <= n; i++) {
    int x = a[i];
    for (int len = 1; len <= i; len++) {
      pre[i][len] = add(pre[i - 1][len], sum(len - 1, last[x] + 1, i - 1));
    }
    if (!last[x]) {
      pre[i][1] = add(pre[i - 1][1], 1);
    }
    last[x] = i;
  }
  int ret = 0;
  for (int len = 1; len <= n; len++) {
    ret = add(ret, mul(pre[n][len], comb[n - 1][len - 1]));
  }
  cout << ret << "\n";
  return 0;
}