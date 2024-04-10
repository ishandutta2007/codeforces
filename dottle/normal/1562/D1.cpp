#include<bits/stdc++.h>
const int N=500050;
using namespace std;

int s[N],n,t,q,sn[]={-1,1};
char S[N];

main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d%d%s",&n,&q,S+1);
		for(int i=1;i<=n;i++)if((S[i]=='+')^(i&1))
			s[i]=s[i-1]+1;
		else 
			s[i]=s[i-1]-1;
		for(int i=1;i<=q;i++){
			int l,r;
			scanf("%d%d",&l,&r);
			if((r-l+1)&1)printf("1\n");
			else if(s[r]-s[l-1])printf("2\n");
			else printf("0\n");
		} 
	}
}