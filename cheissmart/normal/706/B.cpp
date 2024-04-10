#include <iostream>
#include <algorithm>

using namespace std;

long long x[100005];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, q, m, ans = 0;
	cin >> n;
	for(int i=0;i<n;i++)	
		cin >> x[i];
	sort(x, x+n);	
	cout << endl;
	cin >> q;
	for(int i=0;i<q;i++) {
		cin >> m;
		cout << upper_bound(x, x+n, m) - x << endl;
	}
}