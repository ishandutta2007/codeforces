#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<set>
#include<iomanip>
#define sqr(x) (x)*(x)
#define fz1(i,n) for ((i)=1;(i)<=(n);(i)++)
#define fd1(i,n) for ((i)=(n);(i)>=1;(i)--)
#define fz0g(i,n) for ((i)=0;(i)<=(n);(i)++)
#define fd0g(i,n) for ((i)=(n);(i)>=0;(i)--)
#define fz0k(i,n) for ((i)=0;(i)<(n);(i)++)
#define fd0k(i,n) for ((i)=(long long)((n)-1);(i)>=0;(i)--)
#define fz(i,x,y) for ((i)=(x);(i)<=(y);(i)++)
#define fd(i,y,x) for ((i)=(y);(i)>=(x);(i)--)
#define ff(c,itr) for (__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
#define rdst(st,len){char ss[len];scanf("%s",ss);(st)=ss;}
//#define T_ long long
using namespace std;
//struct bit{T_ arr[1000005];int lowbit(int x){return x&(-x);}void add(int x,T_ y){for (int i=x;i<=n;i+=lowbit(i)) arr[i]+=y;}T_ query(int x){T_ s=0;for (int i=x;i>0;i-=lowbit(i)) s+=arr[i];return s;}};
//struct seg{struct treedot{int l,r;T_ sum,add;void update(T_ x){sum+=(r-l+1)*x; add+=x;}}c[800005];void pushdown(int id){if (c[id].add){c[id*2].update(c[id].add);c[id*2+1].update(c[id].add);c[id].add=0;}}void pushup(int id){c[id].sum=c[id*2].sum+c[id*2+1].sum;}void build(int id,int l,int r){if (l>r) return;c[id].l=l;c[id].r=r;c[id].sum=0;c[id].add=0;if (l==r) c[id].sum=0;else{int mid=l+(r-l)/2;build(id*2,l,mid);build(id*2+1,mid+1,r);pushup(id);}}void update(int id,int le,int ri,T_ x){if (le>c[id].r||ri<c[id].l) return;if (le<=c[id].l&&c[id].r<=ri) c[id].update(x);else{pushdown(id);update(id*2,le,ri,x);update(id*2+1,le,ri,x);pushup(id);}}T_ query(int id,int le,int ri){if (ri<c[id].l||c[id].r<le) return 0;if (le<=c[id].l&&c[id].r<=ri) return c[id].sum;T_ ans=0;pushdown(id);ans+=query(id*2,le,ri);ans+=query(id*2+1,le,ri);pushup(id);return ans;}};
int n,m,i,j,px[1500005][11],py[1500005][11],hsh1[1500005],hsh2[1500005],hd[1000005],nxt[1500005],b,e,len,dis[1500005],mod1=1e6+3,mod2=1e9+7,ee=97;
char mp[25][25];
int dx[5]={0,-1,1,0,0},dy[5]={0,0,0,-1,1};
void gth(int x)
{
	int i;
	hsh1[x]=hsh2[x]=0;
	fz1(i,len)
	{
		hsh1[x]=(1ll*hsh1[x]*ee+px[x][i])%mod1;
		hsh2[x]=(1ll*hsh2[x]*ee+px[x][i])%mod2;
		hsh1[x]=(1ll*hsh1[x]*ee+py[x][i])%mod1;
		hsh2[x]=(1ll*hsh2[x]*ee+py[x][i])%mod2;
	}
}
bool ins(int x)
{
	int i;
	for (i=hd[hsh1[x]];i;i=nxt[i])
	{
		if (hsh2[i]==hsh2[x])
		{
			return 0;
		}
	}
	nxt[x]=hd[hsh1[x]];
	hd[hsh1[x]]=x;
	return 1;
}
bool upd(int x,int y)
{
	if (!ins(x)) return 0;
	dis[x]=y;
	if (mp[px[x][1]][py[x][1]]=='@')
	{
		printf("%d\n",y);
		exit(0);
	}
	return 1;
}
int main()
{
	scanf("%d%d",&n,&m);
	b=e=1;
	fz1(i,n)
	{
		scanf(" ");
		fz1(j,m)
		{
			scanf("%c",&mp[i][j]);
			if (isdigit(mp[i][j]))
			{
				px[1][mp[i][j]-'0']=i;
				py[1][mp[i][j]-'0']=j;
				len=max(len,mp[i][j]-'0');
			}
		}
	}
	gth(1);ins(1);
	while (b<=e)
	{
		memcpy(px[0],px[b],sizeof(px[b]));
		memcpy(py[0],py[b],sizeof(py[b]));
		b++;
		fz1(i,4)
		{
			int xx=px[0][1]+dx[i],yy=py[0][1]+dy[i];
			if (xx<1||xx>n||yy<1||yy>m) continue;
			if (mp[xx][yy]=='#') continue;
			fz1(j,len-1) if (px[0][j]==xx&&py[0][j]==yy) break;
			if (j<=len-1) continue;
			e++;
			px[e][1]=xx;py[e][1]=yy;
			fz1(j,len-1)
			{
				px[e][j+1]=px[0][j];
				py[e][j+1]=py[0][j];
			}
			gth(e);
			if (!upd(e,dis[b-1]+1)) e--;
		}
	}//////
	puts("-1");
	return 0;
}