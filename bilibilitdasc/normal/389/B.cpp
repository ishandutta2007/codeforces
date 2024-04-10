#include <bits/stdc++.h>
#include <algorithm>
#define rep(i,n) for(int i=0;i<(n);i++)
#define per(i,n) for(int i=(n)-1;i>=0;i--)
#define prt(n) cout<<(n)<<endl
#define elif else if
#define str string
#define pb push_back
#define mp make_pair
typedef long long ll;
using namespace std;
const ll mod1=998244353;
const ll mod2=1000000007;
//ios_base::sync_with_stdio(false);cin
char a[105][105];
int n;
bool isv(int x,int y)
{
	return 0<=x&&0<=y&&x<n&&y<n;
}
const int dx[4]={0,-1,0,1},dy[4]={1,0,-1,0};
bool isg(int x,int y)
{
	return a[x][y]=='#';
}
int ai,aj;
int getbrd(int x,int y)
{
	int ans=0;
	for(int i=0;i<4;i++)
	{
		int ax=x+dx[i],ay=y+dy[i];
		if(isv(ax,ay)&&isg(ax,ay))
		{
			ai=ax,aj=ay;
			ans++;
		}
	}
	return ans;
}
int main()
{
	cin>>n;
	int cnt=0;
	for(int i=0;i<n;i++) for(int j=0;j<n;j++) cin>>a[i][j];
	for(int i=0;i<n;i++) for(int j=0;j<n;j++) if(isg(i,j)) cnt++;
	if(cnt%5!=0)
	{
		cout<<"NO"<<endl;
		return 0;
	}
	while(cnt!=0)
	{
		bool fd=0;
		for(int i=0;i<n;i++) for(int j=0;j<n;j++)
		{
			if(isg(i,j)&&getbrd(i,j)==1)
			{
				for(int k=0;k<4;k++)
				{
					if(!isv(ai+dx[k],aj+dy[k])||!isg(ai+dx[k],aj+dy[k]))
					{
						cout<<"NO"<<endl;
						return 0;
					}
					else
					{
						a[ai+dx[k]][aj+dy[k]]='.';
					}
				}
				a[ai][aj]='.';
				fd=1;
			}
		}
		if(!fd)
		{
			cout<<"NO"<<endl;
			return 0;
		}
		cnt=0;
		for(int i=0;i<n;i++) for(int j=0;j<n;j++) if(isg(i,j)) cnt++;
	}
	cout<<"YES"<<endl;
	return 0;
}
/*
5
.###.
#####
.###.
..#..
..#..

4
####
####
####
####

6
.#....
####..
.####.
.#.##.
######
.#..#.

6
.##.#.
######
.####.
.####.
######
.#..#.

3
...
...
...
*/