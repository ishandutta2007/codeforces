#include <iostream>
#include <cstdio>
using namespace std;
struct node{
	int x,y;
}QwQ,pos[15][1000005];
int n,m,p,s[15],head[15],tail[15],ans[15],num;
int moveQwQ[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
char a[1005][1005];
node q[1000005];
int h,t,step[1005][1005];
inline void bfs(int now){
	while(h<=t){
		node c=q[h];
		++h;
		for (int i=0;i<4;i++){
			int x=c.x+moveQwQ[i][0],y=c.y+moveQwQ[i][1];
			if (a[x][y]!='.'||step[c.x][c.y]==s[now])continue;
			step[x][y]=step[c.x][c.y]+1;
			if (a[x][y]=='.'){
				a[x][y]=(char)(now+'0');
				num--;
				++tail[now];
				QwQ.x=x,QwQ.y=y;
				pos[now][tail[now]]=QwQ;
				q[++t]=QwQ;
			}
		}
	}
	for (int i=1;i<=t;i++)step[q[i].x][q[i].y]=0;
	return;
}
int main(){
	cin>>n>>m>>p;
	for (int i=1;i<=p;i++)cin>>s[i],head[i]=1;
	for (int i=1;i<=n;i++)
		scanf("%s",a[i]+1);
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++){
			if (a[i][j]>='0'&&a[i][j]<='9'){
				QwQ.x=i,QwQ.y=j;
				++tail[a[i][j]-'0'];
				pos[a[i][j]-'0'][tail[a[i][j]-'0']]=QwQ;
			}
			if (a[i][j]=='.')num++;
		}
	while(1){
		int lastnum=num;
		for (int i=1;i<=p;i++){
			int x=head[i],y=tail[i];
			head[i]=tail[i]+1;
			h=1,t=0;
			for (int j=x;j<=y;j++)q[++t]=pos[i][j];
			bfs(i);
		}
		if (num==lastnum)break;
	}
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			if (a[i][j]>='0'&&a[i][j]<='9')ans[a[i][j]-'0']++;
	for (int i=1;i<=p;i++)cout<<ans[i]<<' ';
	cout<<endl;
	return 0;
}