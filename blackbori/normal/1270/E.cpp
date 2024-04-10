#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair <ll, ll> pll;

vector <ll> V;
ll X[1010], Y[1010];
ll n;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll i;
	
	cin >> n;
	
	for(i = 1; i <= n; i ++){
		cin >> X[i] >> Y[i];
	}
	
	for(; ; ){
		V.clear();
		
		for(i = 1; i <= n; i ++){
			if((X[i] ^ Y[i]) & 1) V.push_back(i);
		}
		
		if(V.size() == 0){
			for(i = 1; i <= n; i ++){
				tie(X[i], Y[i]) = pll(X[i] + Y[i] >> 1, X[i] - Y[i] >> 1);
			}
		}
		else if(V.size() == n){
			for(i = 1; i <= n; i ++){
				Y[i] --;
			}
			
			for(i = 1; i <= n; i ++){
				tie(X[i], Y[i]) = pll(X[i] + Y[i] >> 1, X[i] - Y[i] >> 1);
			}
		}
		else{
			cout << (ll)V.size() << "\n";
			for(ll &t: V) cout << t << " ";
			cout << "\n";
			return 0;
		}
	}
	
	return 0;
}