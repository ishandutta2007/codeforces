#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define F first
#define S second

const int MAXN = 5e5 + 10;

int n, a[MAXN];
ll pt[MAXN];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	int x = 0;
	for (int i = 0; i < n; i++) cin >> a[i], x ^= a[i]&1;
	sort(a, a + n);
	reverse(a, a + n);
	for (int i = 0; i < n; i++) pt[i+1] = pt[i] + a[i];

	int l = 0, r = n;
	for (int i = 1; i <= n+1; i++){
		//inc
		ll t = 1ll*i*(i-1)-pt[i-1];
		int lo = i-2, hi = n;
		while (hi-lo>1){
			int mid = hi+lo>>1;
			if (a[mid] >= i)
				lo = mid;
			else
				hi = mid;
		}
		t += pt[n] - pt[hi];
		t += 1ll*(hi - (i-1))*i;
		if (r > t)
			r = t;

		//exc
		if (i < n+1){
			ll t = pt[i] - 1ll*i*(i-1);
			int lo = i-1, hi = n;
			while (hi-lo>1){
				int mid = hi+lo>>1;
				if (a[mid] >= i)
					lo = mid;
				else
					hi = mid;
			}

			t -= pt[n] - pt[hi];
			t -= 1ll*(hi - i)*i;
			if (t > i || t > a[i-1])
				l = max(l, a[i-1]+1);
			else if (t > l)
				l = t;
		}
	}

	bool found = false;
	for (int i = l; i <= r; i++)
		if ((i&1) == x) {
			cout << i << " ";
			found = true;
		}
	if (found)
		cout << "\n";
	else
		cout << "-1\n";
	return 0;
}