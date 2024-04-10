#include <bits/stdc++.h>
#include <algorithm>
#define rep(i,n) for(int i=0;i<(n);i++)
#define per(i,n) for(int i=(n)-1;i>=0;i--)
#define prt(n) cout<<(n)<<endl
#define elif else if
#define str string
#define pb push_back
#define mp make_pair
#define foreach(i,itr) for(__typeof(itr.begin()) i=itr.begin();i!=itr.end();i++ )
typedef long long ll;
using namespace std;
const ll mod1=998244353;
const ll mod2=1000000007;
//ios_base::sync_with_stdio(false);cin
const int N=6;
str s1[N],s2[N],sc[N];
map<str,int> ind;
str name[N];
int a[N][N];
bool better(int x,int y)
{
	int sx=0,dx=0,wx=0;
	int sy=0,dy=0,wy=0;
	rep(i,4)
	{
		if(x==i) continue;
		if(a[x][i]>a[i][x]) sx+=3; elif(a[x][i]==a[i][x]) sx++;
		dx+=a[x][i]-a[i][x];
		wx+=a[x][i];
	}
	rep(i,4)
	{
		if(y==i) continue;
		if(a[y][i]>a[i][y]) sy+=3; elif(a[y][i]==a[i][y]) sy++;
		dy+=a[y][i]-a[i][y];
		wy+=a[y][i];
	}
	if(sx!=sy) return sx>sy;
	if(dx!=dy) return dx>dy;
	if(wx!=wy) return wx>wy;
	return x<y;
}
bool valid(int j,int k)
{
	int I=ind["BERLAND"];
	int A=0;
	rep(i,4) if(i!=I&&a[I][i]==-1) A=i;
	a[I][A]=j,a[A][I]=k;
	int ord=1;
	rep(i,4) if(i!=I&&better(i,I)) ord++;
	a[I][A]=a[A][I]=-1;
	return ord<=2; 
}
const int M=30;
int main()
{
	rep(i,5) cin>>s1[i]>>s2[i]>>sc[i];
	rep(i,5) ind[s1[i]]=ind[s2[i]]=0;
	int lingshi_de_bianliang=0;
	foreach(i,ind)
	{
		(i->second)=lingshi_de_bianliang;
		name[lingshi_de_bianliang++]=(i->first);
	}
	rep(i,4) rep(j,4) a[i][j]=-1;
	rep(i,5)
	{
		int c=ind[s1[i]],d=ind[s2[i]];
		rep(j,sc[i].size()) if(sc[i][j]==':') sc[i][j]=' ';
		istringstream csin(sc[i]);
		csin>>a[c][d]>>a[d][c];
	}
	for(int d=1;d<=M;d++) rep(y,M)
	{
		int x=y+d;
		if(valid(x,y))
		{
			cout<<x<<":"<<y<<endl;
			return 0;
		}
	}
	cout<<"IMPOSSIBLE"<<endl;
	return 0;
}