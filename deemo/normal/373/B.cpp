#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

typedef long long ll;

ll w, m, k;

int main(){
	cin >> w >> m >> k;
	ll temp = m;
	ll z = 10, cnt = 1;
	while (z <= m)	z *= 10, cnt++;
	while (w){
		ll y = z - m;
		if (w/k >= cnt * y){
			m = z;
			z *= 10;
			w -= k * cnt * y;
			cnt++;
		}
		else{
			ll t = w / k;
			t /= cnt;
			m += t;
			break;
		}
	}
	cout << m - temp << endl;
	return 0;
}