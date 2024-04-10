#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

map <string,ll> M;
ll T[101010], C[101010], G[101010];
string s;
char str[33];
ll n,m,k,ans;

int main()
{
	ll i,j,a,b;
	
	scanf("%lld%lld%lld",&n,&k,&m);
	
	for(i=0;i<n;i++){
		scanf("%s",str);
		s = str;
		M[s] = i;
	}
	
	for(i=0;i<n;i++) scanf("%lld",C+i);
	
	for(i=0;i<k;i++){
		T[i] = 2e9;
		scanf("%lld",&a);
		for(j=0;j<a;j++){
			scanf("%lld",&b); b--;
			T[i] = min(T[i], C[b]);
			G[b] = i;
		}
	}
	
	for(i=0;i<m;i++){
		scanf("%s",str);
		s = str;
		ans += T[G[M[s]]];
	}
	
	printf("%lld\n",ans);
	
	return 0;
}