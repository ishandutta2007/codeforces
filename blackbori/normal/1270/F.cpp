#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll sz = 400;

int M[(sz + 1) * 202020];
vector <ll> X;
string S;
ll n, cnt, ans;

void solve1(ll k)
{
	ll i, s;
	
	M[n] = 1;
	
	for(i = 0, s = n; i < n; i ++){
		if(S[i] == '1') s += k - 1;
		else s --;
		ans += M[s] ++;
	}
	
	M[n] = 0;
	
	for(i = 0, s = n; i < n; i ++){
		if(S[i] == '1') s += k - 1;
		else s --;
		M[s] = 0;
	}
}

void solve2(ll k)
{
	ll i, j, l, r;
	
	for(i = 1, j = 1; i <= n; i ++){
		// X[j] ~ X[j + k - 1]
		if(j + k - 1 <= cnt){
			l = X[j + k - 1] - i + 1;
			r = X[j + k] - i;
			
			if(l % k) l = l - (l % k) + k;
			l = max(l, k * (sz + 1));
			r = r - (r % k);
			
			if(l <= r) ans += (r - l) / k + 1;
		}
		
		if(i == X[j]) j ++;
	}
	
//	cout << k << " " << ans << "\n";
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll i;
	
	cin >> S;
	
	n = S.size();
	
	X.push_back(0);
	
	for(i = 0; i < n; i ++){
		if(S[i] == '1') cnt ++, X.push_back(i + 1);
	}
	
	X.push_back(n + 1);
	
	// (len) / (num of 1) <= sz
	
	for(i = 1; i <= sz; i ++){
		solve1(i);
	}
	
	// (len) / (num of 1) > sz
	// (num of 1) < n / sz
	
	for(i = 1; i <= n / sz; i ++){
		solve2(i);
	}
	
	cout << ans << "\n";
	
	return 0;
}