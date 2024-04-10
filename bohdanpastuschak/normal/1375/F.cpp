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
const LL INF = 1e9 + 47;
const LL LINF = INF * INF;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void read(int& k){
	cin >> k;
	if (k == 0) exit(0);
}

int main()
{
	LL a, b, c;
	cin >> a >> b >> c;
	vector<pair<LL, int>> A;
	A.PB({a, 1});
	A.PB({b, 2});
	A.PB({c, 3});
	sort(ALL(A));
	
	cout << "First" << endl;
	fflush(stdout);
	
	LL query;
	int k, id;
	
	here:
	query = A[2].X - A[1].X;
	cout << query << endl;
	fflush(stdout);		
	read(k);
	FOR(i, 0, 3) if (A[i].Y == k) id = i;
	A[id].X += query;
	sort(ALL(A));
	
	if (id == 2){
		query = A[2].X * 2 - A[1].X - A[0].X;		
		cout << query << endl;
		fflush(stdout);		
		read(k);
		FOR(i, 0, 3) if (A[i].Y == k) id = i;
		A[id].X += query;
		sort(ALL(A));
	//	assert(A[2].X - A[1].X == A[1].X - A[0].X);
		query = A[2].X - A[1].X;
		cout << query << endl;
		read(k);
	//	assert(k == 0);
	}else{
	//	assert(id == 0);
		goto here;		
	}
	
	cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}