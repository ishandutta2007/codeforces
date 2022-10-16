#include <bits/stdc++.h>
#define ll long long
#define PII pair<int, int>
#define PIL pair<int, ll>
#define PLI pair<ll, int>
#define PLL pair<ll, ll>
#define PDD pair<double, double>
#define STR string
#define MP make_pair
#define Fst first
#define Snd second
using namespace std;
int tac,n;
bool ok[30][400][2]; // 0 outside 1 clockwise
char str[3];
PII par[30][400];
int siz[30][400];
PII pare(int x,int y)
{
	return par[x][y]==MP(x,y) ? par[x][y] : par[x][y]=pare(par[x][y].Fst,par[x][y].Snd);
}
inline void join(int x,int y,int xi,int yi)
{
	PII p1=pare(x,y),p2=pare(xi,yi);
	if (p1==p2) return;
	x=p1.Fst,y=p1.Snd,xi=p2.Fst,yi=p2.Snd;
	if (siz[x][y]<siz[xi][yi]) swap(x,xi),swap(y,yi);
	par[xi][yi]=MP(x,y),siz[x][y]+=siz[xi][yi];
}
int main()
{
	scanf("%d",&tac);
	while (tac--)
	{
		scanf("%d",&n);
		for (int i=0;i<28;i++)
			for (int j=0;j<360;j++) ok[i][j][0]=ok[i][j][1]=1;
		for (int i=0;i<n;i++)
		{
			scanf("%s",str);
			if (str[0]=='C')
			{
				int r,x,y;
				scanf("%d%d%d",&r,&x,&y);
				for (int j=x;j!=y;j=(j+1)%360) ok[r][j][0]=0;
			}
			else
			{
				int r1,r2,x;
				scanf("%d%d%d",&r1,&r2,&x);
				for (int j=r1+1;j<=r2;j++) ok[j][(x-1+360)%360][1]=0;
			}
		}
		for (int i=0;i<28;i++)
			for (int j=0;j<360;j++) par[i][j]=MP(i,j),siz[i][j]=1;
		for (int i=0;i<25;i++)
		{
			for (int j=0;j<360;j++)
			{
				if (ok[i][j][0]) join(i,j,i+1,j);
				if (ok[i][j][1]) join(i,j,i,(j+1)%360);
			}
		}
		//cout <<pare(0,0).Fst<<" "<<pare(0,0).Snd<<" ##\n";
		//cout <<pare(22,0).Fst<<" "<<pare(22,0).Snd<<" ##\n";
		puts(pare(0,0)==pare(22,0) ? "YES" : "NO");
	}
	return 0;
}