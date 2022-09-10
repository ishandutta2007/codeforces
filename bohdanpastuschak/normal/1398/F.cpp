#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,fma")

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

vector<int> cnt0, cnt1, lst0, lst1;

inline bool cool(int l, int r){
	return (cnt0[r] - (l == 0 ? 0 : cnt0[l - 1])) == 0 ||
		   (cnt1[r] - (l == 0 ? 0 : cnt1[l - 1])) == 0;	
}

void solve(int n, const string& s, vector<int>& ans){
	FOR(x, 2, n + 1){
		int l = 0, r = x - 1;
		int curr = 0;
		while(r < n){
			if (cool(l, r)){
				l += x;
				r += x;
				curr += 1;
				if (curr == ans[x]){
					break;
				}
				continue;
			}

			l = min(lst0[r], lst1[r]) + 1;
			r = l + x - 1;			
		}

		ans[x] = curr;
	}
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int n; cin >> n;
	string s; cin >> s;
	cnt0 = cnt1 = VI(n, 0);
	lst0 = lst1 = VI(n, -1);
	
	FOR(i, 0, n){
		if (i){
			cnt0[i] += cnt0[i - 1];
			cnt1[i] += cnt1[i - 1];
			lst0[i] = lst0[i - 1];
			lst1[i] = lst1[i - 1];
		}
		if (s[i] == '0'){
			cnt0[i]++;
			lst0[i] = i;
		}

		if (s[i] == '1'){
			cnt1[i]++;
			lst1[i] = i;
		}		
	}
	
	vector<int> ans(n + 1, 0);
	FOR(i, 1, n + 1) ans[i] = n / i;

	if (count(ALL(s), '0') > 0 && count(ALL(s), '1') > 0){
		solve(n, s, ans);
	}	
	
	FOR(i, 1, n + 1) cout << ans[i] << ' ';
	cout << endl;
	
	cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
    return 0;
}