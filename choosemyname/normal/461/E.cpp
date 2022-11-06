#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#include<vector>
#include<map>
#include<set>
#include<stack>
#include<string>
#include<cmath>
#include<cctype>
#include<ctime>
#include<bitset>
using namespace std;
const int maxlongint=2147483647;
const int inf=1000000000;
int ch[200010][5],fa[200010],len[200010],now=1,pre=1;
void insert(int i)
{
	now++;
	int np=now,p=pre;
	len[np]=len[p]+1;
	pre=np;
	for(;p!=0&&ch[p][i]==0;p=fa[p])
		ch[p][i]=np;
	if(p==0)
	{
		fa[np]=1;
		return;
	}
	//cout<<ch[p][i]<<' '<<len[ch[p][i]]<<' '<<len[p]+1<<endl;
	if(len[ch[p][i]]==len[p]+1)
	{
		fa[np]=ch[p][i];
		return;
	}
	int q=ch[p][i];
	now++;
	int nq=now;
	fa[nq]=fa[q];
	fa[q]=fa[np]=nq;
	len[nq]=len[p]+1;
	for(int n1=0;n1<4;n1++)
		ch[nq][n1]=ch[q][n1];
	for(;p!=0&&ch[p][i]==q;p=fa[p])
		ch[p][i]=nq;
}
int v[200010],dp[200010][4];
void get(int i)
{
	int n1,n2;
	if(v[i])
		return;
	v[i]=1;
	dp[i][0]=dp[i][1]=dp[i][2]=dp[i][3]=inf;
	for(n1=0;n1<=3;n1++)
		if(ch[i][n1]==0)
			dp[i][n1]=0;
		else
		{
			get(ch[i][n1]);
			for(n2=0;n2<=3;n2++)
				dp[i][n2]=min(dp[i][n2],dp[ch[i][n1]][n2]);
		}
	for(n1=0;n1<=3;n1++)
		dp[i][n1]++;
}			
char s[100010];	
long long n;
struct matrix
{
	long long p[5][5];
	long long* operator[](int x)
	{
		return p[x];
	}
};
matrix jzc(matrix a,matrix b)
{
	matrix c;
	for(int i=1;i<=4;i++)
		for(int j=1;j<=4;j++)
			c[i][j]=n+1;
	for(int i=1;i<=4;i++)
		for(int j=1;j<=4;j++)
			for(int k=1;k<=4;k++)
				c[i][j]=min(c[i][j],min(n,a[i][k]+b[k][j]));
	return c;
}
matrix go,no,f[70];
int getm(matrix a)
{
	for(int i=1;i<=4;i++)
		for(int j=1;j<=4;j++)
			if(a[i][j]<n)
				return 1;
	return 0;
}
int main()
{
	long long ans=0;
	cin>>n;
	int n1,n2,i;
	scanf("%s",s);
	int len=strlen(s);
	for(n1=0;n1<len;n1++)
		insert(s[n1]-65);
	get(1);
	for(n1=0;n1<=3;n1++)
		for(n2=0;n2<=3;n2++)
			go[n1+1][n2+1]=dp[ch[1][n1]][n2];
	f[0]=go;
	for(i=1;(1ll<<i)<=n;i++)
		f[i]=jzc(f[i-1],f[i-1]);
	for(n1=1;n1<=4;n1++)
		for(n2=1;n2<=4;n2++)
			if(n1==n2)
				no[n1][n2]=0;
			else
				no[n1][n2]=n+1;
	int p=i-1;
	for(i=p;i>=0;i--)
		if(getm(jzc(no,f[i]))==1)
		{
			ans+=(1ll<<i);
			no=jzc(no,f[i]);
		}
	cout<<ans+1<<endl;
}