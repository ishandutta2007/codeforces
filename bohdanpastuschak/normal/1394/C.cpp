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

const int N = 1 << 19;
int n;
PII a[N];
PII ans = {INF, INF};
int Cost = INF;

inline void check(int cnt0, int cnt1, int cost){
	if (Cost > cost){
		ans = {cnt0, cnt1};
		Cost = cost;
	}
}

inline void print(){
	cout << Cost << endl;
	FOR(i, 0, ans.X) cout << 'B';
	FOR(i, 0, ans.Y) cout << 'N';
	cout << endl;
	exit(0);
}

inline int get(int cnt0, int cnt1){
	if (cnt0 + cnt1 == 0) return INF + 1;
	int A = 0;
	FOR(i, 0, n){
		if ((cnt0 <= a[i].X) == (cnt1 <= a[i].Y)){
			setmax(A, max(abs(cnt0 - a[i].X), abs(cnt1 - a[i].Y)));
		}else{
			setmax(A, abs(cnt0 - a[i].X) + abs(cnt1 - a[i].Y));
		}
	}

	//cout << cnt0 << ' ' << cnt1 << ' ' << A << endl;
	return A;
}

int f(int cnt0, int mx1){
	int l1 = 0, r1 = mx1, m1, m2;
	int mn = INF;
	while(r1 - l1 > 2){
		m1 = l1 + (r1 - l1) / 3;
		m2 = r1 - (r1 - l1) / 3;
		int v1 = get(cnt0, m1);
		int v2 = get(cnt0, m2);		
		if (v1 > v2) l1 = m1;
		else r1 = m2;
	}

	FOR(i, l1, r1 + 1){
		int G = get(cnt0, i);
		setmin(mn, G);
		check(cnt0, i, G);
	}

	return mn;
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n;
	FOR(i, 0, n){
		string s; cin >> s;
		int cnt0 = 0;
		for(auto j: s) cnt0 += j == 'B';
		a[i] = {cnt0, SZ(s) - cnt0};
	}

	sort(a, a + n);
	n = unique(a, a + n) - a;
	int mx0 = 0, mx1 = 0;
	FOR(i, 0, n){
		setmax(mx0, a[i].X);
		setmax(mx1, a[i].Y);
	}

	int l1 = 0, r1 = mx0, m1, m2;
	while(r1 - l1 > 2){
		m1 = l1 + (r1 - l1) / 3;
		m2 = r1 - (r1 - l1) / 3;
		int v1 = f(m1, mx1);
		int v2 = f(m2, mx1);
		if (v1 > v2) l1 = m1;
		else r1 = m2;
	}

	FOR(i, l1, r1 + 1) f(i, mx1);

	print();
		
	cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
    return 0;
}