#include<bits/stdc++.h>
using namespace std;
const int M=1e9+7;
char s[1003],c[26],X[55],Y[55];
int nxt[26003][10],cnt=1,flg[26003],fal[26003];
int n,d;
void add(){
	int cur=1,len=d/2;
	for(int i=0;i<len;i++){
		int v=c[i]-'0';
		if(nxt[cur][v]<1)nxt[cur][v]=++cnt;
		cur=nxt[cur][v];
	}
	flg[cur]=1;
}
void getfail(){
	for(int i=0;i<10;i++)nxt[0][i]=1;
	queue<int>q;q.push(1);fal[1]=0;
	while(!q.empty()){
		int u=q.front();q.pop();
		for(int i=0;i<10;i++){
			int v=nxt[u][i],Fal=fal[u];
			if(!v){nxt[u][i]=nxt[Fal][i];continue;}
			fal[v]=nxt[Fal][i];
			q.push(v);
		}
	}
}
int f[263003][2][2],g[263003][2][2],ans=0;
int main(){
	scanf("%s%s%s",s,X,Y),n=strlen(s),d=strlen(X);
	for(int i=0;i+d/2<=n;i++){
		for(int j=0;j<d/2;j++)c[j]=s[j+i];
		add();
	}
	getfail();
	f[1][0][0]=1;
	for(int i=0;i<d;i++){
		memset(g,0,sizeof(g));
		for(int j=1;j<=cnt;j++)for(int k=0;k<2;k++)for(int l=0;l<2;l++)if(f[j][k][l])
			for(int p=0;p<10;p++)if(l||p<=Y[i]-'0')
				(g[nxt[j][p]][k|flg[nxt[j][p]]][l|(p<Y[i]-'0')]+=f[j][k][l])%=M;
		for(int j=1;j<=cnt;j++)for(int k=0;k<2;k++)for(int l=0;l<2;l++)f[j][k][l]=g[j][k][l];
	}
	for(int i=1;i<=cnt;i++)for(int j=0;j<2;j++)(ans+=f[i][1][j])%=M;
	memset(f,0,sizeof(f));
	f[1][0][0]=1;
	for(int i=0;i<d;i++){
		memset(g,0,sizeof(g));
		for(int j=1;j<=cnt;j++)for(int k=0;k<2;k++)for(int l=0;l<2;l++)if(f[j][k][l])
			for(int p=0;p<10;p++)if(l||p<=X[i]-'0')
				(g[nxt[j][p]][k|flg[nxt[j][p]]][l|(p<X[i]-'0')]+=f[j][k][l])%=M;
		for(int j=1;j<=cnt;j++)for(int k=0;k<2;k++)for(int l=0;l<2;l++)f[j][k][l]=g[j][k][l];
	}
	for(int i=1;i<=cnt;i++)for(int j=0;j<2;j++)(ans+=M-f[i][1][j])%=M;
	int cur=1;
	for(int i=0;i<d;i++){
		cur=nxt[cur][X[i]-'0'];
		if(flg[cur]){
			ans++;
			break;
		}
	}
	printf("%d",ans%M);
}