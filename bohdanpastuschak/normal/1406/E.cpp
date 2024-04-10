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

#define int long long
const int N = 100007;
const bool local = 0;
int real_x;
int still_exist[N];
bool is_prime[N];
int n;
int counter;

int A(int x, char c = 'A'){
	counter++;
	assert(counter <= 9999);
	
	if (local){
		int ans = 0;
		for(int i = x; i <= n; i += x) if (still_exist[i]){
			ans++;
			if (i != real_x && c == 'B') still_exist[i] = false;
		}
		return ans;
	}
	
	if (x > n) return 0;
	cout << c << ' ' << x << endl;
	fflush(stdout);
	cin >> x; return x;
}

int B(int x){
	return A(x, 'B');
}

void C(int x){
	cout << "C " << x << endl;
	fflush(stdout);
	if (local){
		debug(counter);
		assert(x == real_x);
	}	
	exit(0);	
}

int32_t main()
{
	fill(is_prime, is_prime + N, 1);
	fill(still_exist, still_exist + N, 1);
	vector<int> small, big;
	FOR(i, 2, N) if (is_prime[i]){
		if (i < 317) small.PB(i);
		else big.PB(i);
		
		for(int j = i + i; j < N; j += i) is_prime[j] = 0;
	}

	cin >> n;
	if (local){
		cin >> real_x;
	}
	
	int now = n;
	int ans = 1;
	
	for(auto p: small){
		const int erased = B(p);
		now -= erased;
		int R = A(1);
		if (R == now){
			continue;
		}

		//assert(R == now + 1);
		now = R;
		
		int P = p;
		while(A(P)) P *= p;
		ans *= P / p;
	}

	if (ans > 1){
		for(auto p: big){
			if (B(p) == 2){
				ans *= p;
				break;
			}
		}
	}else{
		vector<int> all;
		const int sz = 40;

		auto test = [&](){
			int R = A(1);
			if (R == 1) return;
			if (R == now) return;

			for(auto i: all){
				if (A(i)){
					ans *= i;
					C(ans);
				}
			}
			assert(false);		
		};
		
		for(auto p: big){
			all.PB(p);
			B(p);
			now--;
			if (SZ(all) == sz){
				test();
				all.clear();
			}
		}

		test();
	}

	C(ans);
	return 0;
}