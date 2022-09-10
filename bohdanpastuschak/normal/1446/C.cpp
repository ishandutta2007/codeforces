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

const int BIT = 31;
const int A = 2;	

struct node{
	int cnt;
	int nxt[A];
	node(){
		cnt = 0;
		FILL(nxt, -1);
	}
};

vector<node> a;
	
void add(int x){
	int v = 0;
	RFOR(i, BIT, 0){			
		bool tut = (x & (1 << i)) > 0;
		if (a[v].nxt[tut] == -1){
			a[v].nxt[tut] = SZ(a);
			a.PB(node());
		}

		v = a[v].nxt[tut];
		a[v].cnt++;
	}
}

int solve(int x){
	int v = 0;
	int ans = 1;
	RFOR(i, BIT, 0){
		if (a[v].cnt == 1){
			break;
		}
		
		bool tut = (x & (1 << i)) > 0;		 
		ans += a[v].nxt[!tut] != -1;
		v = a[v].nxt[tut];
	}

	return ans;
}

const int N = 1 << 18;
int n, b[N];

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	a.PB(node());
	
	cin >> n;
	FOR(i, 0, n) cin >> b[i];

	FOR(i, 0, n){
		add(b[i]);
	}

	int ans = 0;
	FOR(i, 0, n){
		setmax(ans, solve(b[i]));
	}
	
	cout << n - ans << endl;	
    cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
    return 0;
}