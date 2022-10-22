#include<bits/stdc++.h>
int x,y,a,b;
int main(){
	int T;scanf("%d",&T);for(;T--;){
	  scanf("%d%d%d%d",&x,&y,&a,&b);
	  if((y-x)%(a+b))puts("-1");
	  else printf("%d\n",(y-x)/(a+b));
	}return 0;
}