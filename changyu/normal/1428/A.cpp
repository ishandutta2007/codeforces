#include<cstdio>
#include<algorithm>
int x,y,xx,yy; 
int main(){
	int T;scanf("%d",&T);for(;T--;){
	scanf("%d%d%d%d",&x,&y,&xx,&yy);
	if(x==xx||y==yy)printf("%d\n",std::abs(x-xx)+std::abs(y-yy));
	else printf("%d\n",std::abs(x-xx)+std::abs(y-yy)+2);
	}return 0;
}