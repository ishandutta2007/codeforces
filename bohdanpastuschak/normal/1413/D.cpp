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

void bad(){
	cout << "NO" << endl;
	exit(0);
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int n; cin >> n;
	vector<int> a(n << 1, 0);
	FOR(i, 0, n << 1){
		char x; cin >> x;
		if (x == '-'){
			cin >> a[i];
		}
	}

	vector<int> ans;

	stack<int> s;
	RFOR(i, n << 1, 0){
		if (a[i]){
			if (SZ(s) && s.top() < a[i]){
				bad();
			}
			s.push(a[i]);
		}else{
			if (SZ(s) == 0){
				bad();
			}

			ans.PB(s.top());
			s.pop();
		}
	}

	reverse(ALL(ans));
	cout << "YES" << endl;
	for(auto i: ans){
		cout << i << ' ';
	}
	cout << endl;		
	
    cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
    return 0;
}