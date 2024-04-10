#include<bits/stdc++.h>
using namespace std;
const int M=998244353;
const int N=200005,E=524288;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
int i,j,n,k,a[2005][10],t[2005],s[2005],ww;
char c[2005];
string p[10]={"1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111","1010010","1111111","1111011"};
string w;
void dfs(int i,int p)
{
	if(p>t[i]||p<s[i])
		return;
	if(i>n)
	{
		for(i=1;i<=n;++i)
			putchar(c[i]);
		exit(0);
	}
	int j;
	for(j=9;j>=0;--j)
		if(p>=a[i][j])
		{
			c[i]=j+'0';
			dfs(i+1,p-a[i][j]);
		}
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	scanf("%d %d",&n,&ww);
	for(i=1;i<=n;++i)
	{
		cin>>w;
		int mn=(1<<30);
		for(j=0;j<10;++j)
		{
			for(k=0;k<7;++k)
			{
				if(w[k]!=p[j][k])
					if(w[k]=='1'&&p[j][k]=='0')
						a[i][j]=1<<30;
					else
						++a[i][j];
			}
			mn=min(mn,a[i][j]);
		}
		s[i]=mn;
		t[i]=a[i][8];
	}
	for(i=n;i>=1;--i)
		s[i]+=s[i+1],t[i]+=t[i+1];
	dfs(1,ww);
	puts("-1");
}