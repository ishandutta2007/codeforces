#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define mp make_pair
#define pb push_back
#define ld long double
#define ss(x) (int) x.size()
#define FOR(i, n) for(int i = 1; i <= n; ++i) 
#define fi first
#define se second
#define cat(x) cerr << #x << " = " << x << endl;



using namespace std;
using namespace __gnu_pbds;

// order_by_key
// find_by_order
// tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> Plus, Minus;

int q, n, k;

int main ()
	{
	scanf ("%d",&q);
	while (q--)
		{
		scanf ("%d%d",&n,&k);
		if (k%3!=0)
			printf ("%s\n", n%3!=0 ? "Alice" : "Bob");
		else
			{
			n%=(k+1);
			printf ("%s\n", (n%3!=0 || n==k) ? "Alice" : "Bob");
			}
		}
	

	return 0;
}