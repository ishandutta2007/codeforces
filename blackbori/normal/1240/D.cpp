#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

map <ll, ll> C[303030];
ll A[303030], P[303030], V[303030];
ll n, ans;

void dnc(ll s, ll e)
{
	if(s >= e) return;
	
	vector <ll> X;
	ll m, i, p, t, x;
	
	m = s + e >> 1;
	p = 1; t = 1;
	
	for(i=m; i>=s; i--){
		if(X.empty() || X.back() != A[i]){
			X.push_back(A[i]);
			if(C[t].find(A[i]) == C[t].end()){
				 C[t][A[i]] = ++p; x = p;
			}
			else x = C[t][A[i]];
			P[x] = t; t = x;
		}
		else{
			X.pop_back();
			t = P[t];
		}
		V[t] ++;
	}
	
	X.clear(); t = 1;
	
	for(i=m+1; i<=e; i++){
		if(X.empty() || X.back() != A[i]){
			X.push_back(A[i]);
			if(C[t].find(A[i]) == C[t].end()){
				 C[t][A[i]] = ++p; x = p;
			}
			else x = C[t][A[i]];
			P[x] = t; t = x;
		}
		else{
			X.pop_back();
			t = P[t];
		}
		ans += V[t];
	}
	
	for(i=1; i<=p; i++){
		C[i].clear(); V[i] = 0;
	}
	
	dnc(s, m); dnc(m + 1, e);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll q, i;
	
	cin >> q;
	
	for(; q--; ){
		cin >> n;
		
		for(i=1; i<=n; i++){
			cin >> A[i];
		}
		
		ans = 0;
		
		dnc(1, n);
		
		cout << ans << "\n";
	}
	
	return 0;
}