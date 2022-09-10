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

void bad(){
	cout << "Hermione" << endl;
	exit(0);
}

void ok(){
	cout << "Ron" << endl;
	exit(0);
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int a, b, c, d, e, f;
	cin >> a >> b >> c >> d >> e >> f;
	
	int start = 1e6;
	__int128 Pisok = start, Svynec = 0, Zoloto = 0;
	
	FOR(it, 0, 1 << 20){
		
		if (a){
			Svynec += Pisok / a * b;
			Pisok %= a;
		}else if (b){
			Svynec = (LINF * (Pisok > 0));
		}
		
		if (c){
			Zoloto += Svynec / c * d;
			Svynec %= c;
		}else if (d){
			Zoloto = LINF * (Svynec > 0);
			ok();
		}
		
		if (Zoloto > LINF) ok();
		if (e){
			Pisok += Zoloto / e * f;
			Zoloto %= e;
		}else if (f){
			Pisok = LINF * (Zoloto > 0);
		}
		
		//cout << (LL)Pisok << ' ' << (LL)Zoloto << endl;
		//cin >> it;
	}	
	
	if (Pisok > start) ok();
	bad();
	
    cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
    return 0;
}