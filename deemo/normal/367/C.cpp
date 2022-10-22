#include<iostream>
#include<algorithm>
#include<functional>

using namespace std;

typedef long long ll;

const int MAXM = 1e5 + 10;

int n, m, sec[MAXM];

bool ok(int mid){
	if (mid == 2)	return	n >= 2;

	if (mid % 2){
		ll cc = (ll)mid * ll(mid - 1)/ 2LL;
		return cc + 1 <= n;
	}

	ll cc = (ll)mid * ll(mid - 1)/ 2LL;
	cc += (mid/2);
	return cc <= n;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m; i++){
		int temp;	
		cin >> temp >> sec[i];
	}
	sort(sec, sec + m, greater<int>());
	
	int b = 2, e = m, ret = 1;
	while (b <= e){
		int mid = (b + e)/ 2;
		if (ok(mid))
			ret = mid, b = mid + 1;
		else
			e = mid - 1;
	}

	long long ans = 0;
	for (int i = 0; i < ret; i++)
		ans += sec[i];
	cout << ans << "\n";
	return	0;
}