#include <bits/stdc++.h>
#pragma GCC optimize(3,"Ofast","inline")
void read(int &x){
	register char ch=getchar();register int res=1;x=0;
	for(;ch==' '||ch=='\n';ch=getchar());
	if(ch=='-')res=-1,ch=getchar();
	for(;ch!=' '&&ch!='\n';x=x*10+ch-'0',ch=getchar());
	x*=res;
}
void write(int x){
	if(x>9)write(x/10);
	putchar(x%10+'0'); 
}
int n,q,d[1000004],X,now,num;
void Add(int id,int x){while(id<=n)d[id]+=x,id+=(id&-id);}
int Ans(int id){int ret=0;while(id)ret+=d[id],id-=(id&-id);}
int Bs(int k){
	now=0,num=0;
	for(int i=19,j=(1<<19);i>=0;i--,j>>=1)if(now+j<=n && d[now+j]+num<k)num+=d[now+j],now+=j;
	return now+1;
}
int main(){
	read(n),read(q);
	for(int i=1;i<=n;i++)read(X),Add(X,1);
	for(int i=1;i<=q;i++){
		read(X);
		if(X<0) Add(Bs(-X),-1);
		else Add(X,1);
	}
	for(int i=1;i<=n;i++)if(d[i]>0){
		write(i);return 0;
	}
	puts("0");
}