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
using namespace std;
typedef long long ll;  
int main()
{
#ifndef ONLINE_JUDGE
	freopen("721A.in", "r", stdin); 
#endif
	int n; 
	scanf("%d", &n); 
	string str; 
	cin >> str; 
	vector<int> ans; 
	for (int i = 0; i < n; i++)
	{
		int orig = i; 
		while (i < n && str[i] == 'B')
			i++; 
		if (i != orig)
			ans.pb(i - orig); 
	}
	printf("%d\n", ans.size());
	for (int i = 0; i < ans.size(); i++)
		printf("%d%c", ans[i], " \n"[i + 1 == ans.size()]);
	return 0; 
}