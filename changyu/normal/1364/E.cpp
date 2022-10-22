#include<bits/stdc++.h>
const int K=11,N=1<<K,D=14;
std::mt19937 mtrand(time(0));
int a[N],rt,n,p[N];
inline int Query(int i,int j){printf("? %d %d\n",i+1,j+1),fflush(stdout);int res;scanf("%d",&res);return res;}
inline void Get(int i){
	for(int J=1;J<=D;J++){
		int j;
		for(j=mtrand()%n;j==i;j=mtrand()%n);
		a[i]&=Query(i,j);
	}
}
int main(){
	scanf("%d",&n);
	std::fill(a,a+n,-1);
	std::iota(p,p+n,0);
	std::shuffle(p+1,p+n,mtrand);
	Get(rt=p[0]);
	for(int id=1,i;id<n;id++){
		i=p[id];
		if(Query(rt,i)==a[rt])
			Get(rt=i);
	}
	for(int i=0;i<n;i++)
		if(a[i]<0)
			a[i]=Query(rt,i);
	printf("!");for(int i=0;i<n;i++)printf(" %d",a[i]);puts("");
	return 0;
}