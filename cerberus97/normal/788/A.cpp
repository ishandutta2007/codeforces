/*
Hanit Banga
*/

#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <vector>
#include <map>
#include <set>

using namespace std;

#define pb push_back
#define fast_cin() ios_base::sync_with_stdio(false)

typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 2e5 + 5;
const ll inf = 1e15;

ll a[N], odd[N], even[N];
set <ll> odd_st, even_st;

int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];

	odd[1] = even[1] = 0;
	odd_st.insert(inf);
	even_st.insert(inf);
	ll ans = -inf;
	for (int i = 2; i <= n; ++i)
	{
		odd[i] = odd[i - 1] + (abs(a[i - 1] - a[i])) * ((i % 2 == 0) ? 1 : -1);
		even[i] = even[i - 1] + (abs(a[i - 1] - a[i])) * ((i % 2 == 1) ? 1 : -1);
		ans = max(ans, odd[i] - *(odd_st.begin()));
		ans = max(ans, even[i] - *(even_st.begin()));
		ans = max(ans, odd[i]);
		if (i % 2 == 0)
			even_st.insert(even[i]);
		else
			odd_st.insert(odd[i]);
	}

	cout << ans;
}