#include<cstdio>
#include<algorithm>
#include<cctype>
using namespace std;
#define G getchar()
int read()
{
	int x=0; bool flg=false; char ch=G;
	for (;!isdigit(ch);ch=G) if (ch=='-') flg=true;
	for (;isdigit(ch);ch=G) x=(x<<3)+(x<<1)+(ch^48);
	return flg?-x:x;
}
void print(int x)
{
	if (x>9) print(x/10); putchar(x%10+48);
}
typedef long long ll;
const int Mod=1e9+7,inv2=Mod+1>>1;
const ll MAXW=1e18;

int n,q,w[100010];  //caution array size
struct Edge{
	int l,pos,nxt;
}edge[100010];
int cnt,last[100010];
inline void addedge(int l,int r,int pos)
{
	edge[++cnt]=(Edge){l,pos,last[r]},last[r]=cnt;
}
int ans[100010];

int wi2i[100010],pw[100010],ipw[100010];  //enough? ok.
int f[100010];
int find(int x)
{
	return f[x]?f[x]=find(f[x]):x;
}
struct Blk{
	int siz,ans; ll sum;
}blk[100010];
int blksum[100010];
int main()
{
	n=read(),q=read();
	for (int i=1;i<=n;i++) w[i]=read();
	for (int i=1,x,y;i<=q;i++) x=read(),y=read(),addedge(x,y,i);
	pw[0]=ipw[0]=1;
	for (int i=1;i<=n;i++)
	{
		pw[i]=pw[i-1]*2%Mod; ipw[i]=1LL*ipw[i-1]*inv2%Mod;
		wi2i[i]=(wi2i[i-1]+1LL*w[i]*pw[i])%Mod;
	}
	for (int i=1;i<=n;i++)
	{
		blk[i]=(Blk){1,w[i]*2%Mod,w[i]*2};  //negative  //caution avoid bit operation !!!
		blksum[i]=(blk[i].ans+(i==1?0:blksum[find(i-1)]))%Mod;
		for (int j=find(i);j!=1&&blk[j].sum>=0;j=find(i))
		{
			int u=find(j-1);
			blk[u].ans=(blk[u].ans+1LL*blk[j].ans*pw[blk[u].siz])%Mod;
//			if (blk[u].siz>60||blk[j].sum>MAXW/(1LL<<blk[u].siz)) blk[u].sum=MAXW;
//			else blk[u].sum=min(MAXW,blk[u].sum+blk[j].sum*(1LL<<blk[u].siz));
			if (blk[j].sum)   //caution overflow !!!
			{
				if (blk[u].siz>60||blk[j].sum>MAXW/(1LL<<blk[u].siz)) blk[u].sum=MAXW;
				else blk[u].sum=min(MAXW,blk[u].sum+blk[j].sum*(1LL<<blk[u].siz));
			}
			blksum[u]=(blksum[u]+1LL*blk[j].ans*pw[blk[u].siz])%Mod;
			blk[u].siz+=blk[j].siz;
			f[j]=u;
		}
//		printf("Case %d\n",i);
//		for (int j=1;j<=i;j++)
//			if (find(j)==j)
//			{
//				printf("block %d %d  %d %lld\n",j,j+blk[j].siz-1,blk[j].ans,blk[j].sum);
//			}
		for (int j=last[i];j;j=edge[j].nxt)
		{
			int x=find(edge[j].l);
			ans[edge[j].pos]=(blksum[find(i)]-blksum[x]+1LL*(wi2i[x+blk[x].siz-1]-wi2i[edge[j].l-1])*ipw[edge[j].l])%Mod;
		}
	}
	for (int i=1;i<=q;i++) print((ans[i]+Mod)%Mod),putchar('\n');
	return 0;
}