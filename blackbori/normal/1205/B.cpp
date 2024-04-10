#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

queue <ll> Q;
vector <ll> G[4040], V;
ll L[4040], P[4040], S[66];
bool chk[4040];
ll n, ans;

void bfs(ll p)
{
	ll x, i;
	
	x = p;
	
	for(i=0; i<n; i++){
		chk[i] = 0; L[i] = 0;
	}
	
	Q.push(p); chk[p] = 1;
	
	for(; !Q.empty(); ){
		p = Q.front(); Q.pop();
		for(ll &t: G[p]) if(!chk[t]){
			Q.push(t); chk[t] = 1;
			L[t] = L[p] + 1;
			P[t] = p;
		}
	}
	
	for(i=0; i<n; i++) if(i != x && chk[i]){
		for(ll &t: G[i]) if(t != x && chk[t]){
			if(L[i] == L[t]) ans = min(ans, L[i] + L[t] + 1);
			else if((L[i] == L[t] + 1 && P[i] != t) || (L[t] == L[i] + 1 && P[t] != i)){
				ans = min(ans, L[i] + L[t] + 1);
			}
		}
	}
}

int main()
{
	ll i, j, a, s;
	
	scanf("%lld", &n);
	
	for(i=0; i<n; i++){
		scanf("%lld", &a);
		
		s = 0;
		
		for(j=0; j<62; j++) if(a & 1ll << j){
			s ++;
			S[j] ++;
		}
		
		if(s > 1) V.push_back(a);
	}
	
	n = V.size();
	
	for(j=0; j<62; j++){
		if(S[j] >= 3){
			printf("3\n");
			return 0;
		}
	}
	
	for(i=0; i<n; i++){
		for(j=i+1; j<n; j++){
			if(V[i] & V[j]){
				G[i].push_back(j);
				G[j].push_back(i);
			}
		}
	}
	
	ans = 1e9;
	
	for(i=0; i<n; i++){	
		bfs(i);
	}
	
	if(ans < 1e9) printf("%lld\n", ans);
	else printf("-1\n");
	
	return 0;
}