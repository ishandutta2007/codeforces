#pragma GCC optimize "-O3"
#include <bits/stdc++.h>
 
using namespace std;
 
const int   N   = 1e6 + 1;
 
typedef long long    ll;
 
int n;
ll  k, a[N];
 
struct node {
	int chi[2];
	int cnt[2];
	node()  {
		chi[0] = chi[1] = -1;
		cnt[0] = cnt[1] = 0;
	}
};
 
vector<node> t[2];
 
int R[N], C[N], p;
ll  get(int b)  {
	ll  ans = 0;
	t[p ^ 1].clear();
	for(int i = 1 ; i <= n ; ++i)   {
		int x = (a[i] >> b & 1);
		if (R[i] >= 0)
			ans += t[p][R[i]].cnt[x];
		if (t[p][C[i]].chi[x] < 0) {
			t[p][C[i]].chi[x] = t[p ^ 1].size();
			t[p ^ 1].push_back(node());
		}
		++t[p][C[i]].cnt[x];
		C[i] = t[p][C[i]].chi[x];
	}
	return ans;
}
void upd(int b,int x)   {
	for(int i = 1 ; i <= n ; ++i)   {
		int y = (a[i] >> b & 1);
		if (R[i] < 0)   continue;
		R[i] = t[p][R[i]].chi[y ^ x];
	}
	p ^= 1;
}
 
int main()  {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n >> k;
	
	if (k <= n) return 0 * puts("0");
	
	k = (k - n + 1) / 2;
	
	for(int i = 2 ; i <= n ; ++i)   {
		int p;
		ll  w;
		cin >> p >> w;
		a[i] = (a[p] ^ w);
	}
	
	ll  ans = 0;
	
	t[0] = {node()};
	
	for(int i = 61 ; i >= 0 ; --i)  {
		ll  cur = get(i);
		bool ch = cur < k;
		upd(i,ch);
		if (!ch)  continue;
		ans += (1ll << i);
		k   -= cur;
	}
	
	cout << ans;
}