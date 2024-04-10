#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <map>
#define Fo(i,a,b) for(int i=(a);i<(b);i++)
#define Fr(i,a,b) for(int i=(a);i<=(b);i++)
#define Fl(i,a,b) for(int i=(a);i>=(b);i--)
typedef long long ll;
using namespace std;
const int MX=1000100,P=998244353;

ll Pow(ll a,ll b)
{
	ll r=1;
	a%=P;
	while(b)
	{
		if(b&1)r=r*a%P;
		a=a*a%P,b>>=1;
	}
	return r%P;
}
ll Inv(ll a){return Pow(a,P-2);}

int N,M,K;
map<pair<int,int>,int> mp;

int numx,numy;
int X[MX][2],Y[MX][2];
int cntx[3],cnty[3];
int cntw[2];

#define mk make_pair

void Clear(int x,int y)
{
	if(!mp.count(mk(x,y))||mp[mk(x,y)]-1==-1)return;
	int c=mp[mk(x,y)]-1;
	--cntw[(x^y^c)&1];
	
	--cntx[!!X[x][0]+!!X[x][1]];
	--X[x][(y&1)^c];
	++cntx[!!X[x][0]+!!X[x][1]];
	
	--cnty[!!Y[y][0]+!!Y[y][1]];
	--Y[y][(x&1)^c];
	++cnty[!!Y[y][0]+!!Y[y][1]];
	
	mp[mk(x,y)]=0;
	pair<int,int> p=mk(x,y-1);
	if(mp.count(p)&&mp[p]-1==c)--numx;
	p=mk(x,y+1);
	if(mp.count(p)&&mp[p]-1==c)--numx;
	p=mk(x-1,y);
	if(mp.count(p)&&mp[p]-1==c)--numy;
	p=mk(x+1,y);
	if(mp.count(p)&&mp[p]-1==c)--numy;
}

void Assign(int x,int y,int c)
{
	++cntw[(x^y^c)&1];
	
	--cntx[!!X[x][0]+!!X[x][1]];
	++X[x][(y&1)^c];
	++cntx[!!X[x][0]+!!X[x][1]];
	
	--cnty[!!Y[y][0]+!!Y[y][1]];
	++Y[y][(x&1)^c];
	++cnty[!!Y[y][0]+!!Y[y][1]];
	
	mp[mk(x,y)]=c+1;
	pair<int,int> p=mk(x,y-1);
	if(mp.count(p)&&mp[p]-1==c)++numx;
	p=mk(x,y+1);
	if(mp.count(p)&&mp[p]-1==c)++numx;
	p=mk(x-1,y);
	if(mp.count(p)&&mp[p]-1==c)++numy;
	p=mk(x+1,y);
	if(mp.count(p)&&mp[p]-1==c)++numy;
}

ll Calc()
{
	ll sum=0;
	if(!numy)
	{
		ll t=Pow(2,cnty[0]);
		if(cnty[2])t=0;
		sum+=t,sum%=P;
	}
	if(!numx)
	{
		ll t=Pow(2,cntx[0]);
		if(cntx[2])t=0;
		sum+=t,sum%=P;
	}
//	printf("%d %d\n",cntw[0],cntw[1]);
	return (sum-!cntw[0]-!cntw[1]+P)%P;
}

int main()
{
	scanf("%d%d%d",&N,&M,&K);
	cntx[0]=N,cnty[0]=M;
	Fr(i,1,K)
	{
		int x,y,t;
		scanf("%d%d%d",&x,&y,&t);
		Clear(x,y);
		if(t!=-1)Assign(x,y,t);
		printf("%lld\n",Calc());
	}
	return 0;
}