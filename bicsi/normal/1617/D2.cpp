#include <bits/stdc++.h>

using namespace std;

string S = "101010101010101";
mt19937 rng(42);
const int DRY = 0; // 1;

int readn() { 
  if (DRY) {
    int n = (rng() % 15) * 3 + 6;
    int k = 0;
    while (k <= n / 3 || k >= 2 * n / 3)
      k = rng() % n;
    S.clear();
    for (int i = 0; i < n; ++i)
      S += (i < k ? '0' : '1');
    shuffle(S.begin(), S.end(), rng);
    return S.size();
  }
  int n; cin >> n;
  assert(n != -1);
  return n;
}
int ask(int a, int b, int c) {
  assert(a != b && b != c && c != a);
  if (DRY) {
    int s = (int)S[a] - '0' + (int)S[b] - '0' + (int)S[c] - '0';
    // cerr << a << " " << b << " " << c << " -> " << s << endl;
    if (s > 1) return 1;
    return -1;
  }

  cout << "? " << a + 1 << " " << b + 1 << " " << c + 1 << endl;
  int ans; cin >> ans;
  assert(ans != -1);
  if (ans == 0) return -1;
  return 1;
}
void answer(string s) {
  if (DRY) {
    assert(s == S);
    cerr << "ok " << s << "=" << S << endl;
  }

  vector<int> ans;
  for (int i = 0; i < (int)s.size(); ++i)
    if (s[i] == '0')
      ans.push_back(i);
  cout << "! " << ans.size() << " ";
  for (auto x : ans)
    cout << x + 1 << " "; 
  cout << endl;
  return;

}

int main() {
  //ios_base::sync_with_stdio(false);
  //cin.tie(0);

  int t; cin >> t;
  while (t--) {
    shuffle(S.begin(), S.end(), rng);
    int n = readn(); 
    vector<int> buck(n / 3);
    for (int i = 0; i < n / 3; ++i)
      buck[i] = ask(3 * i, 3 * i + 1, 3 * i + 2);
    //cerr << "n=" << n << endl;
    /* 
    for (int i = 0; i < n/3; ++i)
      cerr << (buck[i] == 1 ? "+" : "-");
    cerr << endl;
    */
    int posb = -1, negb = -1;
    for (int i = 0; i < n / 3; ++i)
      if (buck[i] == 1)
        posb = i;
      else 
        negb = i;
    assert(posb != -1);
    assert(negb != -1);
    
    string s(n, '?');
    int neg = -1, pos = -1;
    auto mark = [&](int i, int val) {
      s[i] = (val < 0 ? '0' : '1');
      if (val < 0) neg = i;
      if (val > 0) pos = i;
    };

    auto ugly = [&]() {
      int a1 = ask(3 * posb, 3 * posb + 1, 3 * negb);
      if (a1 < 0) mark(3 * negb, -1);

      int a2 = ask(3 * posb, 3 * posb + 1, 3 * negb + 1);
      if (a2 < 0) mark(3 * negb + 1, -1);  

      if (a1 < 0 || a2 < 0) {
        mark(3 * posb + 2, +1);
        return;
      }
      
      mark(3 * posb, +1);
      mark(3 * posb + 1, +1);

      int b1 = ask(3 * negb, 3 * negb + 1, 3 * posb);
      if (b1 < 0) {
        mark(3 * negb, -1);
        mark(3 * negb + 1, -1);
        return;
      }
      int b2 = ask(3 * negb, 3 * negb + 2, 3 * posb);
      if (b2 < 0) {
        mark(3 * negb, -1);
        mark(3 * negb + 2, -1);
        return;
      }
      mark(3 * negb + 1, -1);
      mark(3 * negb + 2, -1);
      mark(3 * negb, +1);
      return;
    };
    
    ugly();
    assert(pos != -1);
    assert(neg != -1);
    for (int i = 0; i < 3; ++i) {
      for (int j : {posb, negb}) {
        int k = i + 3 * j;
        if (s[k] == '?')
          mark(k, ask(k, pos, neg));
      }
    }
    //cerr << "s=" << s << endl;

    for (int i = 0; i < n/3; ++i) {
      if (i == posb || i == negb) continue;
      
      int a1 = ask(3 * i, 3 * i + 1, buck[i] == 1 ? neg : pos);
      if (a1 == buck[i]) {
        mark(3 * i, buck[i]);
        mark(3 * i + 1, buck[i]);
        mark(3 * i + 2, ask(3 * i + 2, pos, neg));
      } else {
        mark(3 * i + 2, buck[i]);
        int a2 = ask(3 * i, pos, neg);
        mark(3 * i, a2);
        mark(3 * i + 1, -a2);
      }
    }

    answer(s);
  }
  return 0;
}