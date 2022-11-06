#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#ifdef ONLINE_JUDGE
#define put_ll(x) printf("%I64d\n", x);
#define inp_ll(x) scanf("%I64d", &x); 
#define put_ll_space(x) printf("%I64d ", x);
#else
#define put_ll(x) printf("%lld\n", x);
#define inp_ll(x) scanf("%lld", &x); 
#define put_ll_space(x) printf("%lld ", x);
#endif
using namespace std; 
typedef long long ll; 
ll pre[102400]; 
int arr[102400], seq[102400], l[102400], r[102400]; 
bool vis[102400];
int main()
{
#ifndef ONLINE_JUDGE
	freopen("722C.in", "r", stdin); 
#endif
	int n; 
	scanf("%d", &n); 
	for (int i = 0; i < n; i++)
	{
		scanf("%d", arr + i); 
		pre[i] = (i ? pre[i - 1] : 0) + (ll)arr[i]; 
		l[i] = i; 
		r[i] = i; 
	}
	for (int i = 0; i < n; i++)
		scanf("%d", seq + i); 
	ll ans = 0; 
	vector<ll> res; 
	for (int i = n - 1; i >= 0; i--)
	{
		res.pb(ans); 
		seq[i]--; 
		if (seq[i] && vis[seq[i] - 1])
			l[seq[i]] = l[seq[i] - 1]; 
		if (seq[i] != n - 1 && vis[seq[i] + 1])
			r[seq[i]] = r[seq[i] + 1]; 
		r[l[seq[i]]] = r[seq[i]]; 
		l[r[seq[i]]] = l[seq[i]]; 
		vis[seq[i]] = true; 
		ans = max(ans, pre[r[seq[i]]] - (l[seq[i]] ? pre[l[seq[i]] - 1] : 0));
	}
	for (int i = n - 1; i >= 0; i--)
		put_ll(res[i]); 
	return 0; 
}