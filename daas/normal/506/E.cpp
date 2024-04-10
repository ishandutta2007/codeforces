#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<iomanip>
#include<cstring>
#include<algorithm>
#include<ctime>
using namespace std;
const int mod=1e4+7;
inline int read()
{
	int kkk=0,x=1;
	char c=getchar();
	while((c<'0' || c>'9') && c!='-')
		c=getchar();
	if(c=='-')
		c=getchar(),x=-1;
	while(c>='0' && c<='9')
		kkk=(kkk<<3)+(kkk<<1)+(c-'0'),c=getchar();
	return kkk*x;
}
int n,len,CNT[210][210][210],line[210],ANS;
char s[210];
struct data
{
	int A[410][410],n,m;
}change,ans;
data mul(data x,data y)
{
	data z;
	memset(z.A,0,sizeof(z.A));
	z.n=x.n,z.m=y.m;
	for(int i=0;i<=x.n;++i)
		for(int j=0;j<=x.m;++j)
			for(int k=0;k<=y.m;++k)
				(z.A[i][k]+=x.A[i][j]*y.A[j][k])%=mod;
	return z;
}
void init()
{
	change.n=change.m=ans.m=len+(len+1)/2+1,ans.A[0][0]=1;
	for(int i=0;i<len;++i)
	{
		change.A[i][i+1]=1;
		change.A[i+1][i+1]=24;
	}
	for(int i=len+1;i<ans.m;++i)
	{
		change.A[i][i+1]=1;
		change.A[i][i]=25;
	}
	change.A[len][ans.m]=1;
	change.A[ans.m][ans.m]=26;
	for(int x=0;x<=len;++x)
	{
		int y=(len-x+1)/2;
		change.A[x][ans.m-y]=line[x];
	}
}
void out_change()
{
	cout<<"0 "<<len<<" "<<len+1<<" "<<ans.m-1<<" "<<ans.m<<endl;
	cout<<setw(4)<<0;
	for(int i=0;i<=ans.m;++i)
		cout<<setw(4)<<i;
	cout<<endl;
	for(int i=0;i<=ans.m;++i)
	{
		cout<<setw(4)<<i;
		for(int j=0;j<=ans.m;++j)
			cout<<setw(4)<<change.A[i][j];
		cout<<endl;
	}
}
int main()
{
	scanf("%s",s);
	n=read();
	len=strlen(s);
	CNT[0][len-1][s[0]!=s[len-1]]=1;
	for(int i=len;i>=2;--i)
		for(int l=0;l+i-1<len;++l)
		{
			int r=l+i-1;
			for(int k=0;k<=len;++k)
				if(s[l]==s[r])
					(CNT[l+1][r-1][k+(s[l+1]!=s[r-1])]+=CNT[l][r][k])%=mod;
				else
				{
					(CNT[l+1][r][k+(s[l+1]!=s[r])]+=CNT[l][r][k])%=mod;
					(CNT[l][r-1][k+(s[l]!=s[r-1])]+=CNT[l][r][k])%=mod;
				}
		}
	for(int i=2;i>=1;--i)
		for(int l=0;l+i-1<len;++l)
		{
			int r=l+i-1;
			for(int k=0;k<=len;++k)
				if(s[l]==s[r])
					(line[k]+=CNT[l][r][k])%=mod;
		}
	/*for(int l=0;l<len;++l)
		for(int r=l;r<len;++r)
		{
			for(int j=l;j<=r;++j)
				cout<<s[j];
			cout<<endl;
			for(int j=0;j<=len;++j)
				cout<<CNT[l][r][j]<<" ";
			cout<<endl;
		}*/
	/*for(int i=0;i<=len;++i)
		cout<<line[i]<<" ";
	cout<<endl;*/
	init();
	//out_change();
	int Time=(n+len+1)/2+1;
	//cout<<"WRP AK IOI "<<Time<<endl;
	while(Time)
	{
		if(Time%2)
			ans=mul(ans,change);
		change=mul(change,change);
		Time/=2;
	}
	ANS=ans.A[0][ans.m];
	if((n+len)%2==0)
	{
		printf("%d\n",ANS);
		return 0;
	}
	//cout<<ANS<<endl;
	for(int i=0;i<len;++i)
		for(int k=0;k<=len;++k)
			line[k]=(line[k]-CNT[i][i][k]+mod)%mod;
	memset(ans.A,0,sizeof(ans.A));
	memset(change.A,0,sizeof(change.A));
	init();
	change.A[ans.m][ans.m]=0;
	//out_change();
	Time=(n+len+1)/2+1;
	//cout<<"WRP AK NOI "<<Time<<endl;
	while(Time)
	{
		if(Time%2)
			ans=mul(ans,change);
		change=mul(change,change);
		Time/=2;
	}
	printf("%d\n",(ANS-ans.A[0][ans.m]+mod)%mod);
	return 0;
}