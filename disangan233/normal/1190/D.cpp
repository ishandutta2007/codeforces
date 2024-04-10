#include<bits/stdc++.h>
using namespace std;
#define re register int
#define in inline
#define db double
#define ll long long
#define ak *
in char getch()
{
	static char buf[10000],*p1=buf,*p2=buf;
	return p1==p2&&(p2=(p1=buf)+fread(buf,1,10000,stdin),p1==p2)?EOF:*p1++;
}
char qwq;
#define gc() getch()
in int read()
{
	re cz=0,ioi=1;qwq=gc();
	while(qwq<'0'||qwq>'9') ioi=qwq=='-'?~ioi+1:1,qwq=gc();
	while(qwq>='0'&&qwq<='9') cz=(cz<<3)+(cz<<1)+(qwq^48),qwq=gc();
	return cz ak ioi;
}
const int N=2e5+5;
int n,x[N],tx[N],y[N],ty[N],cnt[N],nx,ny;
ll ans;
vector<int>vec[N];
ll t[N];
in int lowbit(re x) {return x&-x;}
in void upd(re x,re y) {for(;x<=n;x+=lowbit(x)) t[x]+=y;}
in ll ask(re x) {ll y=0;for(;x;x-=lowbit(x)) y+=t[x];return y;}
in ll ask(re x,re y) {return ask(y)-ask(x-1);}
int main()
{
	n=read();
	for(re i=1;i<=n;i++) x[i]=tx[i]=read(),ty[i]=y[i]=read();
	sort(tx+1,tx+n+1);nx=unique(tx+1,tx+n+1)-tx-1;
	sort(ty+1,ty+n+1);ny=unique(ty+1,ty+n+1)-ty-1;
	for(re i=1;i<=n;i++)
	{
		x[i]=lower_bound(tx+1,tx+nx+1,x[i])-tx;
		y[i]=lower_bound(ty+1,ty+ny+1,y[i])-ty;
	}
	for(re i=1;i<=n;i++) vec[y[i]].push_back(x[i]);
	for(re i=1;i<=ny;i++) sort(vec[i].begin(),vec[i].end());
	for(re i=ny;i;i--)
	{
		for(re j=0;j<vec[i].size();j++)
		if(++cnt[vec[i][j]]==1) upd(vec[i][j],1);
		ll len=ask(1,nx);ans+=len*(len+1)/2;
		len=ask(1,vec[i][0]-1);ans-=len*(len+1)/2;
		len=ask(vec[i][vec[i].size()-1]+1,nx);
		ans-=len*(len+1)/2;
		for(re j=0;j<vec[i].size()-1;j++)
		{
			len=ask(vec[i][j]+1,vec[i][j+1]-1);
			ans-=len*(len+1)/2;
		}
	}
	cout<<ans<<endl;
}