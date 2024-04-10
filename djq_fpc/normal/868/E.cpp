#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<ctime>
#include<set>
#include<queue>
#define sqr(x) ((x)*(x))
#define fz1(i,n) for ((i)=1;(i)<=(n);++(i))
#define fd1(i,n) for ((i)=(n);(i)>=1;--(i))
#define fz0g(i,n) for ((i)=0;(i)<=(n);++(i))
#define fd0g(i,n) for ((i)=(n);(i)>=0;--(i))
#define fz0k(i,n) for ((i)=0;(i)<(n);++(i))
#define fd0k(i,n) for ((i)=(long long)((n)-1);(i)>=0;--(i))
#define fz(i,x,y) for ((i)=(x);(i)<=(y);++(i))
#define fd(i,y,x) for ((i)=(y);(i)>=(x);--(i))
#define ff(c,itr) for (__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
#define rdst(st,len){static char ss[len];scanf(" %s",ss);(st)=ss;}
using namespace std;
int n,m,i,j,k,dp[55][55],dis[55][55],fa[55],s,mi,cnt[55],bel[55];
vector<int> bi[55];
vector<int> l;
void dfs(int x,int p)
{
	fa[x]=p;
	ff(bi[x],it)if(*it!=p){
		dfs(*it,x);
	}
}
int solve(int x,int y);
bool check(int x,int y,int mid)
{
	int i,s=0;
	fz0k(i,l.size()){
		int t=1;
		while(t<=y&&solve(l[i],y-t)+dis[l[i]][x]>=mid){
			t++;s++;
		}
		if(s>=y)return 1;
	}
	return s>=y;
}
int solve(int x,int y)
{
	if(!y) return 0;
	if(dp[x][y]!=-1)return dp[x][y];
	int l=1,r=200000,mid,ans=0;
	while(l<r){
		mid=(l+r)/2;
		if(check(x,y,mid)){
			l=mid+1;
			ans=mid;
		}
		else r=mid;
	}
	return dp[x][y]=ans;
}
bool check2(int x,int y,int mid,int fr)
{
	int i,s=0;
	fz0k(i,l.size())if(bel[l[i]]==fr){
		int t=1;
		while(t<=y&&solve(l[i],m-t)+dis[l[i]][x]>=mid){
			t++;s++;
		}
		if(s>=y)return 1;
	}
	return s>=y;
}
int main()
{
	scanf("%d",&n);
	memset(dis,0x18,sizeof(dis));
	fz1(i,n)dis[i][i]=0;
	fz1(i,n-1){
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		bi[x].push_back(y);
		bi[y].push_back(x);
		dis[x][y]=dis[y][x]=z;
	}
	fz1(i,n)if(bi[i].size()==1)l.push_back(i);
	fz1(k,n)fz1(i,n)fz1(j,n){
		dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	}memset(dp,-1,sizeof(dp));
	scanf("%d",&s);dfs(s,0);
	ff(l,it)if(*it!=s){
		int x=*it;while(fa[x]!=s)x=fa[x];
		bel[*it]=x;
	}
	scanf("%d",&m);fz1(i,m){
		int x;scanf("%d",&x);
		while(fa[x]!=s) x=fa[x];
		cnt[x]++;
	}
	mi=0x18181818;
	ff(bi[s],it){
		int l=1,r=200000,mid,ans=0;
		while(l<r){
			mid=(l+r)/2;
			if(check2(s,cnt[*it],mid,*it)){
				l=mid+1;
				ans=mid;
			}
			else r=mid;
		}
		mi=min(ans,mi);
	}
	printf("%d\n",mi);
	return 0;
}