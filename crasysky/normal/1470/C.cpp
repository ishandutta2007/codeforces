#include <bits/stdc++.h>
int query(int x){
	printf("? %d\n",x); fflush(stdout);
	int s; scanf("%d",&s); return s;
}	
int n; int M(int x){ x=(x%n+n)%n; return x==0?n:x; }
signed main(){
	int k,p=1,x,c=0; scanf("%d%d",&n,&k);
	for (;query(p)<=k;p=M(p+c),++c);
	for (int j=20,s=0;j>=0;--j)
		if ((s+(1<<j))<=c&&query(M(p-(1<<j)))>k) p=M(p-(1<<j)),s+=1<<j;
	printf("! %d\n",M(p-1)); fflush(stdout);
	return 0;
}