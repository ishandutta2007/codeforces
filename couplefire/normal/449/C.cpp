#include<cstdio>
 
void add(int a,int b);
 
bool vis[100010];
void makeGroups(int n){
	// make maximum possible number of groups
	for(int x=3;;x+=2,x*2>n?x=2:1)if(!vis[x]){
		int cnt=0;
		for(int i=x;i<=n;i+=x)if(!vis[i])cnt++;
		for(int i=0,j;i<=n;i=j){
			for(i+=x;i<=n&&(vis[i]||cnt%2&&i==x*2);i+=x);
			for(j=i+x;j<=n&&(vis[j]||cnt%2&&j==x*2);j+=x);
			if(j<=n)vis[i]=vis[j]=1,add(i,j);
		}
		if(x==2)return;
	}
}
 
int m,x[100010],y[100010];
void add(int a,int b){x[m]=a;y[m++]=b;}
int main(){
	int n;scanf("%d",&n);
	makeGroups(n);
	printf("%d\n",m);
	for(int i=0;i<m;i++)printf("%d %d\n",x[i],y[i]);
}