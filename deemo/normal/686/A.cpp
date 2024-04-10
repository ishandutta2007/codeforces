#include<iostream>
#include<algorithm>

using namespace std;

typedef long long ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n, x;	cin >> n >> x;
	ll cnt = 0;
	while (n--){
		char type;	cin >> type;
		ll y;	cin >> y;
		if (type == '+')
			x += y;
		else{
			if (x < y)
				cnt++;
			else
				x -= y;
		}	
	}
	cout << x << " " << cnt << "\n";
	return 0;
}