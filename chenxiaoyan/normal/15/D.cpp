#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define ri register int
void read(int &x){
	x=0;char c=getchar();
	while(!isdigit(c))c=getchar();
	while(isdigit(c))x=(x<<3)+(x<<1)+(c^48),c=getchar();
}
const int N=1000,M=1000;
int n,m,n0,m0;
int a[N+1][M+1];
int Sum[N+1][M+1];
int q[N],head,tail;
int mn1[N+1][M+1],mn2[N+1][M+1];
vector<pair<int,int> > ord;
int cst[N+1][M+1];
int calc_cst(int x,int y){
	return Sum[x+n0-1][y+m0-1]-Sum[x-1][y+m0-1]-Sum[x+n0-1][y-1]+Sum[x-1][y-1]-n0*m0*mn2[x][y];
}
bool cmp(pair<int,int> x,pair<int,int> y){
	return cst[x.X][x.Y]!=cst[y.X][y.Y]?cst[x.X][x.Y]<cst[y.X][y.Y]:x.X!=y.X?x.X<y.X:x.Y<y.Y;
}
bool vis[N+1][M+1];
signed main(){
//	freopen("C:\\Users\\chenx\\OneDrive\\\\data.in","r",stdin);
	read(n);read(m);read(n0);read(m0);
	for(ri i=1;i<=n;i++)for(ri j=1;j<=m;j++){
		read(a[i][j]);
		Sum[i][j]=Sum[i-1][j]+Sum[i][j-1]-Sum[i-1][j-1]+a[i][j];
	}
	for(ri i=1;i<=n;i++){
		head=tail=0;
		for(ri j=1;j<m0;j++){
			while(head<tail&&a[i][q[tail-1]]>=a[i][j])tail--;
			q[tail++]=j;
		}
		for(ri j=1;j+m0-1<=m;j++){
			while(head<tail&&q[head]<j)head++;
			while(head<tail&&a[i][q[tail-1]]>=a[i][j+m0-1])tail--;
			q[tail++]=j+m0-1;
			mn1[i][j]=a[i][q[head]];
		}
	}
//	for(ri i=1;i<=n;i++){for(ri j=1;j+m0-1<=m;j++)cout<<mn1[i][j]<<" ";puts("");}puts("");
	for(ri j=1;j+m0-1<=m;j++){
		head=tail=0;
		for(ri i=1;i<n0;i++){
			while(head<tail&&mn1[q[tail-1]][j]>=mn1[i][j])tail--;
			q[tail++]=i;
		}
		for(ri i=1;i+n0-1<=n;i++){
			while(head<tail&&q[head]<i)head++;
			while(head<tail&&mn1[q[tail-1]][j]>=mn1[i+n0-1][j])tail--;
			q[tail++]=i+n0-1;
			mn2[i][j]=mn1[q[head]][j];
		}
	}
//	for(ri i=1;i+n0-1<=n;i++){for(ri j=1;j+m0-1<=m;j++)cout<<mn2[i][j]<<" ";puts("");} 
	for(ri i=1;i+n0-1<=n;i++)for(ri j=1;j+m0-1<=m;j++)cst[i][j]=calc_cst(i,j),ord.pb(mp(i,j));
	sort(ord.begin(),ord.end(),cmp);
	vector<pair<int,int> > ans;
	for(ri i=0;i<ord.size();i++){
		int x=ord[i].X,y=ord[i].Y;
		if(vis[x][y]||vis[x][y+m0-1]||vis[x+n0-1][y]||vis[x+n0-1][y+m0-1])continue;
		ans.pb(ord[i]);
		for(ri j=x;j<=x+n0-1;j++)for(ri k=y;k<=y+m0-1;k++)vis[j][k]=true;
	}
	cout<<ans.size()<<"\n";
	for(ri i=0;i<ans.size();i++)printf("%lld %lld %lld\n",ans[i].X,ans[i].Y,cst[ans[i].X][ans[i].Y]);
	return 0;
}
/*1
2 2 1 2
1 2
3 5
*/
/*2
4 4 2 2
1 5 3 4
2 7 6 1
1 1 2 2
2 2 1 2
*/