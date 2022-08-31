#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<iomanip>
#include<set>
#define sqr(x) (x)*(x)
#define llx(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
using namespace std;
int n,m,i,j,vis[1005][1005],cnt,cnt2;
char mp[1005][1005];
set<int> sx2,sy2;
vector<int> sx,sy;
vector<vector<int> > vx,vy;
vector<vector<int> > gt(const vector<int> &s1,const set<int> &s2)
{
	vector<vector<int> > ans;
	if (s1.size()==4)
	{
		ans.push_back(s1);
		return ans;
	}
	if (s1.size()==3)
	{
		llx(s2,it)
		{
			vector<int> t=s1;
			t.push_back(*it);
			ans.push_back(t);
		}
		return ans;
	}
	if (s1.size()==2)
	{
		llx(s2,it)
		{
			for (set<int>::iterator it2=it;it2!=s2.end();it2++)
			{
				if (it==it2) continue;
				vector<int> t=s1;
				t.push_back(*it);
				t.push_back(*it2);
				ans.push_back(t);
			}
		}
		return ans;
	}
}
int ins(int x,int xx,int y,int yy)
{
	int i,j,ans=0;
	for (i=x;i<=xx;i++)
	{
		if (mp[i][y]=='.') return -1<<25;
		if (vis[i][y]==0) ans++;
		vis[i][y]=1;
		if (mp[i][yy]=='.') return -1<<25;
		if (vis[i][yy]==0) ans++;
		vis[i][yy]=1;
	}
	for (i=y;i<=yy;i++)
	{
		if (mp[x][i]=='.') return -1<<25;
		if (vis[x][i]==0) ans++;
		vis[x][i]=1;
		if (mp[xx][i]=='.') return -1<<25;
		if (vis[xx][i]==0) ans++;
		vis[xx][i]=1;
	}
	return ans;
}
void era(int x,int xx,int y,int yy)
{
	int i,j,ans=0;
	for (i=x;i<=xx;i++)
	{
		vis[i][y]=0;
		vis[i][yy]=0;
	}
	for (i=y;i<=yy;i++)
	{
		vis[x][i]=0;
		vis[xx][i]=0;
	}
}
bool check2(const vector<int> &s1,const vector<int> &s2)
{
	if (s1[1]-s1[0]<2) return 0;
	if (s1[3]-s1[2]<2) return 0;
	if (s2[1]-s2[0]<2) return 0;
	if (s2[3]-s2[2]<2) return 0;
	int x1=s1[0],x2=s1[1],x3=s1[2],x4=s1[3];
	int y1=s2[0],y2=s2[1],y3=s2[2],y4=s2[3];
	int t=ins(x1,x2,y1,y2);
	era(x1,x2,y1,y2);
	if (t!=(x2-x1+y2-y1)*2) return 0;
	t=ins(x3,x4,y3,y4);
	era(x3,x4,y3,y4);
	if (t!=(x4-x3+y4-y3)*2) return 0;
	t=ins(x1,x2,y1,y2)+ins(x3,x4,y3,y4);
	era(x1,x2,y1,y2);
	era(x3,x4,y3,y4);
	if (t!=cnt) return 0;
	return 1;
}
void check(vector<int> s1,vector<int> s2)
{
	sort(s1.begin(),s1.end());
	sort(s2.begin(),s2.end());
	do
	{
		do
		{
			if (check2(s1,s2))
			{
				cout<<"YES"<<endl<<s1[0]<<' '<<s2[0]<<' '<<s1[1]<<' '<<s2[1]<<endl<<s1[2]<<' '<<s2[2]<<' '<<s1[3]<<' '<<s2[3]<<endl;
				exit(0);
			}
		}
		while (next_permutation(s2.begin(),s2.end()));
	}
	while (next_permutation(s1.begin(),s1.end()));
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin>>n>>m;
	for (i=1;i<=n;i++)
	{
		for (j=1;j<=m;j++)
		{
			cin>>mp[i][j];
			cnt+=(mp[i][j]=='#');
		}
	}
	for (i=1;i<=n;i++)
	{
		cnt2=0;
		for (j=1;j<=m;j++)
		{
			cnt2+=(mp[i][j]=='#');
		}
		if (cnt2>=5)
		{
			sx.push_back(i);
			continue;
		}
		for (j=1;j<=m;j++)
		{
			if (mp[i][j]=='#')
			{
				if (i==1||mp[i-1][j]=='.')
				{
					sx.push_back(i);
					break;
				}
				if (i==n||mp[i+1][j]=='.')
				{
					sx.push_back(i);
					break;
				}
			}
		}
	}
	for (j=1;j<=m;j++)
	{
		cnt2=0;
		for (i=1;i<=n;i++)
		{
			cnt2+=(mp[i][j]=='#');
		}
		if (cnt2>=5)
		{
			sy.push_back(j);
			continue;
		}
		for (i=1;i<=n;i++)
		{
			if (mp[i][j]=='#')
			{
				if (j==1||mp[i][j-1]=='.')
				{
					sy.push_back(j);
					break;
				}
				if (j==m||mp[i][j+1]=='.')
				{
					sy.push_back(j);
					break;
				}
			}
		}
	}
	/*llx(sx,it) cerr<<*it<<' ';
	cerr<<endl;
	llx(sy,it) cerr<<*it<<' ';
	cerr<<endl;*/
	if (sx.size()<2||sx.size()>4||sy.size()<2||sy.size()>4)
	{
		cout<<"NO";
		return 0;
	}
	llx(sx,it)
	{
		sx2.insert(*it);
		if (*it>1) sx2.insert(*it-1);
		if (*it<n) sx2.insert(*it+1);
	}
	llx(sy,it)
	{
		sy2.insert(*it);
		if (*it>1) sy2.insert(*it-1);
		if (*it<n) sy2.insert(*it+1);
	}
	vx=gt(sx,sx2);
	vy=gt(sy,sy2);
	/*llx(vx,it)
	{
		llx(*it,it2) cerr<<*it2<<' ';
		cerr<<endl;
	}
	cerr<<endl;
	llx(vy,it)
	{
		llx(*it,it2) cerr<<*it2<<' ';
		cerr<<endl;
	}
	cerr<<endl;*/
	llx(vx,it)
	{
		llx(vy,it2)
		{
			check(*it,*it2);
		}
	}
	cout<<"NO";
	return 0;
}