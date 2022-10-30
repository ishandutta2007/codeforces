#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;

ll a00,a01,a10,a11,x,y;

ll c2(ll x) {
	return x*(x-1)/2;
}

vector<char> ans;

bool test(ll x, ll y) {
	if(c2(x) != a00 || c2(y) != a11) return false;
	if(a01+a10 != x*y) return false;
	ll vn = 0;
	ll u0=x,u1=y;
	for(int i = 0; i < x+y; ++i) {
		if(u0 && vn + u1 <= a10) {
			--u0;
			vn += u1;
			ans.pb('0');
		} else {
			--u1;
			ans.pb('1');
		}
	}
	for(int i = ans.size()-1; i >= 0; --i)
		cout << ans[i];
	cout << "\n";
	return true;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> a00>>a01>>a10>>a11;
	for(x = 0; c2(x+1) <= a00; ++x);
	for(y = 0; c2(y+1) <= a11; ++y);
	if(test(x,y)) return 0;
	if(x==1 && test(0,y)) return 0;
	if(y==1 && test(x,0)) return 0;
	if(x==1 && y==1 && test(0,0)) return 0;
	cout << "Impossible\n";
	return 0;
}