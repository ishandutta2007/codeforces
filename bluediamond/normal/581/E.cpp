#include <bits/stdc++.h>

bool home = 1;

using namespace std;

typedef long double ld;
const int N = (int)2e5 + 7;
int e;
int s;
int n;
int q;
int t[N];
int x[N];
int fq[N];
int frq[4];

struct Segment {
  int l;
  int r;
  int value;
};

vector<int> operator + (vector<int> a, vector<int> b) {
  assert((int) a.size() == (int) b.size());
  for (int i = 0; i < (int) a.size(); i++) {
    a[i] += b[i];
  }
  return a;
}


vector<int> operator - (vector<int> a, vector<int> b) {
  assert((int) a.size() == (int) b.size());
  for (int i = 0; i < (int) a.size(); i++) {
    a[i] -= b[i];
  }
  return a;
}


signed main() {
#ifdef ONLINE_JUDGE
  home = 0;
#endif

  if (home) {
    freopen("I_am_iron_man", "r", stdin);
    /// freopen ("output.txt","w",stdout);
  }
  else {
    ios::sync_with_stdio(0); cin.tie(0);
  }

  cin >> e >> s >> n >> q;
  e--;
  for (int i = 1; i <= n; i++) {
    cin >> t[i] >> x[i];
  }

  for (int i = 1; i <= q; i++) {
    cin >> fq[i];
    fq[i] += s;
  }

  vector<vector<int>> events;
  for (int j = 1; j <= n; j++) {
    events.push_back({ x[j], +1, t[j] });
    events.push_back({ x[j] + s, -1, t[j] });
  }
  for (int i = 1; i <= q; i++) {
    events.push_back({ fq[i], 2 });
  }
  events.push_back({ e + 1, 3 });

  sort(events.begin(), events.end());

  vector<Segment> segs;

  int last_time;
  bool first_time = true;

  for (auto& v : events) {
    assert((int)v.size() >= 2);
    int Time = v[0];
    int Type = v[1];
    if (!first_time) {
      int maximum = 0;
      for (int j = 1; j <= 3; j++) {
        if (frq[j] > 0) {
          maximum = j;
        }
      }
      segs.push_back({ last_time, Time - 1, maximum });
    }
    last_time = Time;
    first_time = false;
    if (abs(Type) == 1) {
      assert((int)v.size() == 3);
      frq[v[2]] += Type;
    }
    else {
      assert((int)v.size() == 2);
      assert(Type == 2 || Type == 3);
    }
  }

  int Y = (int)segs.size();
  vector<vector<int>> partialSum(Y + 1, vector<int> (4, 0));

  for (int i = 1; i <= Y; i++) {
    partialSum[i][segs[i - 1].value] = segs[i - 1].r - segs[i - 1].l + 1;
    partialSum[i] = partialSum[i - 1] + partialSum[i];
  }


  for (int i = 1; i <= q; i++) {
    vector<int> u(4, 0);

    int L = fq[i], R = e;


    if (L <= R) {
      int last = -1, first = -1;

      {
        int low = 0, high = Y - 1;
        while (low <= high) {
          int i = (low + high) / 2;
          if (segs[i].r <= R) {
            last = i;
            low = i + 1;
          } else {
            high = i - 1;
          }
        }
      }

      {
        int low = 0, high = Y - 1;
        while (low <= high) {
          int i = (low + high) / 2;
          if (L <= segs[i].l) {
            first = i;
            high = i - 1;
          } else {
            low = i + 1;
          }
        }
      }

      assert(first != -1);
      assert(last != -1);

      u = partialSum[last + 1] - partialSum[first];

    }
    if (u[0]) {
      cout << "-1 -1\n";
    }
    else {
      cout << u[1] << " " << u[2] << "\n";
    }
  }
}