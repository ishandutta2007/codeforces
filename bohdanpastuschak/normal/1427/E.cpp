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

LL gcd (LL a, LL b, LL& x, LL& y) {
	if (a == 0) {
		x = 0; y = 1;
		return b;
	}
	
	LL x1, y1;
	LL d = gcd (b%a, a, x1, y1);
	x = y1 - (b / a) * x1;
	y = x1;
	return d;
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	vector<vector<LL>> ans;
	LL x; cin >> x;	
	//for(LL x = 3; x <= 1000000; x += 2)
	{
		int k = 2;
		while(true){
			LL val = (x * k) ^ x;
			if (__gcd(val, x) == 1){
				break;
			}

			k += k;
		}

		
		const int bits = 41;
		FOR(i, 0, bits){
			ans.PB({0, x << i, x << i});
		}
		
		ans.PB({1, x, x * k});
		LL val = x ^ (x * k);
		//debug(val)
		if (val > 1){
			LL k1, k2;
			LL g = gcd(x, val, k1, k2);
			assert(g == 1);
			assert(k1 * x + k2 * val == 1);
									
			if (k1 < 0) k1 = -k1;
			if (k2 < 0) k2 = -k2;

			LL V1 = k1 * x;
			LL V2 = k2 * val;
			
			vector<int> B;
			FOR(i, 0, bits) if (k1 & (1LL << i)){
				B.PB(i);
			}

			LL curr = 1LL << B[0];
			FOR(i, 1, SZ(B)){
				ans.PB({0, curr * x, x * (1LL << B[i])});
				curr += 1LL << B[i];
			}

			B.clear();
			FOR(i, 0, bits) if (k2 & (1LL << i)){
				B.PB(i);
			}

			FOR(i, 0, 21){
				ans.PB({0, val << i, val << i});
			}
			
			curr = 1LL << B[0];
			FOR(i, 1, SZ(B)){
				ans.PB({0, curr * val, val * (1LL << B[i])});
				curr += 1LL << B[i];
			}
					
			ans.PB({1, k1 * x, k2 * val});			
			LL QQ = V1 ^ V2;
			if (QQ != 1){
				if (V1 < V2) swap(V1, V2);
				assert(V1 % 2 == 0);
				assert(V2 == V1 - 1);
				ans.PB({0, V2, V2});
				ans.PB({0, V1, V2});
				ans.PB({1, V1 + V2, V2 + V2});
			}
		}
		
		if (1){
			cout << SZ(ans) << endl;
			set<LL> IS;
			IS.insert(x);
			for(auto i: ans){
				
				if (i[0] == 0){
					cout << i[1] << " + " << i[2] << '\n';
					IS.insert(i[1] + i[2]);
				}else{
					cout << i[1] << " ^ " << i[2] << '\n';
					IS.insert(i[1] ^ i[2]);
				}

				assert(IS.count(i[1]));
				assert(IS.count(i[2]));
			}
		}
	}
		
    cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
    return 0;
}