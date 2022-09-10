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

const bool local = false;
const int N = 1 << 16;
int n, k, real_ans[N], ans[N], count_op;

inline int query(int i, int j, int op){
	if (local){
		count_op++;
		assert(count_op <= n + 2);
		if (op == 0) return real_ans[i] & real_ans[j];
		if (op == 1) return real_ans[i] | real_ans[j];
		if (op == 2) return real_ans[i] ^ real_ans[j];
		assert(false);
	}
	
	if (op == 0) cout << "AND ";
	if (op == 1) cout << "OR ";
	if (op == 2) cout << "XOR ";
	cout << i + 1 << ' ' << j + 1 << endl;
	fflush(stdout);
	int res; cin >> res;
	return res;
}	 

void finalize(){
	if (local){
		FOR(i, 0, n) assert(ans[i] == real_ans[i]);
	}
	
	cout << "!";
	FOR(i, 0, n) cout << ' ' << ans[i];
	cout << endl;
	fflush(stdout);
	exit(0);
}

int main()
{
    cin >> n;
    k = 2;
	while((1 << k) < n) k++;
	
    if (local){
		FOR(i, 0, n) cin >> real_ans[i];
	}

	int a = query(0, 1, 0);
	int b = query(0, 2, 0);
	int c = query(1, 2, 1);
	int d = query(0, 1, 2);
	int e = query(0, 2, 2);
	
	int res = 0;
	FOR(i, 0, k){
		int A = a & (1 << i);
		int B = b & (1 << i);
		int C = c & (1 << i);
		int D = d & (1 << i);
		int E = e & (1 << i);
		
		if (A || B){
			res += 1 << i;
			continue;
		}

		if (C){
			continue;
		}

		if (D && E){
			res += 1 << i;
			continue;
		}		
	}

	ans[0] = res;
	ans[1] = res ^ d;
	ans[2] = res ^ e;

	FOR(i, 3, n){
		ans[i] = ans[0] ^ query(0, i, 2);
	}		
	
	finalize();
    return 0;
}