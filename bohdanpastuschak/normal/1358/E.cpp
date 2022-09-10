#include <bits/stdc++.h>
using namespace std;
 
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

void no(){	
  	cout << -1 << endl;
  	exit(0);
}
int it;
inline bool CL(){
	it++;
	if (it & 127) return false;
	return clock() / (double) CLOCKS_PER_SEC >= 1.8;
}

const int N = 1 << 20;
int n, x;
int a[N];
LL s[N];

bool test(int k){
	if (s[k - 1] <= 0) return false;
	int To = n - k;
	FOR(i, 0, To){
		if (s[i] >= s[i + k]){
			return false;
		} 
	}
	
	cout << k << endl;
	exit(0);
	return true;
}

bool test2(int k){
	if (s[k - 1] <= 0) return false;
	int To = n - k;
	RFOR(i, To, 0){
		if (s[i] >= s[i + k]){
			return false;
		} 
	}
	
	cout << k << endl;
	exit(0);
	return true;
}


int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  	
  	cin >> n;
  	FOR(i, 0, (n + 1) >> 1) cin >> a[i];
  	cin >> x;
  	FOR(i, (n + 1) >> 1, n) a[i] = x;
  	
  	s[0] = a[0];
  	FOR(i, 1, n) s[i] = s[i - 1] + a[i];
  	
  	const int magic = 100;
  	FOR(k, 1, magic) if (k <= n) test(k);
  	RFOR(k, n + 1, n - magic) if (k >= 1) test(k);
  	
  	vector<int> K;
  	if (x <= 0){  		
  		FOR(k, n / 2 + 1, n - magic) K.PB(k);
  	}else{
  		FOR(k, magic, n - magic) K.PB(k);
  	}
  	
  	mt19937 rng(58);
  	for(auto k: K){
  		if (CL()) no();
  		 test2(k);
  		
  	}
  	
  	no();
    cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
    return 0;
}