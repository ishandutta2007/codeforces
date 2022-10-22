#include<iostream>
#include<algorithm>
#include<set>

using namespace std;

typedef long long ll;

ll l, r;
ll k;
bool fl = 0;
set<ll>	st;

int main(){
	cin >> l >> r >> k;
	if (r - l <= 7){
		ll mini = 1e18;
		for (int i = 1; i < (1 << (r - l + 1)); i++){
			if (__builtin_popcount(i) > k)	continue;
			ll x = 0;
			for (ll j = 0; j < 10; j++)
				if ((i >> j) & 1)
					x ^= (l + j);
			if (x < mini){
				mini = x;
				st.clear();
				for (ll j = 0; j < 10; j++)
					if ((i >> j) & 1)
						st.insert(l + j);
			}
		}
	}
	else{
		bool fl = 1;
		if (k == 1)
			st.insert(l);
		else if (k >= 4){
			if (l % 2 == 1)	l++;
			st.insert(l);	st.insert(l + 1);	st.insert(l + 2);	st.insert(l + 3);
		}
		else if (k == 3){
			ll a = l;
			ll i = 0;
			for (; a; i++)
				a >>= 1;
			ll b = ll(1) << i;
			b ^= ll(1) << (i - 1);
			if (b <= r){
				st.insert(l);
				st.insert(b);
				st.insert(l ^ b);
				fl = 0;
			}
		}
		
		if (fl && k >= 2){
			if (l % 2 == 1)	l++;
			st.insert(l), st.insert(l + 1);
		}	
	}
	ll ans = 0;
	for (ll u:st)	ans ^= u;
	cout << ans << endl;
	cout << st.size() << endl;
	for (ll u:st)
		cout << u << " " ;
	cout << endl;
	return	0;
}