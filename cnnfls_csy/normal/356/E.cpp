#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<iomanip>
#define sqr(x) (x)*(x)
using namespace std;
long long n,m,i,j,k,ans,cnt[100005][26],cst[100005],ans2,add[100005][26];
bool can[100005][35];
string st;
unsigned long long h1[100005][2],e[2]={1000000007,1000000009},po[100005][2];
bool gethash(long long x,long long y,long long l)
{
	if (l<1) return 1;
	if (x>y) swap(x,y);
    if (x+l>st.length()||y+l>st.length()) return 0;
    return ((h1[x+l-1][0]-h1[x-1][0])*po[y-x][0]==h1[y+l-1][0]-h1[y-1][0])&&((h1[x+l-1][1]-h1[x-1][1])*po[y-x][1]==h1[y+l-1][1]-h1[y-1][1]);
}
long long lcp(long long x,long long y)
{
	long long l=0,r=st.length(),ans=0,mid;
	while (l<r)
	{
		mid=(l+r)/2;
		if (gethash(x,y,mid))
		{
			ans=mid;
			l=mid+1;
		}
		else r=mid;
	}
	return ans;
}
void get(long long x,long long k,long long j)
{
	long long i;
	if (k==1)
	{
		for (i=0;i<26;i++) add[x][i]=1;
		return;
	}
	if (x+j>st.length()) return;
	long long y=x+j/2+1;
	if (can[x][k-1]&&can[y][k-1]&&gethash(x,y,j/2))
	{
		for (i=0;i<26;i++)
		{
			if (cnt[y-2][i]-cnt[x-1][i]==0) add[y-1][i]+=sqr(j);
		}
	}
    long long len=lcp(x,y);
    if (len>=j/2) return;
    long long xx=x+len,yy=y+len;
    if (lcp(xx+1,yy+1)+len+1<j/2) return;
    if (can[x][k-1]&&cnt[y-2][st[y-1]-'a']-cnt[x-1][st[y-1]-'a']==0) add[yy][st[xx]-'a']+=sqr(j);
    if (can[y][k-1]&&cnt[y+j/2-1][st[y-1]-'a']-cnt[y-1][st[y-1]-'a']==0) add[xx][st[yy]-'a']+=sqr(j);
}
int main()
{
	cin>>st;
	st=" "+st;
	po[0][0]=po[0][1]=1;
	for (i=1;i<st.length();i++)
	{
		for (j=0;j<2;j++)
		{
			po[i][j]=po[i-1][j]*e[j];
			h1[i][j]=h1[i-1][j]+st[i]*po[i][j];
		}
	}
	for (i=1;i<st.length();i++)
	{
		for (j=0;j<26;j++)
		{
			cnt[i][j]=cnt[i-1][j]+(st[i]=='a'+j);
		}
	}
	for (j=k=1;j<st.length();j=j+j+1,k++)
	{
		for (i=1;i+j<=st.length();i++)
		{
			if (k==1)
			{
				can[i][k]=1;
			}
			else
			{
				long long x=i,y=i+j/2+1;
				if (!can[x][k-1]) continue;
				if (!can[y][k-1]) continue;
				if (!gethash(x,y,j/2)) continue;
				if (cnt[i+j-1][st[y-1]-'a']-cnt[i-1][st[y-1]-'a']>1) continue;
				can[i][k]=1;
			}
			if (can[i][k])
			{
				ans+=sqr(j);
				cst[i]+=sqr(j);
				cst[i+j]-=sqr(j);
			}
		}
	}
	for (i=1;i<st.length();i++) cst[i]+=cst[i-1];
	/*for (i=1;i<st.length();i++) cerr<<cst[i]<<' ';
	cerr<<endl;*/
	ans2=ans;
	for (j=k=1;j<st.length();j=j+j+1,k++)
	{
		for (i=1;i+j<=st.length();i++)
		{
			get(i,k,j);
		}
	}
	for (i=1;i<st.length();i++)
	{
		for (j=0;j<26;j++)
		{
			//cerr<<add[i][j]<<' ';
			ans2=max(ans2,ans-cst[i]+add[i][j]);
		}
		//cerr<<endl;
	}
	cout<<ans2<<endl;
	return 0;
}