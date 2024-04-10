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

int n, c;
vector<int> guessed;

const int N = 1000007;
vector<int> allp[N];

int xx[N];
int hh[N];

vector<int> ask(vector<int> queries) {
#ifdef LOCAL
  int www = 0;
  for (int i = 0; i < guessed.size(); ++i) {
    xx[i + 1] = guessed[i];
  }
  for (int i = 1; i < N; ++i) {
    hh[i] = 0;
    for (int j = i; j < N; j += i) if (xx[j]) hh[i] ^= j;
  }

  int q = queries.size();
  vector<int> ans(q);

  for (int a = 0; a < q; ++a) {

    int t = 0;
    int num = queries[a];

    for (int mask = 0; mask < (1<<allp[num].size()); ++mask) {
      int P = 1;
      for (int j = 0; j < allp[num].size(); ++j) {
        if ((1<<j)&mask) {
          P *= allp[num][j];
        }
      }
      t ^= hh[P];
    }

    ans[a] = t;
    //per(queries[a], t, R);
    //assert(t==R);

  }

 // per("FINISH");

  return ans;

#else 
  int q = queries.size();
  cout << q << endl;
  for (auto x : queries) cout << x << " ";
  cout << endl;
  vector<int> ans(q);
  for (auto &x : ans) cin >> x;
  return ans;
#endif
}

const int ITER = 5;
const int G = 22;

const int CNT = 300;

vector<vector<int> > do_all(vector<int> elements, int need) {

  int M = elements.size();
  vector<bool> have(M+1, false);

  vector<vector<int> > ans;
  if (M <= 5) {
    for (int i = 0; i < (1<<M); ++i) {
      int x = 0;
      for (int j = 0; j < M; ++j) {
        if ((1<<j)&i) x ^= elements[j];
      }
      if (x == need) {
        int cnt = __builtin_popcount(i);
        if (!have[cnt]) {
          vector<int> z;
          for (int j = 0; j < M; ++j) {
            if ((1<<j)&i) z.pb(elements[j]);
          }
          ans.pb(z);
          have[cnt] = true;
        }
      }
    }
    return ans;
  }

  for (int i = 0; i < ITER; ++i) {
    random_shuffle(all(elements));
    vector<int> t(G, -1);
    vector<bitset<CNT> > wh(G, 0);

    for (int j = 0; j < elements.size(); ++j) {
      bitset<CNT> tut;
      tut[j] = 1;
      int tt = elements[j];

      for (int e = G-1; e >= 0; --e) {
        if ((1<<e)&tt) {
          if (t[e] == -1) {
            t[e] = tt;
            wh[e] = tut;
            break;
          }
          else {
            if (rand()%2) {
              swap(t[e], tt);
              swap(wh[e], tut);
            }
            tt ^= t[e];
            tut ^= wh[e]; 
          }
        }
      }
    }

    //per(t, wh);


    bitset<CNT> tut;
    int tt = need;

    for (int i = 0; i < elements.size(); ++i) {
      if (rand()%2) {
        tt ^= elements[i];
        tut[i] = 1;
      }
    }

    for (int e = G-1; e >= 0; --e) {
      if ((1<<e)&tt) {
        if (t[e] == -1) {
          break;
        }
        else {
          tt ^= t[e];
          tut ^= wh[e]; 
        }
      }
    }

    if (tt == 0) {
      int cnt = tut.count();
      if (!have[cnt]) {
        vector<int> z;
        for (int j = 0; j < M; ++j) {
          if (tut[j]) z.pb(elements[j]);
        }
        ans.pb(z);
        have[cnt] = true;
      }
    }

  }

  return ans;

}


int main(){
#ifdef LOCAL
  srand(time(0));
  c = 1000000;
  guessed.assign(c, 0);
  n = 0;
  for (int i = 0; i < c; ++i) {
    guessed[i] = rand() % 2;
    n += guessed[i];
  }
#else 
  srand(time(0));
  cin >> c >> n;
#endif

 // deg.pb(1);
 // for (int i = 0; i < 120; ++i) deg.pb(deg.back()*2);

  for (int i = 2; i < N; ++i) {
    if (!allp[i].size()) {
      for (int j = i; j < N; j += i) allp[j].pb(i);
    }
  }

  vector<int> queries;
  vector<bool> good;

  vector<int> pos(c, -1);
  int t = 0;


  for (int i = 1; i <= c; ++i) {
    bool take = true;
    for (auto x : allp[i]) {
      if ((ll) i % ((ll) x*x) == 0) take = false;
    }
    if (take) {
      queries.pb(i);
      pos[i - 1] = t++;
    }
    good.pb(take);
  }



  vector<int> ans = ask(queries);
  
  vector<int> want(c, -1);

  //per(ans[pos[41 - 1]], ans[pos[82 - 1]]);

  vector<vector<vector<int> > > possibilities;

  for (int i = c; i >= 1; --i) {
    if (want[i - 1] != -1) continue;
    if (!good[i - 1]) continue;

    vector<int> unknown;
    int x = 0;
    for (int j = i; j <= c; j += i) {
      if (want[j - 1] == -1) unknown.pb(j);
      else if (want[j - 1] == 1) x ^= j;
    }


    for (int mask = 0; mask < (1<<allp[i].size()); ++mask) {
      int P = 1;
      for (int j = 0; j < allp[i].size(); ++j) {
        if ((1<<j)&mask) {
          P *= allp[i][j];
        }
      }
      x ^= ans[pos[P - 1]];
    }

    bool decided = false;

    auto Q = do_all(unknown, x);
    possibilities.pb(Q);

   // assert(unknown.size() <= CNT);

    //per(i, unknown, Q.size(), x);

   // if (Q.size() > 1) per(i, Q);

    for (auto x : unknown) want[x - 1] = 0;
    for (auto x : Q[0]) want[x - 1] = 1;

  }

  int tt = 0;
  for (auto x : want) tt += x;

//  exit(0);

  vector<vector<vector<int> > > guaranteed, choose;
  int tttt = 0;

  for (auto x : possibilities) {
    if (x.size() == 1) {
      tttt += x[0].size();
      guaranteed.pb(x);
    }
    else choose.pb(x);
  }

  while (tt != n) {
    tt = tttt;
    vector<vector<int> > tot;
    for (auto x : choose) {
      int R = rand()%x.size();
      tot.pb(x[R]);
      tt += x[R].size();
    }

    if (tt == n) {

      for (auto &x : want) x = 0;
      for (auto x : tot) for (auto y : x) want[y - 1] = 1;
      for (auto A : guaranteed) for (auto x : A) for (auto y : x) want[y - 1] = 1;
    }

   // per(tt, n);
  }
  //per(tt, n);
  //assert(tt == n);

  for (int i = 0; i < c; ++i) if (want[i]) cout << i+1 << " ";
  cout << endl;



}