#include<bits/stdc++.h>
#define ll long long
#define fo(i,j,k) for(int i=(j),end_i=(k);i<=end_i;i++)
#define fd(i,j,k) for(int i=(j),end_i=(k);i>=end_i;i--)
using namespace std;
template<class T>
void read(T &x){
	x=0;
	char c=getchar();
	while(c>'9'||c<'0')c=getchar();
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
}
int n;
void ask(int x,int flg){
	int i;
	if(flg==1){
		printf("?");
		for(i=1;i<=n;++i){
			if(i==x)printf(" 2");
			else printf(" 1");
		}
	}
	else{
		printf("?");
		for(i=1;i<=n;++i){
			if(i==x)printf(" 1");
			else printf(" 2");
		}
	}
	puts("");
	fflush(stdout);
}
int pre[102],nxt[102],a[102];
int main(){
	read(n);
	int i,x,j=0;
	for(i=1;i<=n;++i){
		ask(i,1);
		scanf("%d",&x);
		if(x!=i){
			if(x==0)x=n+1;
			pre[x]=i;
			nxt[i]=x;
		}
	}
	for(i=1;i<=n;++i){
		ask(i,-1);
		scanf("%d",&x);
		if(x!=i){
			pre[i]=x;
			nxt[x]=i;
		}
	}
	for(i=1;i<=n;++i){
		j=nxt[j];
		a[j]=i;
	}
	printf("!");
	for(i=1;i<=n;++i)printf(" %d",a[i]);
	return 0;
}