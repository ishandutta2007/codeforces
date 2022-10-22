#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define F first
#define S second

const int MAXN = 1e5 + 10;

int n;
ll a[MAXN], sec[MAXN], ans[MAXN];
int sz;

int get(ll x){
	if (!x) return -1;

	int ret = -1;
	while (x){
		x >>= 1;
		ret++;
	}
	return ret;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	sort(a, a + n);
	reverse(a, a + n);
	
	for (int l = 0; l < n;){
		int r = l, temp = get(a[l]);
		while (r < n && get(a[r]) == temp) r++;

		int tt = 0, cur = 0, pt = 0;
		for (int i = l; i < r; i++){
			while (pt < sz && cur){
				ll x = ans[pt++];
				sec[tt++] = x;
				cur ^= x>>temp&1;
			}

			if (cur){
				cout << "No\n";
				return 0;
			}

			sec[tt++] = a[i];
			cur ^= 1;
		}

		while (pt < sz)
			sec[tt++] = ans[pt++];

		sz = tt;
		for (int i = 0; i < tt; i++)
			ans[i] = sec[i];

		l = r;
	}
	
	cout << "Yes\n";
	for (int i = 0; i < n; i++)
		cout << ans[i] << " ";
	cout << "\n";
	return 0;
}