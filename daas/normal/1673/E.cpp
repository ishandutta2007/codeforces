#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<iomanip>
#include<cstring>
#include<algorithm>
#include<ctime>
#include<vector>
#include<map>
#define ll long long
using namespace std;
inline int MOD(int x) {return (x%2+2)%2;}
int read()
{
	int kkk=0,x=1;
	char c=getchar();
	while((c<'0' || c>'9') && c!='-') c=getchar();
	if(c=='-') c=getchar(),x=-1;
	while(c>='0' && c<='9') kkk=kkk*10+(c-'0'),c=getchar();
	return kkk*x;
}
int n,K,ans[1<<20|10],b[1<<20|10],C[30][1<<20|10];
map<pair<int,int>,int> Q;
int Lucas(int n,int m)
{
	if(n<0 || m<0 || n<m) return 0;
	if(n<2 && m<2) return 1;
	return Lucas(n/2,m/2)*Lucas(n%2,m%2);
}
int check(int x,int y)
{
	int res=n-x,k=K-y;
	if(res<0 || res<k) return 0;
	k=max(k,0);
	int bck=0;
	return C[x][k];
	if(Q.find(make_pair(res,k))!=Q.end()) return Q[make_pair(res,k)];
	for(int i=k;i<=res;++i) bck=MOD(bck+Lucas(res,i));
	return Q[make_pair(res,k)]=bck;
}
int main()
{
	/*n=812757,K=8731;
	for(int i=1;i<=n;++i) b[i]=1;*/
	n=read(),K=read();
	for(int i=1;i<=n;++i) b[i]=read();
	int st=min(26,n);
	for(int i=0;i<=n;++i) C[st][i]=Lucas(n-st,i);
	for(int i=st-1;i>=0;--i)
	{
		for(int j=0;j<=n;++j)
		{
			C[i][j]=C[i+1][j];
			if(j) C[i][j]=MOD(C[i][j]+C[i+1][j-1]);
		}
	}
	for(int i=0;i<=st;++i)
		for(int j=n;j>=0;--j)
			C[i][j]=MOD(C[i][j]+C[i][j+1]);
	for(int i=1;i<=n;++i)
	{
		ll p=b[i];
		int B=0;
		for(int j=i;j<=n;++j)
		{
			//cout<<i<<" "<<j<<" "<<Q.count()<<endl;
			int num=(i!=1)+(j!=n);
			if(check((j-i+1)+num,num)) ans[p*(1<<B)]^=1;
			B+=b[j+1];
			if(B>=20 || p*(1<<B)>=(1<<20)) break;
		}
	}
	int ed=1<<20;
	while(!ans[ed] && ed) --ed;
	for(int i=ed;i>=0;--i) printf("%d",ans[i]);
	return 0;
}
//ore no turn,draw!