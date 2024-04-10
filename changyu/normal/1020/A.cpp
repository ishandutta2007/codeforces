#include<cstdio>
inline int abs(int a){return a>0?a:-a;}
int n,m,l,r,t,s;
int main(){
	int u,v,x,y;
	scanf("%d%d%d%d%d",&n,&m,&l,&r,&t);
	for(;t--;){
	  scanf("%d%d%d%d",&u,&x,&v,&y);
	  if(u==v){printf("%d\n",abs(x-y));continue;}
	  if(x>r&&y>r){printf("%d\n",y-r+x-r+abs(u-v));continue;}
	  if(x<l&&y<l){printf("%d\n",l-x+l-y+abs(u-v));continue;}
	  printf("%d\n",abs(x-y)+abs(u-v));
	}return 0;
}