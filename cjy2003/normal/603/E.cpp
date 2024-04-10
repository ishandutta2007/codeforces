#include<cstdio>
#include<cstring>
#include<algorithm>
#include<set>
using namespace std;
int n,m;
namespace lct
{
	int siz[400040],qsiz[400040],val[400040],mx[400040],mxp[400040],ch[400040][2],f[400040];
	bool tag[400040];
	inline void pushup(int x)
	{
		siz[x]=qsiz[x]+siz[ch[x][0]]+siz[ch[x][1]]+(x<=n);
		mx[x]=val[x],mxp[x]=x;
		if(mx[ch[x][0]]>mx[x])mx[x]=mx[ch[x][0]],mxp[x]=mxp[ch[x][0]];
		if(mx[ch[x][1]]>mx[x])mx[x]=mx[ch[x][1]],mxp[x]=mxp[ch[x][1]];
	}
	inline void pushdown(int x)
	{
		int y;
		if(ch[x][0])y=ch[x][0],swap(ch[y][0],ch[y][1]),tag[y]^=1;
		if(ch[x][1])y=ch[x][1],swap(ch[y][0],ch[y][1]),tag[y]^=1;
		tag[x]=0;
	}
	inline bool isroot(int x){return ch[f[x]][0]!=x&&ch[f[x]][1]!=x;}
	inline void rotate(int x)
	{
		int y=f[x],z=f[y],s=ch[x][ch[y][0]==x];
		if(!isroot(y))ch[z][ch[z][1]==y]=x;f[x]=z;
		ch[x][ch[y][0]==x]=y;f[y]=x;
		ch[y][ch[y][1]==x]=s;f[s]=y;
		pushup(y);
	}
	inline void splay(int x)
	{
		static int st[400040],tp;
		int y=x,z;
		while(!isroot(y))st[++tp]=y,y=f[y];st[++tp]=y;
		while(tp)tag[st[tp]]?pushdown(st[tp]),0:0,--tp;
		while(!isroot(x))
		{
			y=f[x],z=f[y];
			if(!isroot(y))
			{
				if((ch[z][0]==y)^(ch[y][0]==x))rotate(x);
				else rotate(y);
			}
			rotate(x);
		}
		pushup(x);
	}
	void access(int x)
	{
		for(int t=0;x;t=x,x=f[x])
		{
			splay(x);
			qsiz[x]+=siz[ch[x][1]];
			ch[x][1]=t;qsiz[x]-=siz[t];
			pushup(x);
		}
	}
	int findroot(int x)
	{
		access(x);splay(x);
		while(ch[x][0])
		{
			if(tag[x])pushdown(x);
			x=ch[x][0];
		}
		splay(x);
		return x;
	}
	void makeroot(int x)
	{
	//	printf("makeroot%d\n",x);
	//	print();
		access(x);
	//	printf("maccess\n");
	//	print();
		splay(x);
		swap(ch[x][0],ch[x][1]),tag[x]^=1;
	}
	void link(int x,int y)
	{
		makeroot(x);access(y);splay(y);
		f[x]=y;qsiz[y]+=siz[x];siz[y]+=siz[x];
	}
	void cut(int x,int y)
	{
		makeroot(x);
	//	printf("cut\n");print();
		access(y);//printf("cut\n");
		splay(x);
		ch[x][1]=0,f[y]=0;pushup(x);
	}
	int qrysiz(int x)
	{
		access(x);splay(x);
		return siz[x];
	}
	void print()
	{
		printf("rt:%d\n",findroot(1));
		for(int i=1;i<=n+m;++i)printf("%d %d %d %d %d\n",ch[i][0],ch[i][1],f[i],siz[i],tag[i]);
		printf("\n");
	}
}using namespace lct;
int b[300030][3],cnt;
set<pair<int,int> >S;
int main()
{
	scanf("%d %d",&n,&m);
	int x,y,w,c;
	for(int i=1;i<=n;++i)siz[i]=1;cnt=n;
	for(int i=1;i<=m;++i)
	{
		scanf("%d %d %d",&x,&y,&w);b[i][0]=x,b[i][1]=y,b[i][2]=w;
		val[i+n]=w,mx[i+n]=w,mxp[i+n]=i+n;
		if(findroot(x)==findroot(y))
		{
			makeroot(x);
		//	printf("makeroot\n");
		//	print();
			access(y);splay(x);
		//	print();
			if(w<mx[x])
			{
				c=mxp[x]-n;
			//	printf("c%d\n",c);
				cut(n+c,b[c][0]);//print();
				cut(n+c,b[c][1]);S.erase(make_pair(b[c][2],c));
			//	print();
				link(n+i,x);link(n+i,y);S.insert(make_pair(w,i));
			}
		}
		else
		{
			if((qrysiz(x)&1)&&(qrysiz(y)&1))cnt-=2;
		//	print();
			link(x,i+n);
		//	printf("link%d %d\n",x,i+n);
		//	print();
			link(i+n,y);
			S.insert(make_pair(w,i));
		}
	//	print();
		while(!cnt)
		{
			int c=S.rbegin()->second;
			x=b[c][0],y=b[c][1];
			cut(x,n+c),cut(y,n+c);
		//	printf("%d %d\n",qrysiz(x),qrysiz(y));
			if(qrysiz(x)&1)
			{
				link(x,n+c),link(y,n+c);
				break;
			}
			S.erase(*S.rbegin());
		}
		if(cnt)printf("-1\n");
		else printf("%d\n",S.rbegin()->first);
	//	print();
	}
	return 0;
}