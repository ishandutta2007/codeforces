#include<stdio.h>
#include<algorithm>
#define R register int
#define L long long
int ct[54];
inline void Solve(){
	int n,k,s;
	scanf("%d%d",&n,&k);
	L x;
	for(R i=0;i!=54;i++){
		ct[i]=0;
	}
	for(R i=0;i!=n;i++){
		scanf("%lld",&x);
		s=0;
		while(x!=0){
			ct[s]+=x%k;
			s++;
			x/=k;
		}
	}
	for(R i=0;i!=54;i++){
		if(ct[i]>1){
			puts("NO");
			return;
		}
	}
	puts("YES");
}
int main(){
	int t;
	scanf("%d",&t);
	for(R i=0;i!=t;i++){
		Solve();
	}
	return 0;
}