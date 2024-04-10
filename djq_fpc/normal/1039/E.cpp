#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<ctime>
#include<set>
#include<queue>
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
#define rdst(st,len){static char ss[len];scanf(" %s",ss);(st)=ss;}
//#define T_ int
using namespace std;
//struct bit{T_ arr[1000005];int lowbit(int x){return x&(-x);}void add(int x,T_ y){for (int i=x;i<=n;i+=lowbit(i)) arr[i]+=y;}T_ query(int x){T_ s=0;for (int i=x;i>0;i-=lowbit(i)) s+=arr[i];return s;}};
//struct seg{struct treedot{int l,r;T_ sum,add;void update(T_ x){sum+=(r-l+1)*x; add+=x;}}c[800005];void pushdown(int id){if (c[id].add){c[id*2].update(c[id].add);c[id*2+1].update(c[id].add);c[id].add=0;}}void pushup(int id){c[id].sum=c[id*2].sum+c[id*2+1].sum;}void build(int id,int l,int r){if (l>r) return;c[id].l=l;c[id].r=r;c[id].sum=0;c[id].add=0;if (l==r) c[id].sum=0;else{int mid=l+(r-l)/2;build(id*2,l,mid);build(id*2+1,mid+1,r);pushup(id);}}void update(int id,int le,int ri,T_ x){if (le>c[id].r||ri<c[id].l) return;if (le<=c[id].l&&c[id].r<=ri) c[id].update(x);else{pushdown(id);update(id*2,le,ri,x);update(id*2+1,le,ri,x);pushup(id);}}T_ query(int id,int le,int ri){if (ri<c[id].l||c[id].r<le) return 0;if (le<=c[id].l&&c[id].r<=ri) return c[id].sum;T_ ans=0;pushdown(id);ans+=query(id*2,le,ri);ans+=query(id*2+1,le,ri);pushup(id);return ans;}};
//struct bit_2d{T_ a[2005][2005];int lowbit(int x){return x&(-x);}void add(int x,int y,T_ z){int i,j;for (i=x;i<=2000;i+=lowbit(i)){for (j=y;j<=2000;j+=lowbit(j)){a[i][j]+=z;}}}T_ query(int x,int y){int i,j;T_ s=0;for (i=x;i;i-=lowbit(i)){for (j=y;j;j-=lowbit(j)){s+=a[i][j];}}return s;}T_ query(int x,int y,int xx,int yy){return query(xx,yy)-query(x-1,yy)-query(xx,y-1)+query(x-1,y-1);}};
int n,m,i,j,q,lc[100005],rc[100005],fa[100005],to[100005],a[100005],ans[100005],sz[100005],mx[100005][19],mi[100005][19],lg[100005],blk;
vector<pair<int,int> > seq;
vector<pair<int,int> > add[100005];
int query1(int x,int y){int k=lg[y-x+1];return max(mx[x][k],mx[y-(1<<k)+1][k])-min(mi[x][k],mi[y-(1<<k)+1][k]);}
int query2(int x,int y)
{
	int i,tmx=0,tmi=1e9+7,mem=x;
	for (i=18;i>=0;i--) if ((x+(1<<i))<=n+1&&max(tmx,mx[x][i])-min(tmi,mi[x][i])<=y)
	{
		tmx=max(tmx,mx[x][i]);tmi=min(tmi,mi[x][i]);x+=(1<<i);
	}
	return x;
}
int f(int x){return upper_bound(seq.begin(),seq.end(),make_pair(x,0))-seq.begin();}
void pushup(int x){sz[x]=sz[lc[x]]+sz[rc[x]]+1;}
bool isrt(int x){return lc[fa[x]]!=x&&rc[fa[x]]!=x;}
void rot(int x)
{
	int y=fa[x],z=fa[y];if (!isrt(y)){
		if (lc[z]==y) lc[z]=x; else rc[z]=x;
	}
	fa[y]=x;fa[x]=z;
	if (lc[y]==x){
		lc[y]=rc[x];rc[x]=y;if (lc[y]) fa[lc[y]]=y;
	}
	else{
		rc[y]=lc[x];lc[x]=y;if (rc[y]) fa[rc[y]]=y;
	}
	pushup(y);pushup(x);
}
void xzzg(int x)
{
	while (!isrt(x)){
		int y=fa[x],z=fa[y];if (!isrt(y)){
			if ((lc[z]==y)==(lc[y]==x)) rot(y); else rot(x);
		}
		rot(x);
	}
	pushup(x);
}
void fdls(int x)
{
	int y=0;while (x){
		xzzg(x);rc[x]=y;pushup(x);y=x;x=fa[x];
	}
}
void shan(int x){fdls(x);xzzg(x);fa[lc[x]]=0;lc[x]=0;pushup(x);}
int jia(int x,int y){fdls(x);xzzg(x);fa[x]=y;}
int xsyc(int &x)
{
	fdls(x);
	xzzg(x);int ans=sz[x]-1;
	while (lc[x]) x=lc[x];return ans;
}
int query(int x,int y)
{
	int ans=0; 
	while (x<=n){
		ans+=xsyc(x);
		if (x<=n){
			ans++;x=max(x+1,query2(x,y));
		}
	}
	return ans;
}
int main()
{
	scanf("%d%d%d",&n,&m,&q);blk=sqrt(n)+1;fz(i,2,n) lg[i]=lg[i/2]+1;
	fz1(i,n){
		scanf("%d",&a[i]);mx[i][0]=mi[i][0]=a[i];
	}
	mx[n+1][0]=1e9+7;mi[n+1][0]=0;
	fz1(j,18) fz1(i,n-(1<<j)+2){
		mx[i][j]=max(mx[i][j-1],mx[i+(1<<(j-1))][j-1]);
		mi[i][j]=min(mi[i][j-1],mi[i+(1<<(j-1))][j-1]);
	}
	fz1(i,q){
		int x;scanf("%d",&x);seq.push_back(make_pair(m-x,i)); 
	}
	sort(seq.begin(),seq.end());
	fz1(i,n){
		sz[i]=1;fa[i]=i+1;
		fz1(j,blk+1) if (i+j-1<=n){
			add[f(query1(i,i+j-1))].push_back(make_pair(i,i+j));
		}
	}
	fz0k(i,q){
		ff(add[i],it){
//			cerr<<seq[i].first<<' '<<it->first<<' '<<it->second<<endl; 
			shan(it->first);
			if (it->second<=it->first+blk) jia(it->first,it->second);
		}
		ans[seq[i].second]=query(1,seq[i].first);
	}
	fz1(i,q){
		printf("%d\n",ans[i]-1);
	}
	return 0;
}