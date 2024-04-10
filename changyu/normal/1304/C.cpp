#include<bits/stdc++.h>
const int N=103;
int t,l,r,L,R,n,la;
int main(){
	int T;scanf("%d",&T);for(;T--;){
	scanf("%d%d",&n,&L),R=L;
	la=0;
	for(int i=1;i<=n;i++){
	  scanf("%d%d%d",&t,&l,&r);
	  R+=t-la,L-=t-la;
	  L=std::max(L,l),R=std::min(R,r);
	  if(L>R){
		for(int j=i+1;j<=n;j++)scanf("%d%d%d",&t,&l,&r);
		puts("no");goto Brk;
	  }
	  la=t;
	}puts("yes");Brk:;
	}return 0;
}