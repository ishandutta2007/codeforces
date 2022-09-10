#include <bits/stdc++.h>
using namespace std;

//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,fma")

typedef long long LL;
typedef pair<int, int> PII;
typedef vector<int> VI;
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

const double PI = acos(-1.0);
const LL INF = 1e9;
const LL LINF = INF * INF;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const bool local = false;
LL x;
int C;

LL ask(LL q){
	C++;
	assert(C <= 22);
	if (local){
		return __gcd(x, q);
	}else{
		cout << "? " << q << endl;
		fflush(stdout);
		cin >> q;
		return q;
	}
}

inline int get(int n){
	int res = 0;
	for(int i = 1; i * i <= n; ++i){
		if (n % i == 0){
			res++;
			res += i * i < n;
		}
	}
	
	return res;
}

LL get_P(int P){
	LL res = P;
	while(res * P <= INF + 1){
		res *= P;
	}
	
	return res;
}

VI primes;

void solve(){
	vector<int> cand;
	LL curr = 1;
	
	vector<int> P;
	
	LL must = 1;
	bool mit = 0;
	for(auto i: primes){
		if (must * i > INF){
			mit = 1;
			break;
		}
		
		if (curr * (__int128) i > LINF){
			LL res = ask(curr);
			for(auto j: P){
				if (res % j == 0){
					cand.PB(j);
					must *= j;
				}
			}
			
			curr = i;
			P = {i};
		}else{
			curr *= i;
			P.PB(i);
		}
	}
	
	int ans = 1;
	if (SZ(cand) && !mit){
		int hto = cand[0];
		LL P_hto = get_P(hto);
		LL res = ask(curr * P_hto);
		for(auto j: P){
			if (res % j == 0){
				cand.PB(j);
				must *= j;
			}
		}
		
		int cnt = 0;
		while(res % hto == 0){
			cnt++;
			res /= hto;
		}
		
		ans *= cnt + 1;
		reverse(ALL(cand));
		cand.pop_back();
		reverse(ALL(cand));
	}else if (SZ(cand) == 0) {
		LL res = ask(curr);
		for(auto j: P){
			if (res % j == 0){
				cand.PB(j);
			}
		}
	}
	
	int iter = 0;
	
	int je = SZ(cand);
	for(int i = 0; i < SZ(cand) && iter < 2; i += 2, iter++){
		int P1 = cand[i];
		int Q = (i + 1 == SZ(cand) ? INF + 1: cand[i + 1]);
		je --;
		je -= Q < INF;
		LL query = get_P(P1) * get_P(Q);
		LL res = ask(query);
		
		int cntP = 0, cntQ = 0;
		while(res % P1 == 0){
			res /= P1;
			cntP++;
		}
		
		while(res % Q == 0){
			res /= Q;
			cntQ++;
		}
		
		ans *= cntP + 1;
		ans *= cntQ + 1;
	}	
	
	while(je--){
		ans += ans;
	}	
	
	ans = max(2 * ans, ans + 7);
	cout << "! " << ans << endl;
	if (local){
		int real_ans = get(x);
		if (abs(ans - real_ans) > 7 && (ans > 2 * real_ans || ans * 2 < real_ans)){
			debug(x)
			debug(ans)
			debug(real_ans)
			assert(false);
		}
	}	
}

int main()
{
    for(int i = 2; i < 797 ; ++i){
		if (get(i) == 2){
			primes.PB(i);
		}
	}
		
	int t;
	cin >> t;
	while(t--){
		if (local){
			cin >> x;
		}
		C = 0;
		solve();
	}
	
    cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
    return 0;
}