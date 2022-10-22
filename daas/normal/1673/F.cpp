#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<iomanip>
#include<cstring>
#include<algorithm>
#include<ctime>
#include<vector>
#define ll long long
using namespace std;
int read()
{
	int kkk=0,x=1;
	char c=getchar();
	while((c<'0' || c>'9') && c!='-') c=getchar();
	if(c=='-') c=getchar(),x=-1;
	while(c>='0' && c<='9') kkk=kkk*10+(c-'0'),c=getchar();
	return kkk*x;
}
int n,K,a[50],ans,val[50][50],mem[2000][2];
void fun(int l,int r,int k)
{
	if(l==r) return;
	int mid=(l+r)>>1;
	a[mid]=k;
	fun(l,mid,k-1);
	fun(mid+1,r,k-1);
}
int main()
{
	fun(0,31,5);
	/*for(int i=0;i<32;++i) cout<<a[i]<<" ";
	cout<<endl;*/
	n=read(),K=read();
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<n;++j)
		{
			printf("%d ",(1<<(2*a[j-1]-1)));
			fflush(stdout);
			//cout<<(1<<(2*a[j-1]-1))<<" ";
			//ans+=(1<<(2*a[j-1]-1));
		}
		putchar('\n');
		fflush(stdout);
	}
	for(int i=1;i<n;++i)
	{
		for(int j=1;j<=n;++j)
		{
			printf("%d ",(1<<(2*a[i-1]-2)));
			fflush(stdout);
			//cout<<(1<<(2*a[i-1]-2))<<" ";
			//ans+=(1<<(2*a[i-1]-2));
		}
		putchar('\n');
		fflush(stdout);
	}
	for(int i=1;i<n;++i) val[0][i]=val[0][i-1]^(1<<(2*a[i-1]-1));
	for(int i=1;i<n;++i)
		for(int j=0;j<n;++j)
		{
			val[i][j]=val[i-1][j]^(1<<(2*a[i-1]-2));
		}
	memset(mem,-1,sizeof(mem));
	for(int i=0;i<n;++i)
		for(int j=0;j<n;++j)
		{
			//if(mem[val[i][j]][0]!=-1) cerr<<"cao";
			mem[val[i][j]][0]=i+1;
			mem[val[i][j]][1]=j+1;
			//cout<<val[i][j]<<" ";
		}
	int las=0;
	while(K--)
	{
		las^=read();
		printf("%d %d\n",mem[las][0],mem[las][1]);
		fflush(stdout);
	}
	//cout<<endl;
	//cout<<ans<<endl;
	return 0;
}
//ore no turn,draw!