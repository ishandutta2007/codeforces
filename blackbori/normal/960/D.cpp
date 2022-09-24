#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll S[111];
ll q,t;

int main()
{
	ll a,b,i,j;
	
	scanf("%lld",&q);
	
	for(;q--;){
		scanf("%lld",&t);
		if(t == 1){
			scanf("%lld%lld",&a,&b);
			for(i=0;a>1;a>>=1,i++);
			b = b % (1ull<<i);
			S[i] += b;
		}
		else if(t == 2){
			scanf("%lld%lld",&a,&b);
			for(i=0;a>1;a>>=1,i++);
			for(j=i;j<=62;j++){
				b = b % (1ull<<j);
				S[j] += b;
				b = (b << 1ull);
			}
		}
		else{
			scanf("%lld",&a); b = a;
			for(i=0;a>1;a>>=1,i++);
			b = (1ull<<i) + ((b + S[i]) % (1ull<<i) + (1ull<<i)) % (1ull<<i);
			for(j=i;j>=0;j--){
				printf("%lld ",(1ull<<j) + ((b - S[j]) % (1ull<<j) + (1ull<<j)) % (1ull<<j));
				b >>= 1;
			}
			printf("\n");
		}
	}
	
	return 0;
}