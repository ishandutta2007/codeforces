#include<stdio.h>
#define R register int
char opt[500001];
int tot,len[500001];
inline void AddOpt(char type,int l){
	opt[tot]=type;
	len[tot]=l;
	tot++;
}
int main(){
	int n,m,k,p,ct=0;
	scanf("%d%d%d",&n,&m,&k);
	p=k;
	if(4ll*n*m-2*n-2*m<k){
		printf("NO");
		return 0;
	}
	puts("YES");
	if(n==1){
		AddOpt('R',m-1);
		AddOpt('L',m-1);
	}else if(m==1){
		AddOpt('D',n-1);
		AddOpt('U',n-1);
	}else{
		AddOpt('D',n-1);
		for(R i=1;i!=m;i++){
			AddOpt('U',n-1);
			AddOpt('R',1);
			AddOpt('D',n-1);
		}
		AddOpt('L',m-1);
		for(R i=1;i!=n;i++){
			AddOpt('R',m-1);
			AddOpt('U',1);
			AddOpt('L',m-1);
		}
	}
	for(R i=0;i!=tot;i++){
		ct++;
		if(p<=len[i]){
			break;
		}
		p-=len[i];
	}
	printf("%d",ct);
	for(R i=0;i!=ct;i++){
		puts("");
		if(k>len[i]){
			printf("%d",len[i]);
			k-=len[i];
		}else{
			printf("%d",k);
		}
		printf(" %c",opt[i]);
	}
	return 0;
}