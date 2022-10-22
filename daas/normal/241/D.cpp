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
const int MAXN=5e4+10;
int read()
{
	int kkk=0,x=1;
	char c=getchar();
	while((c<'0' || c>'9') && c!='-') c=getchar();
	if(c=='-') c=getchar(),x=-1;
	while(c>='0' && c<='9') kkk=kkk*10+(c-'0'),c=getchar();
	return kkk*x;
}
int n,P,a[MAXN],z[MAXN],top,ans[MAXN],flag,mem[MAXN];
void fun(int xv,int pv,int k)
{
	if(flag) return;
	if(k==top+1)
	{
		if(!xv && !pv && mem[0])
		{
			flag=1;
			ans[0]=mem[0];
			for(int i=1;i<=mem[0];++i) ans[i]=mem[i];
			/*for(int i=1;i<=mem[0];++i) cout<<a[mem[i]]<<" ";
			cout<<endl;
			cout<<xv<<" "<<pv<<endl;*/
		}
		return;
	}
	fun(xv,pv,k+1);
	int val=a[z[k]];
	mem[++mem[0]]=z[k];
	fun(xv^val,(val>9?(pv*100+val)%P:(pv*10+val)%P),k+1);
	--mem[0];
}
int main()
{
	n=read(),P=read();
	for(int i=1;i<=n;++i)
	{
		a[i]=read();
		if(a[i]<=24) z[++top]=i;
	}
	fun(0,0,1);
	if(!flag) puts("No");
	else
	{
		puts("Yes");
		printf("%d\n",ans[0]);
		for(int i=1;i<=ans[0];++i) printf("%d ",ans[i]);
		putchar('\n');
	}
	return 0;
}
//ore no turn,draw