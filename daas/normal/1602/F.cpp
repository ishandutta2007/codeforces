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
const int MAXN=5e5+10;
int read()
{
	int kkk=0,x=1;
	char c=getchar();
	while((c<'0' || c>'9') && c!='-') c=getchar();
	if(c=='-') c=getchar(),x=-1;
	while(c>='0' && c<='9') kkk=kkk*10+(c-'0'),c=getchar();
	return kkk*x;
}
int n,D,ans;
struct data
{
	int a,b;
	bool operator <(const data &Z) const {return (max(a,b)==max(Z.a,Z.b))?a<Z.a:max(a,b)<max(Z.a,Z.b);}
	//bool operator <(const data &Z) const {return (a+b==Z.a+Z.b)?a>Z.a:a+b<Z.a+Z.b;}
}Q[MAXN];
int main()
{
	n=read(),D=read();
	for(int i=1;i<=n;++i) Q[i].a=read(),Q[i].b=read();
	sort(Q+1,Q+n+1);
	for(int i=1;i<=n;++i)
	{
		if(Q[i].a>=D)
		{
			D=max(D,Q[i].b);
			++ans;
		}
	}
	printf("%d\n",ans);
	return 0;
}
//ore no turn,draw!