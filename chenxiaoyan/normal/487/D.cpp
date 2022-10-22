#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
#define X first
#define Y second
const int N=100000,M=10,QU=100000,BLKN=2000;
int n,m;
char a[N+1][M+3];
int qu;
struct query{char tp,z;int x,y;}qry[QU+1];
struct sqrt_bf{
	int blkn;
	int in[N+1];
	struct block{int l,r;vector<int> tox[M+1],toy[M+1];}blk[BLKN+1];
	#define l(p) blk[p].l
	#define r(p) blk[p].r
	#define tox(p) blk[p].tox
	#define toy(p) blk[p].toy
	void dfs(int b,int x,int y){
		if(tox(b)[y][x-l(b)]||toy(b)[y][x-l(b)])return;
		if(a[x][y]=='^')dfs(b,x-1,y),tox(b)[y][x-l(b)]=tox(b)[y][x-1-l(b)],toy(b)[y][x-l(b)]=toy(b)[y][x-1-l(b)];
		else if(a[x][y]=='<')dfs(b,x,y-1),tox(b)[y][x-l(b)]=tox(b)[y-1][x-l(b)],toy(b)[y][x-l(b)]=toy(b)[y-1][x-l(b)];
		else if(a[x][y]=='>')dfs(b,x,y+1),tox(b)[y][x-l(b)]=tox(b)[y+1][x-l(b)],toy(b)[y][x-l(b)]=toy(b)[y+1][x-l(b)];
	}
	void initblk(int b){
		for(int i=0;i<=r(b)-l(b);i++)for(int j=1;j<=m;j++)tox(b)[j][i]=toy(b)[j][i]=0;
		for(int i=l(b);i<=r(b);i++)for(int j=1;j<=m;j++)
			if(i==l(b)&&a[i][j]=='^')tox(b)[j][i-l(b)]=l(b)-1,toy(b)[j][i-l(b)]=j;
			else if(j==1&&a[i][j]=='<')tox(b)[j][i-l(b)]=i,toy(b)[j][i-l(b)]=0;
			else if(j==m&&a[i][j]=='>')tox(b)[j][i-l(b)]=i,toy(b)[j][i-l(b)]=m+1;
			else if(j<m&&a[i][j]=='>'&&a[i][j+1]=='<')tox(b)[j][i-l(b)]=toy(b)[j][i-l(b)]=tox(b)[j+1][i-l(b)]=toy(b)[j+1][i-l(b)]=-1;
		for(int i=l(b);i<=r(b);i++)for(int j=1;j<=m;j++)dfs(b,i,j);
	}
	void init(int _blkn){
		blkn=_blkn;
		r(0)=0;
		for(int i=1;i<=blkn;i++){
			l(i)=r(i-1)+1;r(i)=l(i)+n/blkn-1;
			for(int j=l(i);j<=r(i);j++)in[j]=i;
			for(int j=1;j<=m;j++)tox(i)[j].resize(n/blkn),toy(i)[j].resize(n/blkn);
			initblk(i);
		}
		if(r(blkn)<n){
			blkn++;
			l(blkn)=r(blkn-1)+1;r(blkn)=n;
			for(int i=l(blkn);i<=n;i++)in[i]=blkn;
			for(int i=1;i<=m;i++)tox(blkn)[i].resize(n-l(blkn)+1),toy(blkn)[i].resize(n-l(blkn)+1);
			initblk(blkn);
		}
	}
	void chg(int x,int y,char v){
		int b=in[x];
		a[x][y]=v;
		initblk(b);
	}
	pair<int,int> ask(int x,int y){
		int b=in[x];
		pair<int,int> res(x,y);
		for(int i=b;i;i--){
			res=mp(tox(i)[res.Y][res.X-l(i)],toy(i)[res.Y][res.X-l(i)]);
			if(res.Y<1||res.Y>m)break;
		}
		return res;
	}
}sbf;
int main(){
	scanf("%d%d%d",&n,&m,&qu);
	for(int i=1;i<=n;i++)scanf("%s",a[i]+1);
	int tpc=0;
	for(int i=1;i<=qu;i++){
		scanf(" %c%d%d",&qry[i].tp,&qry[i].x,&qry[i].y);
		if(qry[i].tp=='C')scanf(" %c",&qry[i].z),tpc++;
	}
	tpc=min(qu-1,max(1,tpc));
	sbf.init(min(n,max(1,(int)sqrt(n*m))));
	for(int i=1;i<=qu;i++)
		if(qry[i].tp=='A'){
			pair<int,int> ans=sbf.ask(qry[i].x,qry[i].y);
			printf("%d %d\n",ans.X,ans.Y);
		}
		else sbf.chg(qry[i].x,qry[i].y,qry[i].z);
	return 0;
}
/*1
2 2 3
>>
^^
A 2 1
C 1 2 <
A 2 1
*/
/*2
4 5 7
><<^<
^<^^>
>>>^>
>^>>^
A 3 1
A 2 2
C 1 4 <
A 3 1
C 1 2 ^
A 3 1
A 2 2
*/