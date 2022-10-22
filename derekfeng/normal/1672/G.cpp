#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M=998244353;
int r,c,w[4004];
char s[2002][2002];
vector<int>g[4004];
void sol0(){
	int ans=1;
	for(int i=1;i<=r;i++)for(int j=1;j<=c;j++)
		if(s[i][j]=='?')ans=ans*2%M;
	printf("%d",ans);
	exit(0);
}
void sol1(){
	int ans=0;
	for(int t=0;t<2;t++){
		int all=1;
		for(int i=1;i<=r;i++){
			int cnt=0,sum=0;
			for(int j=1;j<=c;j++){
				if(s[i][j]=='?')cnt++;
				else sum^=(s[i][j]-'0');
			}
			if(cnt==0)all=all*(sum==t?1:0);
			else for(int j=0;j<cnt-1;j++)all=all*2%M;
		}
		(ans+=all)%=M;
	}
	printf("%d",ans);
	exit(0);
}
void sol2(){
	swap(r,c);
	for(int i=1;i<=max(r,c);i++)for(int j=1;j<=max(r,c);j++)
		if(i<j)swap(s[i][j],s[j][i]);
	sol1();
}
bool vis[4004];
int ver,edg,tmp;
void dfs(int x){
	if(vis[x])return;
	vis[x]=1,tmp^=w[x],ver++,edg+=g[x].size();
	for(auto y:g[x])dfs(y);
}
void sol3(){
	for(int i=1;i<=r;i++)for(int j=1;j<=c;j++){
		int a=i,b=r+j;
		if(s[i][j]=='?')g[a].push_back(b),g[b].push_back(a);
		else w[a]^=s[i][j]-'0',w[b]^=s[i][j]-'0';
	}
	int ans=0;
	for(int t=0;t<2;t++){
		int all=1;
		memset(vis,0,sizeof(vis));
		for(int i=1;i<=r+c;i++)if(!vis[i]){
			ver=edg=tmp=0,dfs(i);
			edg=edg/2-(ver-1);
			int mul=1;
			for(int j=0;j<edg;j++)mul=mul*2%M;
			if(ver&1)all=(ll)all*((tmp^t)?0:mul)%M;
			else all=(ll)all*(tmp?0:mul)%M;
		}
		(ans+=all)%=M;
	}
	printf("%d",ans);
}
int main(){
	scanf("%d%d",&r,&c);
	for(int i=1;i<=r;i++)scanf("%s",s[i]+1);
	if(r%2==0&&c%2==0)sol0();
	if(r%2==0&&c%2==1)sol1();
	if(r%2==1&&c%2==0)sol2();
	if(r%2==1&&c%2==1)sol3();
}