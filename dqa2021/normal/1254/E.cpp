#include<cstdio>
#include<algorithm>
#include<cctype>
#include<cstdlib>
using namespace std;
#define G getchar()
int read()
{
	int x=0; bool flg=false; char ch=G;
	for (;!isdigit(ch);ch=G) if (ch=='-') flg=true;
	for (;isdigit(ch);ch=G) x=(x<<3)+(x<<1)+(ch^48);
	return flg?-x:x;
}
typedef long long ll;
const int Mod=1e9+7;
int fac[500010]; int ans=1;

int n,w[500010],iw[500010];
struct Edge{
	int to,nxt;
}edge[1000010];
int cnt=1,last[500010],deg[500010];
inline void addedge(int x,int y)
{
	//printf("%d: %d->%d\n",cnt+1,x,y);
	//printf("%d: %d->%d\n",cnt+2,y,x);
	edge[++cnt]=(Edge){y,last[x]},last[x]=cnt,deg[x]++;
	edge[++cnt]=(Edge){x,last[y]},last[y]=cnt,deg[y]++;
}
int fid[500010],dep[500010];  //to up
void dfs(int cur,int fid,int dep)
{
	::fid[cur]=fid; ::dep[cur]=dep;
	for (int i=last[cur],v;i;i=edge[i].nxt)
		if (i^fid) dfs(edge[i].to,i^1,dep+1);
}
int L[2000010],R[2000010],Lid[2000010],Rid[2000010],siz[2000010];
bool check(int cur,int l,int r)
{
	if (R[l]==r) return true;
	if (R[l]||L[r]) return false;
	if (Rid[r]==l) return false;
	if (Lid[l]>n+n&&Rid[r]>n+n&&siz[l]+siz[r]!=deg[cur]+2) return false;
	return true;
}
void cnct(int cur,int l,int r)
{
	if (!check(cur,l,r)) puts("0"),exit(0);
	if (R[l]==r) return;
	//printf("cnct %d  %d %d\n",cur,l,r);
	Lid[Rid[r]]=Lid[l],Rid[Lid[l]]=Rid[r];
	int a=siz[l],b=siz[r];
	siz[Lid[l]]+=b,siz[Rid[r]]+=a;
	L[r]=l,R[l]=r;
}
int main()
{
	n=read();
	for (int i=1;i<=(n<<2);i++) Lid[i]=Rid[i]=i,siz[i]=1;
	for (int i=1;i<n;i++) addedge(read(),read());
	fac[0]=1;
	for (int i=1;i<=n;i++) w[i]=read(),iw[w[i]]=i,fac[i]=1LL*fac[i-1]*i%Mod;
	dfs(1,0,1);  //edge[0].to=0
	int totdis=0;
	for (int i=1;i<=n;i++)
	{
		if (!iw[i]) continue;
		int x=i,y=iw[i],xid=x+n+n,yid=y+n*3;
		while (x^y)
			if (dep[x]<dep[y]) cnct(y,fid[y],yid),yid=fid[y]^1,y=edge[fid[y]].to,totdis++;
			else cnct(x,xid,fid[x]),xid=fid[x]^1,x=edge[fid[x]].to,totdis++;
		cnct(x,xid,yid);
		if (totdis>(n-1<<1)) return puts("0"),0;
	}
	for (int i=1;i<=n;i++)
	{
		int st=i+n+n,ed=i+n*3;
		int subans=(L[ed]?-1:0);
		for (int j=last[i];j;j=edge[j].nxt)
			if (!L[j]) subans++;
		if (subans<0) subans=0;
		ans=1LL*ans*fac[subans]%Mod;
		//printf("node %d get %d!\n",i,subans);
	}
	printf("%d\n",(ans+Mod)%Mod);
	return 0;
}