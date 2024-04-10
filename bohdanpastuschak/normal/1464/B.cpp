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

LL calc(string& s, int x, int y){
	LL res = 0;
	LL cnt0 = 0, cnt1 = 0;
	for(auto i: s){
		if (i == '0'){
			cnt0++;
			res += y * cnt1;
		}
		else{
			cnt1++;
			res += x * cnt0;
		}
	}
	return res;
}

LL solver(int n, int x, int y, string s){
	LL ans = LINF;
	string t = s;
	vector<int> was(n, 0);
	FOR(i, 0, n) if (t[i] == '?'){
		t[i] = '1';
		was[i] = 1;
	}

	ans = calc(t, x, y);
	LL curr = ans;

	vector<int> pref0(n, 0), pref1(n, 0);
	FOR(i, 0, n){
		if (i){
			pref0[i] = pref0[i - 1];
			pref1[i] = pref1[i - 1];
		}
		
		pref0[i] += t[i] == '0';
		pref1[i] += t[i] == '1';
	}

	int cnt0 = 0, cnt1 = 0;
	RFOR(i, n, 0){
		if (!was[i]){
			if (t[i] == '0'){
				cnt0++;
			}else{
				cnt1++;
			}
		}else{
			curr -= pref0[i] * (LL) x;
			curr -= cnt0 * (LL) y;
			curr += cnt1 * (LL) x;
			curr += (pref1[i] - 1) * (LL) y;
			setmin(ans, curr);
			cnt0++;
		}
	}

	return ans;
}

LL solve(int n, int x, int y, string s){
	if (count(ALL(s), '?') == 0){
		return calc(s, x, y);
	}

	LL ans = LINF;		
	setmin(ans, solver(n, x, y, s));
	swap(x, y);
	for(auto& i: s){
		if (i == '0') i = '1';
		else if (i == '1'){
			i = '0';
		}
	}
	setmin(ans, solver(n, x, y, s));
	return ans;
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	string s; cin >> s;
	int x, y; cin >> x >> y;
	cout << solve(SZ(s), x, y, s) << endl;
	
	cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
    return 0;
}