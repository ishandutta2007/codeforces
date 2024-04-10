#include<bits/stdc++.h>
using namespace std;
int n,m,ans;
char a[33][33],p[33][33];
int zad[33][2],zac[33][33],cnt;
int c[22];
int vis[10];
bool used=1;
void dfs(int x,int y){
	if(x==14){
		bool ok=1;
		for(int i=0;i<7;i++)vis[i]=127;
		for(int i=0;i<28&&ok;i++){
			int a=c[zad[i][0]],b=c[zad[i][1]];
			if(a==b){
				if(!(vis[a]&(1<<b)))ok=0;
				else vis[a]^=(1<<b);
			}
			else{
				if(!(vis[a]&(1<<b))||!(vis[b]&(1<<a)))ok=0;
				else vis[a]^=(1<<b),vis[b]^=(1<<a);
			}
		}
		if(ok){
			ans++;
			if(!used)return;
			used=0;
			for(int i=1;i<=n;i++)for(int j=1;j<=m;j++){
				p[i][j]=a[i][j];
				if(~zac[i][j])p[i][j]=c[zac[i][j]]+'0';
			}
		}
		return;
	}
	if(~c[x])dfs(x+1,y);
	else{
		c[x]=y;
		for(int i=x+1;i<14;i++)if(c[i]<0)c[i]=y,dfs(x+1,y+1),c[i]=-1;
		c[x]=-1;
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%s",a[i]+1);
	memset(zad,-1,sizeof(zad)),memset(zac,-1,sizeof(zac));
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)if(a[i][j]!='.'&&zac[i][j]<0)zac[i][j]=zac[i+1][j]=zac[i][j+1]=zac[i+1][j+1]=cnt++;
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)if(a[i][j]!='.'){
		int id=a[i][j]-'a';
		if(a[i][j]=='A')id=26;
		if(a[i][j]=='B')id=27;
		if(zad[id][0]<0)zad[id][0]=zac[i][j];
		else zad[id][1]=zac[i][j];
	}
	memset(c,-1,sizeof(c));
	dfs(0,0);
	printf("%d\n",ans*5040);
	for(int i=1;i<=n;i++,puts(""))for(int j=1;j<=m;j++)putchar(p[i][j]);
}