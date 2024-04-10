#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

struct Tr {
  int t1[4 * 100007];
  int t2[4 * 100007];

  void build(int v, int vl, int vr, pair<int, int>* a) {
    if (vl == vr) {
      t1[v] = a[vl].x;
      t2[v] = a[vl].y;
    } else {
      int vm = (vl + vr) >> 1;
      build(v * 2 + 1, vl, vm, a);
      build(v * 2 + 2, vm + 1, vr, a);
      t1[v] = max(t1[v * 2 + 1], t1[v *2 + 2]);
      t2[v] = min(t2[v * 2 + 1], t2[v *2 + 2]);
    }
  }

  pair<int, int> get(int v, int vl, int vr, int l, int r) {
    if (r < vl || l > vr) return mp(-1, 1e9 + 7);
    if (vl >= l && vr <= r) return mp(t1[v], t2[v]);
    int vm = (vl + vr) >> 1;
    auto now1 = get(v * 2 + 1, vl, vm, l, r);
    auto now2 = get(v * 2 + 2, vm + 1, vr, l, r);
    return mp(max(now1.x, now2.x), min(now1.y, now2.y));
  }
} t1, t2;

int n, m;
int a[100007];
pair<int, int> f1[100007];
pair<int, int> f2[100007];

int dp[100007][2];
pair<int, int> p[100007][2];

int uk1 = -1, uk2 = -1;

int get(int v, int ty) {
  if (v == -1) {
    if (ty == 0) return uk1;
      return uk2;
  }
  if (ty == 0) {
    int vl = v - 1, vr = n;
    while (vl + 1 < vr) {
      int vm = (vl + vr) >> 1;
      auto now = t1.get(0, 0, n - 1, v, vm);
      if (a[v] >= now.x && a[v] <= now.y) vl = vm; else vr = vm;
    }
    return vl;
  } else {
    int vl = v - 1, vr = n;
    while (vl + 1 < vr) {
      int vm = (vl + vr) >> 1;
      auto now = t2.get(0, 0, n - 1, v, vm);
      if (a[v] >= now.x && a[v] <= now.y) vl = vm; else vr = vm;
    }
    return vl;
  }
}

int main(){
#ifdef LOCAL
	freopen("F_input.txt", "r", stdin);
	//freopen("F_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    cin >> a[i] >> f1[i].x >> f1[i].y >> f2[i].x >> f2[i].y;
  }

  t1.build(0, 0, n - 1, f1);
  t2.build(0, 0, n - 1, f2);

  for (int i = 0; i < n; ++i) {
    if (uk1 == i - 1) {
      if (0 >= f1[i].x && 0 <= f1[i].y) uk1++;
    }
    if (uk2 == i - 1) {
      if (0 >= f2[i].x && 0 <= f2[i].y) uk2++;
    }
  }

  dp[0][0] = uk2;
  dp[0][1] = uk1;

  for (int i = 0; i < n; ++i) {

//    cout << i << ' ' << dp[i][0] << ' ' << dp[i][1] << endl;

    dp[i + 1][0] = dp[i + 1][1] = -1;
    if (dp[i][0] >= i) {
      if (a[i] >= f1[i].x && a[i] <= f1[i].y) {
        if (dp[i][0] > dp[i + 1][0]) {
          dp[i + 1][0] = max(dp[i + 1][0], dp[i][0]);
          p[i + 1][0] = mp(i, 0);
        }
      }
    }
    int le = get(i - 1, 0);
    if (dp[i][0] >= i - 1 && le >= i) {
      if (a[i] >= f2[i].x && a[i] <= f2[i].y) {
        if (le > dp[i + 1][1]) {
          dp[i + 1][1] = max(dp[i + 1][1], le);
          p[i + 1][1] = mp(i, 0);
        }
      }
    }


    int ri = get(i - 1, 1);
    if (dp[i][1] >= i - 1 && ri >= i) {
      if (a[i] >= f1[i].x && a[i] <= f1[i].y) {
        if (ri > dp[i + 1][0]) {
          dp[i + 1][0] = max(dp[i + 1][0], ri);
          p[i + 1][0] = mp(i, 1);
        }
      }
    }

    if (dp[i][1] >= i) {
      if (a[i] >= f2[i].x && a[i] <= f2[i].y) {
        if (dp[i][1] > dp[i + 1][1]) {
          dp[i + 1][1] = max(dp[i + 1][1], dp[i][1]);
          p[i + 1][1] = mp(i, 1);
        }
      }
    }

  }

  //cout << dp[n][0] << ' ' << dp[n][1] << endl;

  pair<int, int> last = mp(-1, -1);

  if (dp[n][0] == n - 1) {
    cout << "Yes\n";
    last = mp(n, 0);
  } else if (dp[n][1] == n - 1) {
    cout << "Yes\n";
    last = mp(n, 1);
  }


  if (last.y != -1) {

    vector<int> ans;
    for (int it = 0; it < n; ++it) {
      auto prev = p[last.x][last.y];
      ans.pb(last.y);
      last = prev; 
    }

    reverse(all(ans));
    for (int x : ans) cout << x << ' ';

    exit(0);
  }

  cout << "No\n";
}