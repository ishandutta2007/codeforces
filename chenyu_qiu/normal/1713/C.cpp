#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define pb push_back
#define vi vector<int>
#define pii pair<int,int>
#define psi pair<string,int>
#define fi first
#define se second
#define lson son << 1
#define rson son << 1 | 1
#define all(x) (x).begin(),(x).end()
#define int ll 
const int N = 2e5+10, inf = 9e18, MAXN = 1e6 + 10, mod = 1e9 + 7;
void solve(){
	int n;
	cin >> n;
	vector<int> a(n + 1);
	n --;
	vector<array<int,2>> v;
	double t = n;
	while(t > 0){
		int s = ceil(sqrt(t));
		s = s * s;
		int pre = s - t;
		v.push_back({pre, t});
		t = pre - 1;
	}
	for(auto [x,y]:v){
		for(int i = x; i <= y; i ++ ){
			a[i] = x + y - i;
		}
	}
	for(int i = 0; i <= n; i ++ ){
		cout << a[i] << " \n"[i == n ];
	}
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;
	cin >> t;
	while(t --){
		solve();
	}
	return 0;
}