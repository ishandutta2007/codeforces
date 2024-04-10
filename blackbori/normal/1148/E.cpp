#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair <ll, ll> pll;

struct mv{
	ll i, j, d;
	mv() {}
	mv(ll i, ll j, ll d) : i(i), j(j), d(d) {}
};

vector <mv> V;
pll S[303030], T[303030];
ll n;

void die() { printf("NO\n"); exit(0); }

int main()
{
	ll i, j;
	
	scanf("%lld", &n);
	
	for(i=0; i<n; i++){
		scanf("%lld", &S[i].first);
		S[i].second = i + 1;
	}
	
	for(i=0; i<n; i++){
		scanf("%lld", &T[i].first);
		T[i].second = i + 1;
	}
	
	sort(S, S + n); sort(T, T + n);
	
	for(i=0, j=0; i<n; i++){
		if(S[i].first - T[i].first > 0) die();
		else if(S[i].first - T[i].first == 0) continue;
		
		for(; j<n; j++){
			if(S[j].first - T[j].first > 0){
				if(S[j].first - T[j].first > T[i].first - S[i].first){
					V.emplace_back(S[i].second, S[j].second, T[i].first - S[i].first);
					S[j].first -= (T[i].first - S[i].first);
					S[i].first = T[i].first; break;
				}
				else{
					V.emplace_back(S[i].second, S[j].second, S[j].first - T[j].first);
					S[i].first += (S[j].first - T[j].first);
					S[j].first = T[j].first;
				}
			}
		}
		
		if(S[i].first - T[i].first != 0) die();
	}
	
	printf("YES\n");
	
	printf("%lld\n", (ll)V.size());
	
	for(mv &t: V){
		printf("%lld %lld %lld\n", t.i, t.j, t.d);
	}
	
	return 0;
}