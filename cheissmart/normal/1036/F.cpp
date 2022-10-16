#include <bits/stdc++.h>

const long long N = (long long)1e18 + 1;

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	vector<long long> v;
	for(long long i=2;i<=1000000;i++) {
		long long tmp = i*i*i;
		while(true) {
			if((long long)sqrtl(tmp)*(long long)sqrtl(tmp) != tmp)
				v.push_back(tmp);
			if(LLONG_MAX / tmp < i)
				break;
			tmp *= i;
		}
	}
	sort(v.begin(), v.end());
	int nsz = unique(v.begin(), v.end()) - v.begin();
	v.resize(nsz);

	int t;
	long long n;
	cin >> t;
	while(t--) {
		cin >> n;
		long long ans = n;
		ans -= (long long)sqrtl(n);
		ans -= upper_bound(v.begin(), v.end(), n) - v.begin();
		cout << ans << endl;
	}
}