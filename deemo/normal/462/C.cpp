#include<iostream>
#include<algorithm>

using namespace std;

typedef long long ll;

const ll MAXN = 3e5 + 20;

ll n, vec[MAXN];
ll ans, sum;

void solve(ll rem){
	if (rem == 1)	return;
	ans += sum;
	sum -= vec[n - rem];
	solve(rem - 1);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (ll i = 0; i < n; i++){
		cin >> vec[i];
		sum += vec[i];
	}
	ans = sum;
	sort(vec, vec + n);
	solve(n);	

	cout << ans << endl;
	return	0;
}