#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
#define per(i,n) for(int i=(n)-1;i>=0;i--)
#define rep1(i,n) for(int i=1;i<=(n);i++)
#define per1(i,n) for(int i=(n);i>=1;i--)
#define repk(i,a,b) for(int i=(a);i<=(b);i++)
#define perk(i,a,b) for(int i=(a);i>=(b);i--)
#define rep0(i,a,b) for(int i=(a);i<(b);i++)
#define pb push_back
#define mp make_pair
#define g(x) cout<<#x<<'='<<x<<endl
#define nextp next_permutation
#define pq priority_queue
typedef long long ll;
using namespace std;
const ll mod1=998244353;
const ll mod2=1000000007;
//ios_base::sync_with_stdio(false);cin
char s1[20]="23456789TJQKA";
char s2[10]="CDHS";
string s[52];
map<string,int> num;
string ss="WD";
int c[18][18];
set<int> ssss;
bool joker1,joker2;
int n,m;
int j1x,j1y,j2x,j2y;
bool vis[18][18];
set<int> sss;
bool valid1(int x1,int y1)
{
	sss.clear();
	int x3=x1+2,y3=y1+2;
	repk(i,x1,x3) repk(j,y1,y3)
	{
		sss.insert(c[i][j]>>2);
	}
	return sss.size()==9;
}
bool valid2(int x1,int y1)
{
	int x3=x1+2,y3=y1+2;
	repk(i,x1,x3) repk(j,y1,y3)
	{
		if((c[i][j]&3)!=(c[x1][y1]&3))
		return 0;
	}
	return 1;
}
bool valid(int x1,int y1,int x2,int y2)
{
	memset(vis,0,sizeof(vis));
	int x3=x1+2,y3=y1+2,x4=x2+2,y4=y2+2;
	if(x3>=n||y3>=m||x4>=n||y4>=m) return 0;
	repk(i,x1,x3) repk(j,y1,y3)
	{
		if(vis[i][j]) return 0;
		vis[i][j]=1;
	}
	repk(i,x2,x4) repk(j,y2,y4)
	{
		if(vis[i][j]) return 0;
		vis[i][j]=1;
	}
	return (valid1(x1,y1)||valid2(x1,y1))&&(valid1(x2,y2)||valid2(x2,y2));
}
pair< pair<int,int>,pair<int,int> > chk()
{
	rep(i,n) rep(j,m) rep(k,n) rep(l,m) if(valid(i,j,k,l)) return mp(mp(i,j),mp(k,l)); return mp(mp(-1,-1),mp(-1,-1));
}
#define num(a,b) (((a)<<2)|(b))
#define fi first
#define se second
int main()
{
	ios_base::sync_with_stdio(false);
	rep(i,13) rep(j,4)
	{
		ss[0]=s1[i];ss[1]=s2[j];s[num(i,j)]=ss;
		num[ss]=num(i,j);
	}
	cin>>n>>m;
	rep(i,n) rep(j,m)
	{
		cin>>ss;
		if(ss!="J1"&&ss!="J2")
		{
			c[i][j]=num[ss];
			ssss.insert(c[i][j]);
		}
		else if(ss=="J1")
		{
			joker1=1;j1x=i;j1y=j;
		}
		else
		{
			joker2=1;j2x=i;j2y=j;
		}
	}
	//rep(i,n) rep(j,m)
	//{
	//	cout<<c[i][j];
	//	if(j+1==m) cout<<endl;
	//	else cout<<' ';
	//}
	if(!joker1)
	{
		if(!joker2)
		{
			pair< pair<int,int>,pair<int,int> > p=chk();
			if(p.fi.fi!=-1)
			{
				cout<<"Solution exists.\nThere are no jokers.\nPut the first square to ("<<p.fi.fi+1<<", "<<p.fi.se+1<<").\nPut the second square to ("<<p.se.fi+1<<", "<<p.se.se+1<<")."<<endl;
				return 0;
			}
		}
		else
		{
			rep(i,52)
			{
				if(!ssss.count(i))
				{
					c[j2x][j2y]=i;
					pair< pair<int,int>,pair<int,int> > p=chk();
					if(p.fi.fi!=-1)
					{
						cout<<"Solution exists.\nReplace J2 with "<<s[i]<<".\nPut the first square to ("<<p.fi.fi+1<<", "<<p.fi.se+1<<").\nPut the second square to ("<<p.se.fi+1<<", "<<p.se.se+1<<")."<<endl;
						return 0;
					}
				}
			}
		}
	}
	else
	{
		if(!joker2)
		{
			rep(i,52)
			{
				if(!ssss.count(i))
				{
					c[j1x][j1y]=i;
					pair< pair<int,int>,pair<int,int> > p=chk();
					if(p.fi.fi!=-1)
					{
						cout<<"Solution exists.\nReplace J1 with "<<s[i]<<".\nPut the first square to ("<<p.fi.fi+1<<", "<<p.fi.se+1<<").\nPut the second square to ("<<p.se.fi+1<<", "<<p.se.se+1<<")."<<endl;
						return 0;
					}
				}
			}
		}
		else
		{
			rep(i,52) rep(j,52)
			{
				if(!ssss.count(i)&&!ssss.count(j)&&i!=j)
				{
					c[j2x][j2y]=i;
					c[j1x][j1y]=j;
					pair< pair<int,int>,pair<int,int> > p=chk();
					if(p.fi.fi!=-1)
					{
						cout<<"Solution exists.\nReplace J1 with "<<s[j]<<" and J2 with "<<s[i]<<".\nPut the first square to ("<<p.fi.fi+1<<", "<<p.fi.se+1<<").\nPut the second square to ("<<p.se.fi+1<<", "<<p.se.se+1<<")."<<endl;
						return 0;
					}
				}
			}
		}
	}
	cout<<"No solution."<<endl;
	return 0;
}