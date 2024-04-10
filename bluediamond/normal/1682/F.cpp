#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const ll MOD = (ll) 1e9 + 7;

ll repmod(ll x) {
  x %= MOD;
  if (x < 0) x += MOD;
  return x;
}

const int N = (int) 2e5 + 7;
int n, q, lq[N], rq[N];
ll a[N], b[2][N], sum[2][N], aib[N], print[N];

void clraib() {
  for (int i = 1; i <= n; i++) {
    aib[i] = 0;
  }
}

void addaib(int i, ll x) {
  x = repmod(x);
  while (i <= n) {
    aib[i] = repmod(aib[i] + x);
    i += i & (-i);
  }
}

ll getaib(int i) {
  ll sol = 0;
  while (i) {
    sol = repmod(sol + aib[i]);
    i -= i & (-i);
  }
  return sol;
}


signed main() {
#ifndef ONLINE_JUDGE
  freopen ("input.txt", "r", stdin);
#endif

#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(0); cin.tie(0);
#endif // ONLINE_JUDGE

  cin >> n >> q;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= n; i++) {cin >> b[0][i]; b[1][i] = -b[0][i];}

  for (int it = 0; it < 2; it++) {
    for (int i = 1; i <= n; i++) {
      sum[it][i] = sum[it][i - 1] + b[it][i];
      if (b[it][i] < 0) {
        b[it][i] = 0;
      }
    }
    for (int i = n; i >= 1; i--) {
      sum[it][i] = sum[it][i - 1];
    }
  }

  for (int iq = 1; iq <= q; iq++) {
    cin >> lq[iq] >> rq[iq];
  }

  for (int it = 0; it < 2; it++) {
    {
      vector<ll> some_guys;

      vector<pair<ll, int>> people;
      vector<pair<ll, int>> ques;

      for (int j = 1; j <= n; j++) {
        some_guys.push_back(-sum[it][j]);
        some_guys.push_back(-sum[it][j] - 1);

        people.push_back({-sum[it][j], j});
      }

      for (int iq = 1; iq <= q; iq++) {
        ques.push_back({-sum[it][lq[iq]] - 1, iq});
      }

      clraib();

      sort(people.begin(), people.end());
      sort(ques.begin(), ques.end());

      int p = 0;
      for (auto &Q : ques) {
        int iq = Q.second;
        while (p < (int) people.size() && people[p].first <= Q.first) {
          int j = people[p++].second;
          addaib(j, -repmod(a[j]) * repmod(b[it][j]));
        }
        print[iq] = repmod(print[iq] + getaib(rq[iq]) - getaib(lq[iq] - 1));
      }
    }
    {
      vector<ll> some_guys;

      vector<pair<ll, int>> people;
      vector<pair<ll, int>> ques;

      for (int j = 1; j <= n; j++) {
        some_guys.push_back(sum[it][j]);

        people.push_back({sum[it][j], j});
      }

      for (int iq = 1; iq <= q; iq++) {
        ques.push_back({sum[it][lq[iq]], iq});
      }

      clraib();

      sort(people.begin(), people.end());
      sort(ques.begin(), ques.end());

      int p = 0;
      for (auto &Q : ques) {
        int iq = Q.second;
        while (p < (int) people.size() && people[p].first <= Q.first) {
          int j = people[p++].second;
          addaib(j, repmod(a[j]) * repmod(b[it][j]));
        }
        print[iq] = repmod(print[iq] + getaib(rq[iq]) - getaib(lq[iq] - 1));
      }
    }
    {
      vector<ll> some_guys;

      vector<pair<ll, int>> people;
      vector<pair<ll, int>> ques;

      for (int j = 1; j <= n; j++) {
        some_guys.push_back(-sum[it][j] - b[it][j]);

        people.push_back({-sum[it][j] - b[it][j], j});
      }

      for (int iq = 1; iq <= q; iq++) {
        ques.push_back({-sum[it][lq[iq]], iq});
      }

      clraib();

      sort(people.begin(), people.end());
      sort(ques.begin(), ques.end());

      int p = 0;
      for (auto &Q : ques) {
        int iq = Q.second;
        while (p < (int) people.size() && people[p].first <= Q.first) {
          int j = people[p++].second;
          addaib(j, -repmod(2 * a[j]) * repmod(sum[it][j] + b[it][j]));
        }
        print[iq] = repmod(print[iq] + getaib(rq[iq]) - getaib(lq[iq] - 1));
      }
    }
    {
      vector<ll> some_guys;

      vector<pair<ll, int>> people;
      vector<pair<ll, int>> ques;

      for (int j = 1; j <= n; j++) {
        some_guys.push_back(-sum[it][j] - b[it][j]);

        people.push_back({-sum[it][j] - b[it][j], j});
      }

      for (int iq = 1; iq <= q; iq++) {
        ques.push_back({-sum[it][lq[iq]], iq});
      }

      clraib();

      sort(people.begin(), people.end());
      sort(ques.begin(), ques.end());

      int p = 0;
      for (auto &Q : ques) {
        int iq = Q.second;
        while (p < (int) people.size() && people[p].first <= Q.first) {
          int j = people[p++].second;
          addaib(j, repmod(2 * a[j]));
        }
        print[iq] = repmod(print[iq] + (repmod(sum[it][lq[iq]]) * (getaib(rq[iq]) - getaib(lq[iq] - 1))));
      }
    }
    {
      vector<ll> some_guys;

      vector<pair<ll, int>> people;
      vector<pair<ll, int>> ques;

      for (int j = 1; j <= n; j++) {
        some_guys.push_back(-sum[it][j]);

        people.push_back({-sum[it][j], j});
      }

      for (int iq = 1; iq <= q; iq++) {
        ques.push_back({-sum[it][lq[iq]] - 1, iq});
      }

      clraib();

      sort(people.begin(), people.end());
      sort(ques.begin(), ques.end());

      int p = 0;
      for (auto &Q : ques) {
        int iq = Q.second;
        while (p < (int) people.size() && people[p].first <= Q.first) {
          int j = people[p++].second;
          addaib(j, -repmod(2 * a[j]));
        }
        print[iq] = repmod(print[iq] + (repmod(sum[it][lq[iq]]) * (getaib(rq[iq]) - getaib(lq[iq] - 1))));
      }
    }
    {
      vector<ll> some_guys;

      vector<pair<ll, int>> people;
      vector<pair<ll, int>> ques;

      for (int j = 1; j <= n; j++) {
        some_guys.push_back(-sum[it][j]);

        people.push_back({-sum[it][j], j});
      }

      for (int iq = 1; iq <= q; iq++) {
        ques.push_back({-sum[it][lq[iq]] - 1, iq});
      }

      clraib();

      sort(people.begin(), people.end());
      sort(ques.begin(), ques.end());

      int p = 0;
      for (auto &Q : ques) {
        int iq = Q.second;
        while (p < (int) people.size() && people[p].first <= Q.first) {
          int j = people[p++].second;
          addaib(j, repmod(2 * a[j]) * repmod(sum[it][j] + b[it][j]));
        }
        print[iq] = repmod(print[iq] + (getaib(rq[iq]) - getaib(lq[iq] - 1)));
      }
    }
  }

  for (int iq = 1; iq <= q; iq++) {
    print[iq] = repmod(print[iq]);
    cout << print[iq] << "\n";
  }

}