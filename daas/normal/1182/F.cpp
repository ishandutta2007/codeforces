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
const int base=35010;
int read()
{
	int kkk=0,x=1;
	char c=getchar();
	while((c<'0' || c>'9') && c!='-') c=getchar();
	if(c=='-') c=getchar(),x=-1;
	while(c>='0' && c<='9') kkk=kkk*10+(c-'0'),c=getchar();
	return kkk*x;
}
int T,p,q,a,b,ans,cnt;
pair<int,int> mem[base+10];
int calc(int x) {return 2ll*p*x%(2*q);}
int chk(int x)
{
	int bck=abs(calc(x)-q);
	return min(bck,2*q-bck);
}
void check(int x)
{
	int v1=chk(x),v2=chk(ans);
	if(v1<v2) ans=x;
	else if(v1==v2) ans=min(ans,x);
}
void solve(int st)
{
	int val=((ll)q-calc(st)+2*q)%(2*q);
	int l=1,r=cnt,lim=cnt;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(mem[mid].first<=val) lim=mid,l=mid+1;
		else r=mid-1;
	}
	check(st+mem[lim].second);
	check(st+mem[lim%cnt+1].second);
}
int main()
{
	//freopen("5.in","r",stdin);
	//freopen("5.out","w",stdout);
	T=read();
	while(T--)
	{
	    a=read(),b=read();
		p=read(),q=read();
		ans=a; ++a;
		if(b-a<base)
		{
			for(int i=a;i<=b;++i) check(i);
			printf("%d\n",ans);
			//cout<<chk(ans)<<endl;
			continue;
		}
		for(int i=1;i<=base;++i) mem[i]=make_pair(calc(i),i);
		sort(mem+1,mem+base+1);
		cnt=0;
		for(int l=1,r;l<=base;l=r+1)
		{
			r=l;
			while(r+1<=base && mem[r+1].first==mem[l].first) ++r;
			mem[++cnt]=mem[l];
		}
		for(int i=a;i+base-1<=b;i+=base) solve(i-1);
		solve(b-base);
		printf("%d\n",ans);
		//cout<<chk(ans)<<endl;
	}
	return 0;
}
//ore no turn,draw!