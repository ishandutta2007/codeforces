#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
int n,a[4000004];
char s[2002];
vector<pii>gr[4000004];
int I(int x,int y){return (x-1)*n+y;}
void adde(int x,int y,int c){
	gr[x].push_back({y,c});
	gr[y].push_back({x,c});
}
bool dfs(int x){
	for(auto [y,c]:gr[x]){
		if(~a[y]){
			if(a[y]!=a[x]^c)return 0;
		}else{
			a[y]=a[x]^c;
			if(!dfs(y))return 0;
		}
	}
	return 1;
}
int main(){
	scanf("%d",&n);
	if(n&1)return puts("NONE"),0;
	for(int i=1;i<=n;i++){
		scanf("%s",s+1);
		for(int j=1;j<=n;j++)
			a[I(i,j)]=s[j]=='.'?-1:(s[j]=='S'?0:1);
	}
	for(int i=1;i<=n;i+=2)
		for(int j=i-1,k=2;j;j--,k++)
			adde(I(j,k),I(j+1,k-1),1);
	for(int i=2;i<=n;i+=2)
		for(int j=n-1,k=i+1;k<=n;j--,k++)
			adde(I(j,k),I(j+1,k-1),1);
	for(int i=2;i<=n;i+=2)
		for(int j=2,k=i+1;k<=n;j++,k++)
			adde(I(j,k),I(j-1,k-1),1);
	for(int i=2;i<=n;i+=2)
		for(int j=i+1,k=2;j<=n;j++,k++)
			adde(I(j,k),I(j-1,k-1),1);
	for(int i=n;i;i-=2){
		adde(I(i,1),I(i-1,1),0);
		adde(I(1,i),I(1,i-1),0);
		adde(I(n,i),I(n,i-1),0);
		adde(I(i,n),I(i-1,n),0);
	}
	for(int i=1;i<=n*n;i++)if(~a[i]&&!dfs(i))return puts("NONE"),0;
	for(int i=1;i<=n*n;i++)if(!~a[i])return puts("MULTIPLE"),0;
	puts("UNIQUE");
	for(int i=1;i<=n;i++,puts(""))for(int j=1;j<=n;j++)putchar(a[I(i,j)]?'G':'S');
}