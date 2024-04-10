#include<stdio.h>
#define R register int
char s[400000];
int len[400000];
inline void Solve(){
	int n,ct=0;
	scanf("%d\n",&n);
	for(R i=1;i<=n;i++){
		len[i]=0;
	}
	for(R i=1;i<=n;i++){
		s[i]=getchar();
		if(s[i]!=s[i-1]){
			ct++;
		}
		len[ct]++;
	}
	if(ct==1){
		printf("%d\n",(n+2)/3);
	}else{
		if(s[n]==s[1]){
			len[1]+=len[ct];
			ct--;
		}
		int sum=0;
		for(R i=1;i<=ct;i++){
			sum+=len[i]/3;
		}
		printf("%d\n",sum);
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