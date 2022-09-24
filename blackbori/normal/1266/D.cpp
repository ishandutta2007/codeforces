#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct edge{
	ll u, v, c;
	edge() {}
	edge(ll u, ll v, ll c) : u(u), v(v), c(c) {}
};

vector <edge> E;
vector <ll> X, Y;
ll D[101010];
ll n, m;

int main()
{
	ll i, j, a, b, c;
	
	scanf("%lld%lld", &n, &m);
	
	for(; m --; ){
		scanf("%lld%lld%lld", &a, &b, &c);
		D[a] += c; D[b] -= c;
	}
	
	for(i = 1; i <= n; i ++){
		if(D[i] > 0) X.push_back(i);
		if(D[i] < 0) Y.push_back(i);
	}
	
	for(i = 0, j = 0; i < X.size(); i ++){
		for(; j < Y.size(); ){
			if(D[X[i]] == -D[Y[j]]){
				E.emplace_back(X[i], Y[j], D[X[i]]);
				j ++; break;
			}
			else if(D[X[i]] < -D[Y[j]]){
				E.emplace_back(X[i], Y[j], D[X[i]]);
				D[Y[j]] += D[X[i]]; break;
			}
			else{
				E.emplace_back(X[i], Y[j], -D[Y[j]]);
				D[X[i]] += D[Y[j]]; j ++;
			}
		}
	}
	
	printf("%lld\n", (ll)E.size());
	
	for(edge &e: E){
		printf("%lld %lld %lld\n", e.u, e.v, e.c);
	}
	
	return 0;
}