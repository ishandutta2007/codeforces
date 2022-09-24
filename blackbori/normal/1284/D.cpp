#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair <ll, ll> pll;
 
struct segtree{
	ll T[606060];
	ll sz = 1 << 18;
	
	void init()
	{
		ll i;
		
		for(i = 0; i < sz + sz; i ++){
			T[i] = 0;
		}
	}
	
	void update(ll p, ll v)
	{
		p += sz; T[p] = max(T[p], v);
		for(p >>= 1; p; p >>= 1){
			T[p] = max(T[p << 1], T[p << 1 | 1]);
		}
	}
	
	ll getmax(ll l, ll r)
	{
		ll ret = 0;
		
		l += sz; r += sz;
		
		for(; l <= r; ){
			if(l & 1) ret = max(ret, T[l]);
			if(~r & 1) ret = max(ret, T[r]);
			l = l + 1 >> 1; r = r - 1 >> 1;
		}
		
		return ret;
	}
};
 
void die() { cout << "NO\n"; exit(0); }
 
segtree T1, T2;
vector <pll> V;
vector <ll> X;
ll I1[101010], I2[101010], I3[101010], I4[101010];
ll L[101010], R[101010];
ll n, x;
 
void f()
{
	ll i, l, r;
	
	T1.init(); T2.init();
	X.clear(); V.clear();
	
	for(i = 1; i <= n; i ++){
		l = I1[i]; r = I2[i]; L[i] = I3[i]; R[i] = I4[i];
		V.emplace_back(l, -i);
		V.emplace_back(r, i);
		X.push_back(L[i]); X.push_back(R[i]);
	}
	
	sort(V.begin(), V.end());
	sort(X.begin(), X.end());
	X.erase(unique(X.begin(), X.end()), X.end());
	
	x = X.size();
	
	for(i = 1; i <= n; i ++){
		L[i] = lower_bound(X.begin(), X.end(), L[i]) - X.begin() + 1;
		R[i] = lower_bound(X.begin(), X.end(), R[i]) - X.begin() + 1;
	}
	
	for(pll p: V){
		if(p.second < 0){
			i = -p.second;
			if(T1.getmax(1, L[i] - 1) >= L[i]) die();
			if(x - T2.getmax(R[i] + 1, x) + 1 <= R[i]) die();
		}
		else{
			i = p.second;
			T1.update(L[i], R[i]);
			T2.update(R[i], x - L[i] + 1);
		}
	}
}
 
int main()
{	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll i;
	
	cin >> n;
	
	for(i = 1; i <= n; i ++){
		cin >> I1[i] >> I2[i] >> I3[i] >> I4[i];
	}
	
	f();
	
	for(i = 1; i <= n; i ++){
		swap(I1[i], I3[i]); swap(I2[i], I4[i]);
	}
	
	f();
	
	cout << "YES\n";
	
	return 0;
}