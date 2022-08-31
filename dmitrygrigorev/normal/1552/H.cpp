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

#ifdef LOCAL
  int p1, p2, p3, p4;
#endif

int ask(int x, int y) {

  vector<pair<int, int> > res;
  for (int i = 1; i <= 200; i += x) {
    for (int j = 1; j <= 200; j += y) {
      res.pb(mp(i, j));
    }
  }

  #ifdef LOCAL
  cout << "QUERY" << endl;
  int ta = 0;
  for (auto e : res) {
    if (e.x >= p1 && e.x <= p2 && e.y >= p3 && e.y <= p4) ta++;
  }
  return ta;
#endif

  cout << "? " << res.size() << endl;
  for (auto x : res) cout << x.x << " " << x.y << " ";
  cout << endl;

  int t;
  cin >> t;

  return t;

}

const int K = 14;

int main(){
#ifdef LOCAL
  srand(time(0));
  //freopen("O_input.txt", "r", stdin);
  //freopen("O_output.txt", "w", stdout);
  p1 = rand()%200 + 1, p2 = rand()%200 + 1, p3 = rand()%200+1, p4 = rand()%200+1;
  while (p2 <= p1) p1 = rand()%200 + 1, p2 = rand()%200 + 1;
  while (p4 <= p3) p3 = rand()%200 + 1, p4 = rand()%200 + 1;
#endif
  ios_base::sync_with_stdio(0);
  cin.tie(0);


  int sq = ask(1, 1);
  int nq = ask(K, 1);

  vector<pair<int, int> > rem;
  for (int dx = 1; dx < 200; ++dx) {
    for (int dy = 1; dy < 200; ++dy) {
      if ((dx + 1) * (dy + 1) == sq) {
        bool can = false;
        if (dx % K != K - 1) if ((dx / K) * (dy + 1) == nq) can = true;
        if (((dx / K) + 1) * (dy + 1) == nq) can = true;
        if (can) rem.pb(mp(dx, dy));
      }
    }
  }

  while (rem.size() > 1) {
    int best = rem.size();
    int bx = -1, by = -1;

    for (int a = 1; a <= 200; ++a) {
      for (int b = 1; b <= 200; ++b) {
        map<int, int> tt;
        int tut = 0;

        for (auto p : rem) {
          int dx = p.x, dy = p.y;
          tt[((dx / a) + 1) * ((dy / b) + 1)]++;
          if (dy % b != (b - 1)) tt[((dx / a) + 1) * (dy / b)]++;
          if (dx % a != (a - 1)) tt[(dx / a) * ((dy / b) + 1)]++;
          if (dx % a != (a - 1) && dy % b != (b - 1)) tt[(dx / a) * (dy / b)]++;
        }

        for (auto e : tt) tut = max(tut, e.y);
        if (tut < best) {
          best = tut;
          bx = a;
          by = b;
        }

      }
    }

    int T = ask(bx, by);
    vector<pair<int, int> > nrem;

    for (auto x : rem) {
      bool can = false;
      int dx = x.x, dy = x.y;
      int a = bx, b = by;
      if (((dx / a) + 1) * ((dy / b) + 1) == T) can = true;
      if (dy % b != (b - 1)) if (((dx / a) + 1) * (dy / b) == T) can = true;
      if (dx % a != (a - 1)) if ((dx / a) * ((dy / b) + 1) == T) can = true;
      if (dx % a != (a - 1) && dy % b != (b - 1)) if ((dx / a) * (dy / b) == T) can = true;
      if (can) nrem.pb(x);
    }

    rem = nrem;

  }

  cout << "! " << 2*(rem[0].x + rem[0].y) << endl;
  #ifdef LOCAL
  int rp = (p2 - p1) * 2 + (p4 - p3) * 2;
  cout << rp << endl;
#endif
  


}