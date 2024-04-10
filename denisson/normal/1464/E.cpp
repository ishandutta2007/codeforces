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

const int mod = 998244353;

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




class GaussModulo {
    const int mod = 998244353;

public:
    enum GaussSolution {
        ZERO, ONE, MANY
    };

    int n;
    GaussSolution solutions_cnt;
    vector<int> solutions;

    // eqs = A|b
    // A*x = b
    GaussModulo(vector< vector<int> >& eqs) {
        n = (int)eqs.back().size() - 1;
        solutions.resize(n, 0);

        int cur_eq = 0;
        for (int v = 0; v < n; v++) {
            int correct_eq_num = -1;
            for (int eq_num = cur_eq; eq_num < eqs.size(); eq_num++) {
                if (eqs[eq_num][v] != 0) {
                    correct_eq_num = eq_num;
                    break;
                }
            }

            if (correct_eq_num == -1) continue;

            swap(eqs[cur_eq], eqs[correct_eq_num]);

            int rev_val = get_rev(eqs[cur_eq][v]);
            for (int i = v; i < eqs[cur_eq].size(); i++) {
                eqs[cur_eq][i] = mult(eqs[cur_eq][i], rev_val);
            }

            for (int eq_num = cur_eq + 1; eq_num < eqs.size(); eq_num++) {
                int cur_val = eqs[eq_num][v];
                for (int i = v; i < eqs[eq_num].size(); i++) {
                    eqs[eq_num][i] -= mult(eqs[cur_eq][i], cur_val);
                    if (eqs[eq_num][i] < 0) eqs[eq_num][i] += mod;
                }
            }

            cur_eq++;
        }

        for (int i = cur_eq; i < eqs.size(); i++) {
            if (eqs[i].back() != 0) {
                solutions_cnt = ZERO;
                return;
            }
        }

        if (cur_eq < n) {
            solutions_cnt = MANY;
        } else {
            solutions_cnt = ONE;
        }

        for (int v = n - 1; v >= 0; v--) {
            int pos = -1;
            for (int i = 0; i + 1 < eqs[v].size(); ++i) {
                if (eqs[v][i] != 0) {
                    pos = i;
                    break;
                }
            }
            if (pos == -1) continue;
            solutions[pos] = eqs[v].back();

            for (int eq_num = v - 1; eq_num >= 0; eq_num--) {
                eqs[eq_num].back() -= mult(eqs[eq_num][pos], eqs[v].back());
                if (eqs[eq_num].back() < 0) eqs[eq_num].back() += mod;
                eqs[eq_num][pos] = 0;
            }
        }
    }

private:
    int mult(int a, int b){
        return a * (ll)b % mod;
    }
    
    int pow(int a, int n) {
        int res = 1;
        while (n) {
            if (n & 1) res = mult(res, a);
            a = mult(a, a);
            n >>= 1;
        }
        return res;
    }

    int get_rev(int val) {
        return pow(val, mod - 2);
    }
};




int n, m;
vector<int> g[100007];

int dp[100007];

int gr(int v) {
  if (dp[v] != -1) return dp[v];

  vector<int> t;

  for (int to : g[v]) t.pb(gr(to));

  sort(all(t));
  t.resize(unique(all(t)) - t.begin());

  for (int i = 0; i < t.size(); ++i) if (t[i] != i) return dp[v] = i;

  return dp[v] = t.size();
}

int cnt[555];

int main(){
#ifdef LOCAL
	freopen("O_input.txt", "r", stdin);
	//freopen("O_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    int w1, w2;
    cin >> w1 >> w2; --w1; --w2;
    g[w1].pb(w2);
  }

  fill(dp, dp + n, -1);

  for (int i = 0; i < n; ++i) if (dp[i] == -1) gr(i);

  for (int i = 0; i < n; ++i) cnt[dp[i]]++;    

  vector<vector<int>> eqs;

  int rev = bp(n + 1, mod - 2);

  const int DD = 512; // 512;

  for (int x = 0; x < DD; ++x) {
    vector<int> eq(DD + 1, 0);

    add(eq[x], 1);
    for (int y = 0; y < DD; ++y) {
      dec(eq[x ^ y], mult( cnt[y], rev ));
    }

    if (x != 0) {
      add(eq[DD], rev);
    }

    eqs.pb(eq);

  }

  // pper(eqs);

  auto gm = GaussModulo(eqs);

  cout << gm.solutions[0];
}