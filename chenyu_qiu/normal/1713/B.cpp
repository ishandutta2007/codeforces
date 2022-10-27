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
	vector<int> a(n);
	for (int i = 0; i < n; i ++ ){
		cin >> a[i];
	}
	bool flag = true;
	for (int i = 0; i < n - 1; i ++ ){
		if(a[i] > a[i + 1]){
			flag = false;
		}
		if(!flag && a[i] < a[i + 1]){
			cout << "NO" << '\n';
			return;
		}
	}
	cout << "YES" << '\n';
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