#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
#define X first
#define Y second
#define pb push_back
const int N=1000,M=1000,CNTR=300;
int n,m,t;
char a[N+5][M+5];
vector<pair<int,int> > rat;
bitset<CNTR> kll[N+1][M+1],all;
vector<pair<int,int> > klled[CNTR];
const int dx[]={0,0,-1,1},dy[]={-1,1,0,0};
struct node{int x,y,d;};
void bfs(int k){
	int x=rat[k].X,y=rat[k].Y;
	queue<node> q;
	q.push((node){x,y,0});
	kll[x][y].set(k);klled[k].pb(mp(x,y));
	while(q.size()){
		int xx=q.front().x,yy=q.front().y,d=q.front().d;
		q.pop();
		for(int i=0;i<4;i++){
			int xxx=xx+dx[i],yyy=yy+dy[i];
			if(a[xxx][yyy]!='X'&&!kll[xxx][yyy][k]){
				kll[xxx][yyy].set(k);klled[k].pb(mp(xxx,yyy));
				if(d<t-1)q.push((node){xxx,yyy,d+1});
			}
		}
	}
}
int main(){
	freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
	scanf("%d%d%d",&n,&m,&t);
	for(int i=1;i<=n;i++)scanf("%s",a[i]+1);
	int cnts=0,cntr=0;
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)cnts+=a[i][j]!='X',cntr+=a[i][j]=='R';
	if(cntr>300||cnts<2)return puts("-1"),0;
	if(cntr==0){
		int rst=2;
		for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)if(a[i][j]!='X')
			if(rst==2)rst=1,printf("%d %d ",i,j);
			else return printf("%d %d",i,j),0;
	}
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)if(a[i][j]=='R')rat.pb(mp(i,j));
	if(cntr==1){
		printf("%d %d ",rat[0].X,rat[0].Y);
		for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)if(a[i][j]=='.')
			return printf("%d %d",i,j),0;
	}
	for(int i=0;i<cntr;i++)bfs(i);
//	for(int i=0;i<cntr;i++){
//		printf("rat#%d:",i);
//		for(int j=0;j<klled[i].size();j++)printf("(%d,%d)",klled[i][j].X,klled[i][j].Y);
//		puts("");
//	}
	for(int i=0;i<cntr;i++)all.set(i);
	for(int i=0;i<klled[0].size();i++){
		int a1=klled[0][i].X,b1=klled[0][i].Y;
		if(kll[a1][b1]==all)
			for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)if((i!=a1||j!=b1)&&a[i][j]!='X')
				return printf("%d %d %d %d",a1,b1,i,j),0;
		int f;
		for(int j=0;j<cntr;j++)if(!kll[a1][b1][j]){f=j;break;}
		for(int j=0;j<klled[f].size();j++){
			int a2=klled[f][j].X,b2=klled[f][j].Y;
			if((kll[a1][b1]|kll[a2][b2])==all)return printf("%d %d %d %d",a1,b1,a2,b2),0;
		}
	}
	puts("-1");
	return 0;
}
/*1
4 4 1
XXXX
XR.X
X.RX
XXXX
*/
/*2
9 14 5
XXXXXXXXXXXXXX
X....R...R...X
X..R.........X
X....RXR..R..X
X..R...X.....X
XR.R...X.....X
X....XXR.....X
X....R..R.R..X
XXXXXXXXXXXXXX
*/
/*3
7 7 1
XXXXXXX
X.R.R.X
X.....X
X..X..X
X..R..X
X....RX
XXXXXXX
*/
/*4
7 7 5
XXXXXXX
X.....X
X...R.X
X.....X
XR.R..X
X.....X
XXXXXXX
*/