#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define F first
#define S second

const int MAXN = 1e6 + 10;

int n, a[MAXN], sec[MAXN], tl[MAXN], tr[MAXN];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)	cin >> a[i];
	{
		int sz = 0;
		for (int i = 0; i < n; i++){
			while (sz && a[sec[sz-1]] <= a[i]) sz--;
			if (sz == 0)
				tl[i] = 0;
			else
				tl[i] = sec[sz-1]+1;
			sec[sz++] = i;
		}
	}
	{
		int sz = 0;
		for (int i = n-1; ~i; i--){
			while (sz && a[sec[sz-1]] < a[i]) sz--;
			if (sz == 0)
				tr[i] = n;
			else
				tr[i] = sec[sz-1];
			sec[sz++] = i;
		}
	}
	ll ans = 0;
	for (int i = 0; i < n; i++)
		ans += 1ll*(tr[i]-i)*(i-tl[i]+1)*a[i];
	{
		int sz = 0;
		for (int i = 0; i < n; i++){
			while (sz && a[sec[sz-1]] >= a[i]) sz--;
			if (sz == 0)
				tl[i] = 0;
			else
				tl[i] = sec[sz-1]+1;
			sec[sz++] = i;
		}
	}
	{
		int sz = 0;
		for (int i = n-1; ~i; i--){
			while (sz && a[sec[sz-1]] > a[i]) sz--;
			if (sz == 0)
				tr[i] = n;
			else
				tr[i] = sec[sz-1];
			sec[sz++] = i;
		}
	}
	for (int i = 0; i < n; i++)
		ans -= 1ll*(tr[i]-i)*(i-tl[i]+1)*a[i];
	cout << ans << "\n";
	return 0;
}