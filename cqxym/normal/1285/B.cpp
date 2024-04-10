#include<stdio.h>
#define R register int
long long s[100001],m[100001];
inline void Solve(){
	int n,x;
	scanf("%d",&n);
	long long Max=-1e18;
	for(R i=1;i!=n;i++){
		scanf("%d",&x);
		s[i]=s[i-1]+x;
		if(s[i]-m[i-1]>Max){
			Max=s[i]-m[i-1];
		}
		m[i]=m[i-1]<s[i]?m[i-1]:s[i];
	}
	scanf("%d",&x);
	s[n]=s[n-1]+x;
	for(R i=1;i!=n;i++){
		if(s[n]-s[i]>Max){
			Max=s[n]-s[i];
		}
	}
	if(Max<s[n]){
		puts("YES");
	}else{
		puts("NO");
	}
}
int main(){
	int t;
	scanf("%d",&t);
	for(R i=0;i!=t;i++){
		Solve();
	}
	return 0;
}