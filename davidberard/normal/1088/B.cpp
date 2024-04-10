#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for(auto& x: a) cin >> x;
	sort(a.begin(), a.end());
	int i = 0, j=0;
	ll diff = 0;
	for(i=0;i<n && j<k;++i)
	{
		if(a[i]-diff == 0) continue;
		cout << a[i]-diff << "\n";
		diff += a[i]-diff;
		++j;
	}
	for(;j<k;++j)
	{
		cout << "0\n";
	}


	return 0;
}