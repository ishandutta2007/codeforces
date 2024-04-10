#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
const int Mod=998244353,inv2=Mod+1>>1;
const ll MAXW=(1LL<<60)-1;

int n,m;
struct Bin{
	ll l; int len;
}a1[50010],a2[70][1010],b1[50010],b2[70][1010]; int a1tot,a2tot[70],b1tot,b2tot[70];
bool operator<(const Bin x,const Bin y)
{
	if (x.l^y.l) return x.l<y.l;
	return x.len<y.len;
}
bool operator==(const Bin x,const Bin y)
{
	return x.l==y.l&&x.len==y.len;
}
#define mid (l+r>>1)
void update1(ll l,ll r,int dep,ll ql,ll qr)  //dep 60
{
	a2[dep][++a2tot[dep]]=(Bin){l,dep};
	if (l==ql&&r==qr) return a1[++a1tot]=(Bin){l,dep},void();
	if (qr<=mid) update1(l,mid,dep-1,ql,qr);
	else if (ql>mid) update1(mid+1,r,dep-1,ql,qr);
	else update1(l,mid,dep-1,ql,mid),update1(mid+1,r,dep-1,mid+1,qr);
}
void update2(ll l,ll r,int dep,ll ql,ll qr)
{
	b2[dep][++b2tot[dep]]=(Bin){l,dep};
	if (l==ql&&r==qr) return b1[++b1tot]=(Bin){l,dep},void();
	if (qr<=mid) update2(l,mid,dep-1,ql,qr);
	else if (ql>mid) update2(mid+1,r,dep-1,ql,qr);
	else update2(l,mid,dep-1,ql,mid),update2(mid+1,r,dep-1,mid+1,qr);
}
#undef mid
struct Rec{
	ll pos; bool val;
}rec[15000010]; int rectop;
bool operator<(const Rec x,const Rec y)
{
	return x.pos<y.pos;
}

int ans;
void checkans(ll l,ll r)
{
	l%=Mod,r%=Mod;
	ans=(ans+(l+r)*(r-l+1)%Mod*inv2)%Mod;
}
int main()
{
	//freopen("data.in","r",stdin);
	//freopen("A.out","w",stdout);

	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		ll l,r; scanf("%I64d%I64d",&l,&r);  //%I64d !!!
		update1(0,MAXW,60,l,r);
	}
	scanf("%d",&m);
	for (int i=1;i<=m;i++)
	{
		ll l,r; scanf("%I64d%I64d",&l,&r);  //%I64d !!!
		update2(0,MAXW,60,l,r);
	}
	sort(a1+1,a1+a1tot+1); a1tot=unique(a1+1,a1+a1tot+1)-a1-1;
	sort(b1+1,b1+b1tot+1); b1tot=unique(b1+1,b1+b1tot+1)-b1-1;
	for (int i=0;i<=60;i++)
	{
		sort(a2[i]+1,a2[i]+a2tot[i]+1);
		a2tot[i]=unique(a2[i]+1,a2[i]+a2tot[i]+1)-a2[i]-1;
		sort(b2[i]+1,b2[i]+b2tot[i]+1);
		b2tot[i]=unique(b2[i]+1,b2[i]+b2tot[i]+1)-b2[i]-1;
	}
	
	for (int i=1,k;i<=a1tot;i++)
	{
		k=a1[i].len;
		//printf("get k %d\n",k);
		for (int j=1;j<=b2tot[k];j++)
		{
			ll l=a1[i].l^b2[k][j].l,r=l+(1LL<<k);  //[l,r)
			rec[++rectop]=(Rec){l,1}; rec[++rectop]=(Rec){r,0};
		}
	}
	for (int i=1,k;i<=b1tot;i++)
	{
		k=b1[i].len;
		//printf("get k %d\n",k);
		for (int j=1;j<=a2tot[k];j++)
		{
			ll l=b1[i].l^a2[k][j].l,r=l+(1LL<<k);  //[l,r)
			rec[++rectop]=(Rec){l,1}; rec[++rectop]=(Rec){r,0};
		}
	}
	sort(rec+1,rec+rectop+1);
	for (int i=1,j,tot=0;i<=rectop;i=j+1)
	{
		tot+=(rec[i].val?1:-1);
		for (j=i;j<rectop&&rec[j+1].pos==rec[i].pos;j++,tot+=(rec[j].val?1:-1));
		if (tot) checkans(rec[i].pos,rec[j+1].pos-1);
	}
	printf("%d\n",(ans+Mod)%Mod);
	return 0;
}