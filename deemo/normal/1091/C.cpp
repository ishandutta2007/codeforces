#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define F first
#define S second

const int MAXN = 1e5 + 10;

int n, sec[MAXN], sz;
ll ans[MAXN], tt;

ll get(ll k){
	ll t = n/ k;
	return 1ll*t*(1 + 1+1ll*(t-1)*k)/ 2;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 1; 1ll*i*i <= n; i++)
		if (n%i == 0)
			sec[sz++] = i, sec[sz++] = n/i;
	sort(sec, sec + sz);
	sz = unique(sec, sec + sz) - sec;

	for (int i = 0; i < sz; i++)
		ans[tt++] = get(sec[i]);
	
	sort(ans, ans + tt);
	tt = unique(ans, ans + tt) - ans;
	for (int i = 0; i < tt; i++)
		cout << ans[i] << " ";
	cout << "\n";
	return 0;
}