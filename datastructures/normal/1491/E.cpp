#include <iostream>
#include <cstdio>
using namespace std;
int n,u[1000005],v[1000005],first[1000005],nxt[1000005];
int fib[1000005],c[1000005],book[1000005];
int size[1000005],x,y;
inline void getxy(register int now,register int fa,register int s){
	size[now]=1;
	for (register int i=first[now];i;i=nxt[i])
		if (v[i]!=fa&&book[v[i]]==0)getxy(v[i],now,s),size[now]+=size[v[i]];
	if (size[now]==fib[s-2]){
		x=now,y=fa;
		return;
	}
	if (size[now]==fib[s-1]){
		x=fa,y=now;
		return;
	}
	return;
}
inline void calc(register int now,register int fa,register int val){
	if (val==-1){
		if (book[now]==0)return;
		book[now]=0;
	}
	if (val==1){
		if (book[now]==1)return;
		book[now]=1;
	}
	for (register int i=first[now];i;i=nxt[i])
		if (v[i]!=fa)calc(v[i],now,val);
	return;
}
inline bool dfs(register int now,register int fa,register int s){
	if (s<=3)return 1;
	x=y=-1;
	getxy(now,fa,s);
	if (x==-1)return 0;
	register int ans=1;
	register int _x=x,_y=y;
	book[_y]=1,ans=ans&&dfs(_x,_y,s-2);
	book[_y]=0,ans=ans&&dfs(_y,_x,s-1);
	calc(now,fa,1);
	return ans;
}
int main(){
	cin>>n;
	for (int i=1;i<n;i++){
		scanf("%d%d",&u[i],&v[i]);
		nxt[i]=first[u[i]],first[u[i]]=i;
		u[i+n]=v[i],v[i+n]=u[i];
		nxt[i+n]=first[u[i+n]],first[u[i+n]]=i+n;
	}
	fib[0]=0,fib[1]=1;
	for (register int i=2;;i++){
		fib[i]=fib[i-1]+fib[i-2];
		if (fib[i]>n)break;
		c[fib[i]]=i; 
	}
	if (c[n]==0){
		puts("NO");
		return 0;
	}
	if (dfs(1,0,c[n]))puts("YES");
	else puts("NO");
	return 0;
}