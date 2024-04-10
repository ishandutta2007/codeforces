#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<ctime>
#include<set>
#include<iomanip>
#include<stack>
#define sqr(x) ((x)*(x))
#define fz1(i,n) for ((i)=1;(i)<=(n);(i)++)
#define fd1(i,n) for ((i)=(n);(i)>=1;(i)--)
#define fz0g(i,n) for ((i)=0;(i)<=(n);(i)++)
#define fd0g(i,n) for ((i)=(n);(i)>=0;(i)--)
#define fz0k(i,n) for ((i)=0;(i)<(n);(i)++)
#define fd0k(i,n) for ((i)=(long long)((n)-1);(i)>=0;(i)--)
#define fz(i,x,y) for ((i)=(x);(i)<=(y);(i)++)
#define fd(i,y,x) for ((i)=(y);(i)>=(x);(i)--)
#define fzin fz1(i,n)
#define fzim fz1(i,m)
#define fzjn fz1(j,n)
#define fzjm fz1(j,m)
#define ff(c,itr) for (__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
#define rdst(st,len){static char ss[len];scanf(" %s",ss);(st)=ss;}
//#define T_ int
using namespace std;
//struct bit{T_ arr[1000005];int lowbit(int x){return x&(-x);}void add(int x,T_ y){for (int i=x;i<=n;i+=lowbit(i)) arr[i]+=y;}T_ query(int x){T_ s=0;for (int i=x;i>0;i-=lowbit(i)) s+=arr[i];return s;}};
//struct seg{struct treedot{int l,r;T_ sum,add;void update(T_ x){sum+=(r-l+1)*x; add+=x;}}c[800005];void pushdown(int id){if (c[id].add){c[id*2].update(c[id].add);c[id*2+1].update(c[id].add);c[id].add=0;}}void pushup(int id){c[id].sum=c[id*2].sum+c[id*2+1].sum;}void build(int id,int l,int r){if (l>r) return;c[id].l=l;c[id].r=r;c[id].sum=0;c[id].add=0;if (l==r) c[id].sum=0;else{int mid=l+(r-l)/2;build(id*2,l,mid);build(id*2+1,mid+1,r);pushup(id);}}void update(int id,int le,int ri,T_ x){if (le>c[id].r||ri<c[id].l) return;if (le<=c[id].l&&c[id].r<=ri) c[id].update(x);else{pushdown(id);update(id*2,le,ri,x);update(id*2+1,le,ri,x);pushup(id);}}T_ query(int id,int le,int ri){if (ri<c[id].l||c[id].r<le) return 0;if (le<=c[id].l&&c[id].r<=ri) return c[id].sum;T_ ans=0;pushdown(id);ans+=query(id*2,le,ri);ans+=query(id*2+1,le,ri);pushup(id);return ans;}};
//struct bit_2d{T_ a[2005][2005];int lowbit(int x){return x&(-x);}void add(int x,int y,T_ z){int i,j;for (i=x;i<=2000;i+=lowbit(i)){for (j=y;j<=2000;j+=lowbit(j)){a[i][j]+=z;}}}T_ query(int x,int y){int i,j;T_ s=0;for (i=x;i;i-=lowbit(i)){for (j=y;j;j-=lowbit(j)){s+=a[i][j];}}return s;}T_ query(int x,int y,int xx,int yy){return query(xx,yy)-query(x-1,yy)-query(xx,y-1)+query(x-1,y-1);}};
int n,m,i,j,lc[200005],rc[200005],sz[200005],fa[200005],s[400005],lst[200005],tag[200005],rev[200005],cnt,x,y;
char ss[18];
vector<int> bi[200005];
void add(int x,int y){int i;for (i=x;i<=n+m;i+=(i&(-i))) s[i]+=y;}
int query(int x){int i,sum=0;for (i=x;i;i-=(i&(-i))) sum+=s[i];return sum;}
bool isrt(int x){return lc[fa[x]]!=x&&rc[fa[x]]!=x;}
void pushup(int x){sz[x]=sz[lc[x]]+sz[rc[x]]+1;}
void pushdo(int x){if (rev[x]){swap(lc[x],rc[x]);rev[lc[x]]^=1;rev[rc[x]]^=1;rev[x]=0;}if (tag[x]){tag[lc[x]]=tag[rc[x]]=lst[lc[x]]=lst[rc[x]]=tag[x];tag[x]=0;}}
void rot(int x){
	int y=fa[x],z=fa[y];
	if (!isrt(y)){
		if (lc[z]==y) lc[z]=x; else rc[z]=x;
	}
	if (lc[y]==x){
		lc[y]=rc[x];fa[rc[x]]=y;
		rc[x]=y;fa[y]=x;fa[x]=z;
	}else{
		rc[y]=lc[x];fa[lc[x]]=y;
		lc[x]=y;fa[y]=x;fa[x]=z;
	}
	pushup(x);pushup(y);pushup(x);pushup(y);
}
void xzzg(int x){
	stack<int> stk;stk.push(x);int t=x;
	while (!isrt(x)){
		x=fa[x];
		stk.push(x);
	}
	while (!stk.empty()){
		pushdo(stk.top());
		stk.pop();
	}
	x=t;
	while (!isrt(x)){
		int y=fa[x],z=fa[y];
		if (!isrt(y)){
			if ((lc[z]==y)^(lc[y]==z)){
				rot(x);
			}else{
				rot(y);
			}
		}
		rot(x);
	}
}
void fdls(int x,int cnt){
	int y=0;
	while (x){
		xzzg(x);rc[x]=0;pushup(x);
		add(lst[x],-sz[x]);lst[x]=tag[x]=cnt;add(lst[x],sz[x]);
		rc[x]=y;pushup(x);y=x;x=fa[x];
	}
}
void mkrt(int x){fdls(x,cnt);xzzg(x);rev[x]^=1;}
int solve(int x){xzzg(x);pushdo(x);return query(lst[x])-sz[lc[x]];}
void dfs(int x,int p){fa[x]=p;sz[x]=1;lst[x]=x;ff(bi[x],it) if (*it!=p){dfs(*it,x);if (lst[*it]>lst[x]){lst[x]=lst[*it];rc[x]=*it;}}pushup(x);add(lst[x],1);}
int main()
{
	scanf("%d%d",&n,&m);cnt=n; 
	fz1(i,n-1){
		scanf("%d%d",&x,&y);
		bi[x].push_back(y);bi[y].push_back(x); 
	}
	dfs(n,0);
	fz1(i,m)
	{
		scanf(" %s",ss);
		if (ss[0]=='u'){
			scanf("%d",&x);
			mkrt(x);pushdo(x);add(lst[x],-1);
			lst[x]=tag[x]=++cnt;
			rc[x]=0;sz[x]=1;add(lst[x],1);
		}else if (ss[0]=='w'){
			scanf("%d",&x);
			printf("%d\n",solve(x));
		}else if (ss[0]=='c'){
			scanf("%d%d",&x,&y);
//			cerr<<(solve(x)<solve(y))<<endl;
			printf("%d\n",solve(x)<solve(y)?x:y);
		}
	}
	return 0;
}