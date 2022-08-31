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

const int N = 20007;
const int MAXK = 33;
const int LG = 16;

int binup[N][LG][MAXK];
int longest[N][LG][MAXK];

vector<pair<int, int> > rmq;

void build(int i, int l, int r, vector<int> &v) {
	if (r - l == 1) {
		rmq[i] = mp(v[l] + l, l);
		return;
	}

	int mid = (l+r)/2;
	build(2*i+1, l, mid, v);
	build(2*i+2, mid, r, v);

	rmq[i] = max(rmq[2*i+1], rmq[2*i+2]);
}

pair<int, int> get(int i, int l, int r, int l1, int r1) {
	if (l1 >= r1) return mp(-1e9, -1);
	if (l == l1 && r == r1) return rmq[i];

	int mid = (l+r)/2;
	return max(get(2*i+1, l, mid, l1, min(r1, mid)), get(2*i+2, mid, r, max(l1, mid), r1));

}

int main(){
#ifdef LOCAL
	freopen("H_input.txt", "r", stdin);
	//freopen("H_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, q;
	cin >> n >> q;

	vector<int> v(n);
	for (auto &x : v) cin >> x;

	rmq.resize(4 * n);
	build(0, 0, n, v);

	for (int i = n - 1; i >= 0; --i) {

		for (int j = 0; j < MAXK; ++j) {
			int pos = i + v[i] + j;
			longest[i][0][j] = pos;
			if (pos >= n - 1) {
				binup[i][0][j] = n - 1;
			}
			else {
				if (j == 0) {
					auto p = get(0, 0, n, i + 1, i + v[i] + 1);
					pos = p.y;
				}
				binup[i][0][j] = pos;
			}
		}

		for (int j = 1; j < LG; ++j) {
			for (int spend = 0; spend < MAXK; ++spend) {
				binup[i][j][spend] = j;
				longest[i][j][spend] = j;
				for (int p = 0; p <= spend; ++p) {
					int W = binup[i][j - 1][p];
					binup[i][j][spend] = max(binup[i][j][spend], binup[W][j - 1][spend - p]);
					longest[i][j][spend] = max(longest[i][j][spend], longest[W][j - 1][spend - p]);
				}
			}
		}
	}

	//cout << binup[10][0][0] << '\n';

	for (int i = 0; i < q; ++i) {
		int l, r, k;
		cin >> l >> r >> k;
		l--, r--;

		if (l == r) {
			cout << "0\n";
			continue;
		}

		vector<int> opt_j(k + 1, l);
		int ans = 0;
		for (int j = LG - 1; j >= 0; --j) {
			int optimum = 0;
			for (int p = 0; p <= k; ++p) {
				optimum = max(optimum, longest[opt_j[p]][j][k - p]);
			}
			if (optimum >= r) continue;
			ans += (1<<j);
			vector<int> nopt(k + 1, l);
			for (int a = 0; a <= k; ++a) {
				for (int b = 0; a + b <= k; ++b) {
					nopt[a + b] = max(nopt[a + b], binup[opt_j[a]][j][b]);
				}
			}
			opt_j = nopt;
		}

		cout << ans+1 << '\n';

	}



}