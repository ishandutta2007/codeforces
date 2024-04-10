#include<bits/stdc++.h>
#define ll long long
using namespace std;

int T;
int N;ll L,R; 

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%lld%lld",&N,&L,&R);
		if(L==R&&L==1LL*N*(N-1)+1){printf("1\n");continue;}
		ll i=N-1;
		for(;i;i--){
			if(L>2*i) L-=2*i,R-=2*i;
			else break;
		}
		ll u=N-i,v=(L-1)/2+u;
		for(i=L;i<=R;i++){
			if(v==N) u++,v=u;
			if(u==N){printf("1 ");break;}
			if(i&1LL) printf("%lld ",u);
			else v++,printf("%lld ",v);
		}
		printf("\n");
	}
	return 0;
}