#include<iostream>
#include<algorithm>
#include<vector>
#include<set>

using namespace std;

typedef long long ll;

const ll C = 10;
const ll MAX = 1e9;

ll n, ans = 0;
set<ll>	st;

int main(){
	cin >> n;
	for (ll i = 1; i <= 9; i++){
		for (ll z = 0; z < (1 << C) - 1; z++){
			ll x = i, y = z;
			for (ll w = 0; w < C; w++, y >>= 1){
				if (y & 1)	x = (x * 10) + i;
				else	x = x * 10;
				if (x <= n)	st.insert(x);
			}
		}
	}
	
	for (ll i = 1; i < 10; i++)
		for (ll j = i + 1; j < 10; j++){
			for (ll z = 1; z < (1 << C) - 1; z++){
				ll x = 0, y = z;
				for (ll w = 0; w < C; w++, y >>= 1){
					if (y & 1)	x = (x * 10) + i;
					else	x = (x * 10) + j;
					if (x <= n)	st.insert(x);
				}
			}
		}
	cout << (ll)st.size() << endl;
	return 0;	
}