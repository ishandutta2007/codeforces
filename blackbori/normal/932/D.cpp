#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll P[404040][21], M[404040][21], K[404040][21], S[404040][21], D[404040];
ll cnt, last;

void add(ll p,ll w)
{
//	printf("%lld %lld ",p,w);
	
	ll i,j;
	
	cnt++; P[cnt][0] = p; M[cnt][0] = w;
	
	for(i=1;i<20;i++){
		P[cnt][i] = P[P[cnt][i-1]][i-1];
		M[cnt][i] = max(M[cnt][i-1], M[P[cnt][i-1]][i-1]);
	}
	
	for(j = P[cnt][0],i=19;i>=0;i--){
		if(M[j][i] < w) j = P[j][i];
	}
	
//	printf("%lld\n",j);
	
	K[cnt][0] = j; S[cnt][0] = w; D[cnt] = D[j] + 1;
		
	for(i=1;i<20;i++){
		K[cnt][i] = K[K[cnt][i-1]][i-1];
		S[cnt][i] = S[cnt][i-1] + S[K[cnt][i-1]][i-1];
	}
}

ll query(ll p,ll x)
{
	ll i, ret = 0;
	
	for(i=19;i>=0;i--){
		if(S[p][i] <= x && 1<<i <= D[p]){
			x -= S[p][i];
			p = K[p][i];
			ret += 1<<i;
		}
	}
	
	return ret;
}

int main()
{
	ll q,a,b,c;
	
	scanf("%lld",&q);
	
	cnt ++; D[1] = 1;
	
	for(;q--;){
		scanf("%lld%lld%lld",&a,&b,&c);
		b ^= last, c ^= last;
		
		if(a == 1) add(b,c);
		else{
			last = query(b,c);
			printf("%lld\n",last);
		}
	}
	return 0;
}