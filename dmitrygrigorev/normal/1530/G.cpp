#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

const int mod = 1000000007;

void add(int& a, int b) {
  a += b;
  if (a >= mod) a -= mod;
  if (a < 0) a += mod;
}

int mult(int a, int b) {
  return a * (ll)b % mod;
}

int bp(int a, int b) {
  int res = 1;
  while (b > 0) {
    if (b & 1) res = mult(res, a);
    a = mult(a, a);
    b >>= 1;
  }
  return res;
}

int get(string s) {
  int a = -1, b = 1e9;
  for (int i = 0; i < s.size(); ++i) {
    if (s[i] == '1') {
      a = max(a, i);
      b = min(b, i);
    }
  }

  return a - b;

}

void add(vector<pair<int, int> > &ans, int l, int r, string &s) {
  ans.pb(mp(l, r));
  reverse(s.begin() + l, s.begin() + r + 1);
}

void solve1(string s, string t) {

  vector<pair<int, int> > ans;

  int len = get(s);
  int klen = get(t);
  if (len != klen) {
    cout << "-1\n";
    return;
  }
  int q = 0;

  while (true) {

    //cout << s << " " << t << " " << s.size() << " " << t.size() << " " << s[0] << " " << s[1] << " " << s[2] << " " << s[3] << " " << s[4] << endl;
    //assert(s.size() == t.size());

    if (s == t) {
      cout << ans.size() << '\n';
      for (auto x : ans) cout << x.x + 1 << " " << x.y+1 << '\n';
      return;
    }

    int a = -1, b = -1;
    for (int i = 0; i < s.size(); ++i) {
      if (s[i] == '1') {
        a = i;
        break;
      }
    }

    for (int i = 0; i < t.size(); ++i) {
      if (t[i] == '1') {
        b = i;
        break;
      }
    }

    if (a > b) {
      add(ans, a - 1, a + len, s);
    }

    else if (a < b) {
      add(ans, a, a + len + 1, s);
    }

    else {
      if (q) {
        cout << "-1\n";
        return;
      }
      q++;
      add(ans, a, a+len, s);
    }

  }

}

int n, k;
string gg;

void spec_solve(string &s, vector<pair<int, int> > &ans) {

  int pos = -1;
  for (int i = 0; i < n; ++i) if (s[i] == '1') {
    pos = i;
    break;
  }

  int zeros = 0;
  int tut = pos+1;

  while (tut < s.size() && s[tut] == '0') {
    tut++;
    zeros++;
  }

  if (zeros == 0) return;
  int total = n - pos - zeros;

  vector<int> last(n, -1);

  queue<int> q;
  q.push(1);

  while (q.size()) {
    int W = q.front();
    q.pop();
    if (W == 0) break;
    int R = total - W;
    for (int take = 0; take <= k; ++take) {
      if (take <= W && k - take <= R) {
        int nn = W - take + (k - take);
        if (last[nn] == -1) {
          last[nn] = W;
          q.push(nn);
        }
      }
    }
  }

  // R - L = chain[i] - chain[i - 1]
  // k - 2*L

  vector<int> chain;
  chain.pb(0);
  while (chain.back() != 1) chain.pb(last[chain.back()]);

  reverse(all(chain));
  
  for (int i = 1; i < chain.size(); ++i) {
    int from_left = (k - (chain[i] - chain[i-1])) / 2;
    int gap = pos + (chain[i - 1] - from_left);

    add(ans, gap, pos + chain[i - 1] + zeros + (k - from_left - 1), s);
  }

}

vector<pair<int, int> > go(string s) {

  vector<pair<int, int> > ans;
  int tot = 0;

  for (auto x : s) if (x == '1') tot++;

  while (true) {
    int kek = 0;
    int i = s.size() - 1;

    for (; i >= 0; --i) {
      if (s[i] == '1') kek++;
      else break;
    }

    if (kek + 1 >= tot) {
      if (kek + 1 == tot && k == 1) {
        int a = 0;
        while (s[a] == '0') a++;
        add(ans, 0, a, s);
      } 
      break;
    }

    int rem = k + 1;
    vector<int> indices;

    if (tot - kek > k) {

      for (; i >= 0; --i) {
        if (s[i] == '1') {
          indices.pb(i);
          rem--;
          if (rem == 0) break;
        }
      }
      reverse(all(indices));

    }

    else {
      i = 0;
      for (; i < s.size(); ++i) {
        if (s[i] == '1') {
          indices.pb(i);
          rem--;
          if (rem == 0) break;
        }
      }
      i++;
      kek = n - i;
    }

    int a = indices[0], b = indices.back();

    for (int j = 0; j < k; ++j) {
      if (j % 2 == 0) {
        int T = b;
        while (s[T] == '0') {
          T--;
          assert(T >= 0);
        }
        for (int e = a; e <= b; ++e) {
          if (s[e] == '1') {
           // cout << e << endl;
            assert(e+1 <= T);
            add(ans, e+1, T, s);
            break;
          }
        }
      }
      else {
        int T = a;
        while (s[T] == '0') {
          T++;
          assert(T < s.size());
        }
        for (int e = b; e >= a; --e) {
          if (s[e] == '1') {
            assert(T <= e-1);
            add(ans, T, e-1, s);
            break;
          }
        }
      }
    }

    int zz = 1;

    for (int e = a; e <= b; ++e) {

      if (s[e] == '1') {
        if (zz) zz--;
        else {
          assert(e <= n-kek-1);
          add(ans, e, n - kek - 1, s);
          break;
        }
      }

    }


  }

  if (k % 2 != 0) {
    spec_solve(s, ans);
  } 

  gg = s;

  return ans;





}

void solve2(string s, string t) {
  
  auto ans = go(s);
  auto Q = gg;
  auto ans2 = go(t);

  if (gg != Q) {
    cout << "-1\n";
    return;
  }

  cout << ans.size() + ans2.size() << '\n';
  for (auto x : ans) cout << x.x+1 << " " << x.y + 1 << '\n';
  reverse(all(ans2));
  for (auto x : ans2) cout << x.x+1 << " " << x.y + 1 << '\n';

}

void solve() {

  cin >> n >> k;

  string s, t;
  cin >> s >> t;

  int a = 0, b = 0;
  for (auto x : s) if (x == '1') a++;
  for (auto x : t) if (x == '1') b++;

  if (a != b) {
    cout << "-1\n";
    return;
  }

  if (s == t) {
    cout << "0\n";
    return;
  }

  if (k == 0) {
    cout << "-1\n";
    return;
  }

  if (k > a) {
    cout << "-1\n";
    return;
  }

  if (k == a) {
    solve1(s, t);
  }
  else {
    solve2(s, t);
  }

}

int main(){
#ifdef LOCAL
	freopen("G_input.txt", "r", stdin);
	//freopen("G_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  int t;
  cin >> t;

  for (int i = 0; i < t; ++i) {
    solve();
  }

}