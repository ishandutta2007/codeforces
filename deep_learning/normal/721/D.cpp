#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#ifdef ONLINE_JUDGE
#define inp_ll(x) scanf("%I64d", &x)
#define put_ll(x) printf("%I64d\n", x)
#define put_ll_space(x) printf("%I64d ", x)
#else
#define inp_ll(x) scanf("%lld", &x)
#define put_ll(x) printf("%lld\n", x)
#define put_ll_space(x) printf("%lld ", x)
#endif
#define my_abs(x) ((x) < 0 ? -(x) : (x))
using namespace std;
typedef long long ll;  
ll arr[204800]; 
int main()
{
#ifndef ONLINE_JUDGE
	freopen("721D.in", "r", stdin); 
#endif
	int n, k, x; 
	scanf("%d%d%d", &n, &k, &x); 
	int mn = 0x3FFFFFFF, pos, off = 0; 
	set<pair<ll, int> > se; 
	for (int i = 0; i < n; i++)
	{
		inp_ll(arr[i]); 
		se.insert(mp(my_abs(arr[i]), i)); 
		off ^= arr[i] < 0; 
	}
	while (k--)
	{
		int pos = se.begin()->second; 
		off ^= arr[pos] < 0; 
		if (off)
			arr[pos] += x; 
		else
			arr[pos] -= x; 
		se.erase(se.begin()); 
		se.insert(mp(my_abs(arr[pos]), pos)); 
		off ^= arr[pos] < 0; 
	}
	for (int i = 0; i < n; i++)
		put_ll_space(arr[i]); 
	return 0; 
}