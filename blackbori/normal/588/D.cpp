#include <bits/stdc++.h>

#define D(x,y) A[(x)*(n+2)+(y)]
#define mod 1000000007

using namespace std;
typedef long long LL;

LL n,l,k,ans,c,sum;

LL C[1<<20],K[1<<20],A[1<<23],S[1<<20];

struct nn{
	LL val;
	bool f;
}N[1<<20];

bool comp(nn na,nn nb)
{
	return na.val<nb.val;
}

int main()
{
	LL i,j;
	scanf("%I64d%I64d%I64d",&n,&l,&k);
	
	for(i=0;i<n;i++) scanf("%I64d",C+i), N[i].val=C[i], N[i].f = i<l%n;
	
	sort(C,C+n);
	sort(N,N+n,comp);
	
	for(i=0;i<n;i++){
		K[i]=upper_bound(C,C+n,C[i])-C;
	}
	
//	for(i=0;i<n;i++) printf("%I64d %I64d\n",N[i].val,N[i].f);
	
	for(j=0;j<n;j++) D(1,j)=1;
	
	for(i=2;i<=k;i++){
		S[0]=D(i-1,0);
		for(j=1;j<n;j++) S[j]=(D(i-1,j)+S[j-1])%mod;
		
		for(j=0;j<n;j++){
			D(i,j) = S[K[j]-1];
		}
	}
	
	for(i=1;i<=k;i++){
		for(j=0;j<n;j++){
			c=0;
			if((l/n)>=i) c=(l/n-i+1)%mod;
			ans = (ans+D(i,j)*c)%mod;
		}
	}
	
	for(j=0;j<n;j++){
		if(N[j].f){
			for(i=1;i<=k;i++){
				if(i>l/n+1) break;
				ans = (ans+D(i,j))%mod;
			}
		}
	}
	
	printf("%I64d\n",ans);
	
	return 0;
}