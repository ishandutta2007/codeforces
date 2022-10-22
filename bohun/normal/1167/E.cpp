#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>


#define pb push_back
#define ld long double
#define fi first
#define se second
#define ll long long
#define ss(x) (int) x.size()
#define mp make_pair
#define FOR(i, n) for(int i = 1; n >= i; ++i)

using namespace std;
using namespace __gnu_pbds;

const int N = 1e6 + 5;
int n, m, t[N], Right[N], Left[N];
vector <int> v[N];
ll ans = 0;
int P, S;
int mini[N];

int main() {
	
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	cin >> n >> m;
	for(int i = 1; i <= m; ++i) {
		Left[i] = n + 1;
	}
	for(int i = 1; i <= n; ++i) {
		cin >> t[i];
		Right[t[i]] = max(Right[t[i]], i);
		Left[t[i]] = min(Left[t[i]], i);
	}
	int so_far = -1;
	for(int i = 1; i <= m; ++i) {
		if(Left[i] < so_far) {
			break;
		}
		P = i;
		so_far = max(so_far, Right[i]);
	}
	so_far = n + 1;
	for(int i = m; 1 <= i; i--) {
		if(Right[i] > so_far) {
			break;
		}
		S = i;
		so_far = min(so_far, Left[i]);
	}
	if(P == m){
		cout << (ll) m * (m + 1) / 2;
		return 0;
	}
	mini[m + 1] = n + 5;
	for(int i = m; 1 <= i; i--) {
		mini[i] = min(mini[i + 1], Left[i]);
	}
	ans += (m - S) + 2;
	so_far = -1;
	for(int i = 1; i <= P; ++i) {
		so_far = max(so_far, Right[i]);
		while(S <= m && mini[S] < so_far)
			S++;
		ans += m - S + 2;
	}
	cout << ans;
		
	
	
	
		
	
    return 0;
}