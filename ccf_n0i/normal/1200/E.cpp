#include <bits/stdc++.h>
#define rep(i,n) for ((i)=1;(i)<=(n);(i)++)
using namespace std;
int n,m,i,j,k,lst;
string st[100005],ans;
char _[1000005];
long long e=1e6+3,mod[3]={1000000007,1000000009,1000033},hsh[3][1000005],hsh2[3][1000005],pw[3][1000005];
long long gethash(int typ,int l,int r)
{
	long long t=hsh[typ][r]-hsh[typ][l-1]*pw[typ][r-l+1]%mod[typ];
	if(t<0)t+=mod[typ];
	return t;
}
long long gethash2(int typ,int l,int r)
{
	long long t=hsh2[typ][r]-hsh2[typ][l-1]*pw[typ][r-l+1]%mod[typ];
	if(t<0)t+=mod[typ];
	return t;
}
void buqi()
{
	while(lst<ans.size())
	{
		int i;
		for(i=0;i<3;i++)
		{
			hsh[i][lst+1]=(hsh[i][lst]*e+ans[lst])%mod[i];
		}
		for(i=0;i<3;i++)
		{
			pw[i][lst+1]=pw[i][lst]*e%mod[i];
		}
		lst++;
	}
}
int main()
{
	scanf("%d",&n);
	rep(i,n)
	{
		scanf(" %s",_);
		st[i]=_;
	}
	lst=0;
	ans=st[1];
	pw[0][0]=pw[1][0]=pw[2][0]=1;
	buqi();
	for(k=2;k<=n;k++)
	{
		for(j=0;j<st[k].size();j++)
		{
			for(i=0;i<3;i++)
			{
				hsh2[i][j+1]=(hsh2[i][j]*e+st[k][j])%mod[i];
			}
		}
		for(j=min(st[k].size(),ans.size());j>=1;j--)
		{
			bool f=1;
			for(i=0;i<3;i++)
			{
				if(gethash(i,ans.size()-j+1,ans.size())!=gethash2(i,1,j))
				{
					f=0;break;
				}
			}
			if(f)break;
		}
		for(i=j;i<st[k].size();i++)
		{
			ans.push_back(st[k][i]);
		}
		buqi();
	}
	puts(ans.c_str());
	return 0;
}