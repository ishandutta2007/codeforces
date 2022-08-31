#include <iostream>
#include <set>
#include <vector>

using namespace std;

typedef long long ll;

const int N = 1e5 + 5;

int p[N];
ll prefix[N], a[N];

void buildPrefixSums(ll *a, int n)
{
	prefix[0] = 0;

	for (int i = 1; i <= n; ++i)
		prefix[i] = a[i] + prefix[i-1];
}

ll getSum(int i, int j)
{
	if (j < i)
		return 0;

	return prefix[j] - prefix[i-1];
}

int main()
{
	int n;
	cin >> n;

	for (int i = 1; i <= n; ++i)
		cin >> a[i];

	for (int i = 1; i <= n; ++i)
		cin >> p[i];

	buildPrefixSums(a, n);

	set <int> destroyed;
	destroyed.insert(0);
	destroyed.insert(n+1);

	multiset <ll, greater <ll> > sums;
	sums.insert(getSum(1, n));

	for (int i = 1; i <= n; ++i)
	{
		int cur = p[i];
		auto right = destroyed.lower_bound(cur), left = right;
		--left;

		int l = *left, r = *right;

		sums.erase(sums.find(getSum(l+1, r-1)));
		sums.insert(getSum(l+1, cur-1));
		sums.insert(getSum(cur+1, r-1));

		destroyed.insert(cur);

		cout << *(sums.begin()) << '\n';
	}
}