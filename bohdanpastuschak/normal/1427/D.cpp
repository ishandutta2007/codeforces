#include <bits/stdc++.h>
using namespace std;

//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,fma")

typedef long long LL;
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef long double db;

#define MP make_pair
#define PB push_back
#define X first
#define Y second

#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define RFOR(i, b, a) for(int i = (b) - 1; i >= (a); --i)
#define ALL(a) a.begin(), a.end()
#define SZ(a) (int)((a).size())
#define FILL(a, value) memset(a, value, sizeof(a))
#define debug(a) cerr << #a << " = " << a << endl;

template<typename T> void setmax(T& x, T y) {x = max(x, y);}
template<typename T> void setmin(T& x, T y) {x = min(x, y);}

template<typename T> void print(const T& a, ostream& out){	
	for(auto i: a) out << i << ' ';
	out << endl;
}

const double PI = acos(-1.0);
const LL INF = 1e9 + 47;
const LL LINF = INF * INF;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

vector<int> go(vector<int> x){
	vector<int> y;
	for(auto i: x) if (i) y.PB(i);
	return y;
}

void roby(vector<int>& a, vector<int> x){
	vector<vector<int>> b;

	vector<int> curr;
	int ptr = 0;
	for(auto i: a){
		curr.PB(i);
		if (SZ(curr) == x[ptr]){
			b.PB(curr);
			curr.clear();
			ptr++;
		}
	}
	
	reverse(ALL(b));
	a.clear();
	for(auto i: b) for(auto j: i) a.PB(j);
}

int is_shift(vector<int>& a, int n){
	FOR(i, 0, n) if (a[i] == 0){
		FOR(j, 1, n) if (a[(i + j) % n] != a[(i + j - 1) % n] + 1){
			return -1;
		}

		return i;
	}
	
	assert(false);
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int n; cin >> n;
	vector<int> a(n);
	FOR(i, 0, n) cin >> a[i], a[i]--;

	vector<vector<int>> ans;

	while(true){
		vector<int> pos(n);
		FOR(i, 0, n) pos[a[i]] = i;

		int id = -1;
		FOR(i, 1, n){
			if (pos[i] < pos[i - 1]){
				id = i;
				break;
			}
		}

		if (id == -1){
			break;
		}

		int xxx = is_shift(a, n);
		if (xxx != -1){
			ans.PB({xxx, n - xxx});
			roby(a, ans.back());
			break;
		}

		int len = 1;
		while(a[pos[id] + len] == a[pos[id] + len - 1] + 1) len++;
		  
		vector<int> x = go({pos[id], len, pos[id - 1] - pos[id] - len + 1, n - pos[id - 1] - 1});
		ans.PB(x);
		roby(a, ans.back());
		//print<VI>(a, cerr);
	}

//	assert(is_sorted(ALL(a)));
	assert(SZ(ans) <= n);
	cout << SZ(ans) << endl;
	for(auto i: ans){
		cout << SZ(i);
		for(auto j: i) cout << ' ' << j;
		cout << endl;
	}

    cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
    return 0;
}