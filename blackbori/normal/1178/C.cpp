#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll mod = 998244353;

ll w, h, ans;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> w >> h;
	
	w += h;
	
	for(ans=1; w; w--){
		ans = ans * 2 % mod;
	}
	
	cout << ans << "\n";
	
	return 0;
}