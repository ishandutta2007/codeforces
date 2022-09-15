#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define inf 1000000005
#define all(a) (a).begin(), (a).end()
#define ms(a,x) memset(a, x, sizeof(a))
#define mod 1000000007
#define sz(a) ((ll)(a).size())

template<class T> int getbit(T s, int i) { return (s >> i) & 1; }
template<class T> T onbit(T s, int i) { return s | (T(1) << i); }
template<class T> T offbit(T s, int i) { return s & (~(T(1) << i)); }
template<class T> int cntbit(T s) { return __builtin_popcnt(s);}
#define Rep(i,n) for(int i = 0; i < (n); ++i)
#define Repd(i,n) for(int i = (n)-1; i >= 0; --i)
#define For(i,a,b) for(int i = (a); i <= (b); ++i)
#define Ford(i,a,b) for(int i = (a); i >= (b); --i)

typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
#define eps 1e-12
typedef pair<int, int> II;
typedef pair<ll, ll> LL;
template<class T> T gcd(T a, T b){ T r; while (b != 0) { r = a % b; a = b; b = r; } return a;}
template<class T> T lcm(T a, T b) { return a / gcd(a, b) * b; }
#define PI (2 * acos((ld)0))
#define linf (1ll << 60)
#define y1 y32432
#define y0 y435346

#define maxn 505

int n, k, m, a, g[maxn];
int num[maxn], last[maxn];

int main() {
//	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k >> m >> a;
	For(i, 1, a){
		cin >> g[i];
		num[g[i]]++;
		last[g[i]] = i;
	}

	For(i, 1, n){
		bool canLose, canWin;
		if(num[i] == 0) canLose = 1;
		else if(k == n) canLose = 0;
		else{
			vector<int> need;
			For(j, 1, n) if(j != i){
				if(num[j] > num[i] || (num[j] == num[i] && last[j] < last[i])){
					need.pb(0);
				} else{
					need.pb(num[i] - num[j] + 1);
				}
			}
			sort(all(need));
			int total = 0;
			Rep(j, k) total += need[j];
			if(total <= m - a) canLose = 1;
			else canLose = 0;
		}

		if(m - a == 0){
			if(num[i] == 0) canWin = 0;
			else{
				int number = 0;
				For(j, 1, n) if(j != i){
					if(num[j] > num[i] || (num[j] == num[i] && last[j] < last[i])) number++;
				}
				if(number >= k) canWin = 0;
				else canWin = 1;
			}
		} else{
			int number = 0;
			For(j, 1, n) if(j != i){
				if(num[j] >= num[i] + m - a) number++;
			}
			if(number >= k) canWin = 0;
			else canWin = 1;
		}

		if(!canLose){
			cout << 1 << " ";
		} else if(!canWin) cout << 3 << " ";
		else cout << 2 << " ";
	}

	return 0;
}