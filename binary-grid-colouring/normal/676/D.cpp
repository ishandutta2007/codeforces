#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1000+5;
const int inf=1e9;
char s[4][N][N];
int d[4][N][N],n,m;
bool vis[4][N][N];
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
bool go(int i,int j,int k,int z){
	switch(s[z][i][j]){
		case '+':return true;
		case '-':return k==0||k==2;
		case '|':return k==1||k==3;
		case '^':return k==3;
		case '>':return k==0;
		case '<':return k==2;
		case 'v':return k==1;
		case 'L':return k!=2;
		case 'R':return k!=0;
		case 'U':return k!=3;
		case 'D':return k!=1;
		case '*':return false;
	}
}
int cor(int k){
	return k<=1?k+2:k-2;
}
bool check(int i,int j,int k,int z){
	int x=i+dx[k],y=j+dy[k];
	if(x<1||x>n||y<1||y>m||vis[z][x][y])return false;
	return go(i,j,k,z)&&go(x,y,cor(k),z);
}
void bfs(int x,int y){
	queue<int>qx,qy,q;
	qx.push(x);
	qy.push(y);
	q.push(0);
	vis[0][x][y]=1;
	while(!q.empty()){
		x=qx.front();  y=qy.front();
		int z=q.front();
		qx.pop();
		qy.pop();
		q.pop();
		 for(int i=0;i<=3;i++)
		if(check(x,y,i,z)){
			int xx=x+dx[i],yy=y+dy[i];
			qx.push(xx);
			qy.push(yy);
			q.push(z);
			d[z][xx][yy]=d[z][x][y]+1;
			vis[z][xx][yy]=1;
		}
		if(!vis[(z+1)%4][x][y]){
			d[(z+1)%4][x][y]=d[z][x][y]+1;
			vis[(z+1)%4][x][y]=1;
			qx.push(x);
			qy.push(y);
			q.push((z+1)%4);
		}
	}
}
char change(int i,int j,int k){
	switch(s[k-1][i][j]){
		case '+':return '+';
		case '-':return '|';
		case '|':return '-';
		case '^':return '>';
		case '>':return 'v';
		case 'v':return '<';
		case '<':return '^';
		case 'L':return 'U';
		case 'U':return 'R';
		case 'R':return 'D';
		case 'D':return 'L';
		case '*':return '*';
	}
}
int main(){
	scanf("%d%d",&n,&m);
	 for(int i=1;i<=n;i++)
	   scanf("%s",s[0][i]+1);
	   
	 for(int k=1;k<=3;k++)
	    for(int i=1;i<=n;i++)
	      for(int j=1;j<=m;j++)
				s[k][i][j]=change(i,j,k);
						int x,y; scanf("%d%d",&x,&y);
					bfs(x,y);
			int ans=inf;
			scanf("%d%d",&x,&y);
			 for(int i=0;i<=3;i++)
				if(vis[i][x][y])
			ans=min(ans,d[i][x][y]);
			if(ans==inf)ans=-1;
			printf("%d\n",ans);
			return 0;
}