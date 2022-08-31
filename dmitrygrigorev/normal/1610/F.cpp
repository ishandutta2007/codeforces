#include <bits/stdc++.h>
#define ll long long
#define db long double
#define ull unsigned long long
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

#define pper(a) cerr << #a << " = " << a << endl;

void per() { cerr << endl; }
template<typename Head, typename... Tail> void per(Head H, Tail... T) { cerr << H << ' '; per(T...); }

template<class T> bool uin(T &a, T b) { return a > b ? (a = b, true) : false; }
template<class T> bool uax(T &a, T b) { return a < b ? (a = b, true) : false; }

template<class U, class V> 
ostream& operator<<(ostream& out, const pair<U, V>& a) {
  return out << "(" << a.x << ", " << a.y << ")";
}

template<class U, class V> 
istream& operator>>(istream& in, pair<U, V>& a) {
  return in >> a.x >> a.y;
}

template<typename W, typename T = typename enable_if<!is_same<W, string>::value, typename W::value_type>::type>
ostream& operator<<(ostream& out, const W& v) { out << "{ "; for (const auto& x : v) out << x << ", "; return out << '}'; }

template<class T>
void readArr(T from, T to) {
  for (auto i = from; i != to; ++i) cin >> *i;
}

mt19937 mrand(1337); 
unsigned int myRand32() {
  return mrand() & (unsigned int)(-1);
}
 
unsigned ll myRand64() {
  return ((ull)myRand32() << 32) ^ myRand32();
}

const int mod = 1000000007;

void add(int& a, int b) {
  a += b; if (a >= mod) a -= mod;
}

void dec(int &a, int b) {
  a -= b; if (a < 0) a += mod;
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

vector<vector<pair<int, int> > > gr_one;
vector<vector<pair<int, int> > > gr_two;

int n, m;

struct Res {
  bool cycle;
  vector<vector<int> > paths;
};

vector<Res> find_eulerian(vector<vector<pair<int, int> > > gr) {

  vector<int> bad;
  for (int i = 0; i < n; ++i) {
    if (gr[i].size() % 2 != 0) bad.pb(i);
  }

  int u = m;

  while (bad.size()) {
    int A = bad.back();
    bad.pop_back();
    int B = bad.back();
    bad.pop_back();

    gr[A].pb(mp(B, 2*u));
    gr[B].pb(mp(A, 2*u+1));
    u++;
  }


  vector<bool> used(u, false);
  vector<bool> wused(n, false);
  vector<Res> tans;

  for (int e = 0; e < n; ++e) {

    if (wused[e]) continue;

    vector<pair<int, int> > st;

    vector<int> ans;

    st.pb(mp(e, -1));
    
    while (st.size()) {
      int W = st.back().x;
      wused[W] = true;
      if (gr[W].size()) {
        int ed = gr[W].back().y;
        int to = gr[W].back().x;
        gr[W].pop_back();
        if (used[ed / 2]) continue;
        used[ed/2] = true;
        st.pb(mp(to, ed ^ 1));
      }
      else {
        ans.pb(st.back().y);
        st.pop_back();
      }
     }


     ans.pop_back();
     vector<vector<int> > q;

     int tindex = -1;
     for (int i = 0; i < ans.size(); ++i) if (ans[i] >= 2*m) tindex = i;

     if (tindex == -1) {
      tans.pb({false, {ans}});
      continue;
     }
     else {
      vector<int> N;
      for (int i = 0; i < ans.size(); ++i) N.pb(ans[(i+tindex)%ans.size()]);
      ans = N;
     }

     vector<int> now;
     for (auto x : ans) {
      if (x >= 2*m) {
        if (now.size()) q.pb(now);
        now.clear();
      }
      else now.pb(x);
     }

     if (now.size()) q.pb(now);

   //  per(q);
     tans.pb({false, q});
   }

   return tans;

}

vector<vector<int> > gg;
vector<int> color;

void dfs(int vertex, int t) {
  color[vertex] = t;
  for (auto to : gg[vertex]) {
    if (color[to] != -1) continue;
    dfs(to, 1 - t);
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

  gr_one.assign(n, {});
  gr_two.assign(n, {});

  vector<pair<int, int> > edges;

  for (int i = 0; i < m; ++i) {
    int a, b, c;
    cin >> a >> b >> c;
    a--, b--;

    edges.pb(mp(a, b));
    edges.pb(mp(b, a));

    if (c == 1) {
      gr_one[a].pb(mp(b, 2*i)), gr_one[b].pb(mp(a, 2*i+1));
    }
    else {
      gr_two[a].pb(mp(b, 2*i));
      gr_two[b].pb(mp(a, 2*i+1));
    }
  }

  int ans = 0;
  for (int i = 0; i < n; ++i) {
    if (gr_one[i].size() % 2 == 0) continue;
    ans++;
  }

  auto E = find_eulerian(gr_one);
  auto F = find_eulerian(gr_two);

  gg.assign(n, {});

  for (auto p1 : E) {
    if (!p1.cycle) {
      for (auto x : p1.paths) {
        if (!x.size()) continue;
        int A = edges[x[0]].x;
        int B = edges[x.back()].y;
        gg[A].pb(B);
        gg[B].pb(A);
      }
    }
  }

  for (auto p2 : F) {
    if (!p2.cycle) {
      for (auto x : p2.paths) {
        if (!x.size()) continue;
        int A = edges[x[0]].x;
        int B = edges[x.back()].y;
        gg[A].pb(B);
        gg[B].pb(A);
      }
    }
  }

  color.assign(n, -1);
  for (int i = 0; i < n; ++i) {
    if (color[i] == -1) dfs(i, 0);
  }

 // per(color);

  for (auto& p1 : E) {
    if (!p1.cycle) {
      for (auto& x : p1.paths) {
        if (!x.size()) continue;
        int A = edges[x[0]].x;
        int B = edges[x.back()].y;
        if (color[A] == 0) {
          for (auto &y : x) y ^= 1;
        }
      }
    }
  }

  for (auto& p2 : F) {
    if (!p2.cycle) {
      for (auto& x : p2.paths) {
        if (!x.size()) continue;
        int A = edges[x[0]].x;
        int B = edges[x.back()].y;
        
        if (color[A] == 1) {
          for (auto &y : x) y ^= 1;
        }
      }
    }
  }

  cout << ans << '\n';
  vector<int> dd(m, -1);

  for (auto p1 : E) {
    for (auto x : p1.paths) {
      for (auto y : x) {
        dd[y/2] = y%2;
      }
    }
  }

  for (auto p2 : F) {
    for (auto x : p2.paths) {
      for (auto y : x) {
        dd[y/2] = y%2;
      }
    }
  }

  for (auto x : dd) cout << x+1;

}