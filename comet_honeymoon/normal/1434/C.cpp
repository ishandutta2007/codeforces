#include<bits/stdc++.h>
#define ll long long
using namespace std;

int T;
ll A,B,C,D;

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%lld%lld%lld%lld",&A,&B,&C,&D);
		if(A>B*C){printf("-1\n");continue;}
		//c=inf
		ll h=B*D,h2=h+2*A;
		ll t1=h2/h/2,t2=t1+1;
		ll w1=(t1*h2-t1*t1*h)/2,w2=(t2*h2-t2*t2*h)/2;
		printf("%lld\n",max(w1,w2));
	}
}