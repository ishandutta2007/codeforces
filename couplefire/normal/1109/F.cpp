#include<cstdio>
#include<algorithm>
#include<cctype>
using namespace std;
typedef pair<int,int> PI;
const int N=2e5+5,M=1005;
const int way[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
struct node
{
	int x,y;
}a[N];
int n,m,up,top,qx,qy,qz;
long long ans;
int fa[N],s[N][2],st[N];
bool rev[N];
PI f[N<<2];
int b[M][M],c[N<<2];
inline int read()
{
	int X=0,w=0; char ch=0;
	while(!isdigit(ch)) w|=ch=='-',ch=getchar();
	while(isdigit(ch)) X=(X<<3)+(X<<1)+(ch^48),ch=getchar();
	return w?-X:X;
}
inline bool pd(int x)
{
	return x==s[fa[x]][1];
}
inline bool isroot(int x)
{
	return x^s[fa[x]][0] && x^s[fa[x]][1];
}
inline void rotate(int x)
{
	int y=fa[x],w=pd(x);
	if((fa[x]=fa[y]) && !isroot(y)) s[fa[y]][pd(y)]=x;
	if(s[y][w]=s[x][w^1]) fa[s[y][w]]=y;
	s[fa[y]=x][w^1]=y;
}
inline void reverse(int x)
{
	if(x) swap(s[x][0],s[x][1]),rev[x]^=1;
}
inline void down(int x)
{
	if(rev[x])
	{
		reverse(s[x][0]),reverse(s[x][1]);
		rev[x]=false;
	}
}
inline void splay(int x)
{
	for(int y=st[top=1]=x;!isroot(y);y=fa[y]) st[++top]=fa[y];
	while(top) down(st[top--]);
	for(int y;!isroot(x);rotate(x))
		if(!isroot(y=fa[x])) rotate(pd(x)==pd(y)?y:x);
}
inline void access(int x)
{
	for(int y=0;x;x=fa[y=x]) splay(x),s[x][1]=y;
}
inline void mkroot(int x)
{
	access(x),splay(x),reverse(x);
}
inline void link(int x,int y)
{
	mkroot(x),fa[x]=y;
}
inline void cut(int x,int y)
{
	mkroot(x),access(y),splay(y);
	s[y][0]=fa[x]=0;
}
inline bool connect(int x,int y)
{
	mkroot(x),access(y),splay(y);
	while(s[y][0]) y=s[y][0];
	return x==y;
}
inline void down1(int v)
{
	if(c[v])
	{
		f[v<<1].first+=c[v];
		f[v<<1|1].first+=c[v];
		c[v<<1]+=c[v];
		c[v<<1|1]+=c[v];
		c[v]=0;
	}
}
void make(int v,int l,int r)
{
	if(l==r)
	{
		f[v].second=1;
		return;
	}
	int mid=l+r>>1;
	make(v<<1,l,mid);
	make(v<<1|1,mid+1,r);
	f[v].second=f[v<<1].second+f[v<<1|1].second;
}
PI cmin(PI x,PI y)
{
	if(x.first<y.first) return x;
	if(x.first>y.first) return y;
	return make_pair(x.first,x.second+y.second);
}
void change(int v,int l,int r)
{
	if(qx<=l && r<=qy)
	{
		f[v].first+=qz;
		c[v]+=qz;
		return;
	}
	down1(v);
	int mid=l+r>>1;
	if(qx<=mid) change(v<<1,l,mid);
	if(qy>mid) change(v<<1|1,mid+1,r);
	f[v]=cmin(f[v<<1],f[v<<1|1]);
}
PI find(int v,int l,int r)
{
	if(qx<=l && r<=qy) return f[v];
	down1(v);
	int mid=l+r>>1;
	PI val(N,0);
	if(qx<=mid) val=find(v<<1,l,mid);
	if(qy>mid) val=cmin(val,find(v<<1|1,mid+1,r));
	return val;
}
inline bool judge(int l,int r)
{
	for(int i=0;i<3;i++)
	{
		int x=a[r].x+way[i][0],y=a[r].y+way[i][1];
		if(!x || x>n || !y || y>m) continue;
		if(b[x][y]<l || b[x][y]>r) continue;
		for(int j=i+1;j<4;j++)
		{
			int xx=a[r].x+way[j][0],yy=a[r].y+way[j][1];
			if(!xx || xx>n || !yy || yy>m) continue;
			if(b[xx][yy]<l || b[xx][yy]>r) continue;
			if(connect(b[x][y],b[xx][yy])) return true;
		}
	}
	return false;
}
inline void del(int l)
{
	for(int i=0;i<4;i++)
	{
		int x=a[l].x+way[i][0],y=a[l].y+way[i][1];
		if(!x || x>n || !y || y>m) continue;
		if(connect(b[x][y],l))
			cut(b[x][y],l);
	}
}
inline void add(int l,int r)
{
	for(int i=0;i<4;i++)
	{
		int x=a[r].x+way[i][0],y=a[r].y+way[i][1];
		if(!x || x>n || !y || y>m) continue;
		if(l<=b[x][y] && b[x][y]<r)
		{
			link(b[x][y],r);
			qx=1,qy=b[x][y],qz=-1;
			change(1,1,up);
		}
	}
	qx=l,qy=r,qz=1;
	change(1,1,up);
}
int main()
{
	n=read(),m=read(),up=n*m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			b[i][j]=read();
			a[b[i][j]]=(node){i,j};
		}
	make(1,1,up);
	for(int i=1,j=1;i<=up;i++)
	{
		while(judge(j,i)) del(j++);
		add(j,i);
		qx=j,qy=i;
		PI sum=find(1,1,up);
		ans+=sum.first==1?sum.second:0;
	}
	printf("%I64d",ans);
	return 0;
}