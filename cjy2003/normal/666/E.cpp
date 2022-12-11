#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
char s[500050],a[50050];
int n,m,q;
struct data
{
	int mx,p;
	friend data operator + (data a,data b){return a.mx>=b.mx?a:b;}
}ans[500050];
namespace seg
{
	int rt[1000010],ch[5000000][2],tot;
	data s[5000000];
	void ins(int &k,int l,int r,int p)
	{
		if(!k)k=++tot,s[k]={0,l};
		if(l==r)return ++s[k].mx,void();
		if(p<=l+r>>1)ins(ch[k][0],l,l+r>>1,p);
		else ins(ch[k][1],(l+r>>1)+1,r,p);
		s[k]=s[ch[k][0]]+s[ch[k][1]];
	}
	data query(int k,int l,int r,int ll,int rr)
	{
		if(l>rr||r<ll||k==0)return data{0,ll};
		if(l>=ll&&r<=rr)return s[k];
		return query(ch[k][0],l,l+r>>1,ll,rr)+query(ch[k][1],(l+r>>1)+1,r,ll,rr);
	}
	void merge(int &k1,int k2,int l,int r)
	{
		if(!k1||!k2)return k1+=k2,void();
		if(l==r)return s[k1].mx+=s[k2].mx,void();
		merge(ch[k1][0],ch[k2][0],l,l+r>>1);
		merge(ch[k1][1],ch[k2][1],(l+r>>1)+1,r);
		s[k1]=s[ch[k1][0]]+s[ch[k1][1]];
	}
}
struct query
{
	int l,r,len,id;
	friend bool operator < (query a,query b){return a.len<b.len;}
};
namespace SAM
{
	int ch[1000010][26],f[1000010],len[1000010],ed=1,tot=1,p[500050],up[1000010][20];
	vector<query>Q[1000010];
	vector<int>E[1000010];
	vector<pair<int,int> >ad[1000010];
	void extend(int c)
	{
		int p=ed;ed=++tot;len[ed]=len[p]+1;
		while(p&&!ch[p][c])ch[p][c]=ed,p=f[p];
		if(!p)return f[ed]=1,void();
		int q=ch[p][c];
		if(len[p]+1==len[q])return f[ed]=q,void();
		int nq=++tot;len[nq]=len[p]+1;
		memcpy(ch[nq],ch[q],sizeof(ch[q]));
		f[nq]=f[q],f[ed]=f[q]=nq;
		while(ch[p][c]==q)ch[p][c]=nq,p=f[p];
	}
	void build()
	{
		for(int i=1;i<=n;++i)extend(s[i]-'a'),p[i]=ed;/*,printf("%d ",p[i]);printf("\n");*/
		for(int i=2;i<=tot;++i)up[i][0]=f[i],E[f[i]].push_back(i)/*,printf("%d %d\n",f[i],i)*/;
		for(int i=1;i<=19;++i)
			for(int j=1;j<=tot;++j)up[j][i]=up[up[j][i-1]][i-1];
	}
	void run(int id)
	{
		int lena=strlen(a+1),u=1,c,clen=0;
		for(int i=1;i<=lena;++i)
		{
			c=a[i]-'a';
			while(u&&!ch[u][c])u=f[u],clen=len[u];
			if(!u)u=1;
			else u=ch[u][c],++clen;
			ad[u].push_back(make_pair(clen,id));
		//	seg::ins(seg::rt[u],1,m,id);
		//	printf("%d ",u);
		}
	//	printf("\n");
	}
	int get(int x,int y)
	{
		int l=y-x+1;x=p[y];
		for(int i=19;~i;--i)
			if(len[up[x][i]]>=l)x=up[x][i];
		return x;
	}
	void solve(int v)
	{
		for(auto u:E[v])
		{
			solve(u);
			seg::merge(seg::rt[v],seg::rt[u],1,m);
		}
		sort(Q[v].begin(),Q[v].end());
		sort(ad[v].begin(),ad[v].end());
		int last=ad[v].size()-1;
		for(int i=Q[v].size()-1;~i;--i)
		{
			while(last>=0&&ad[v][last].first>=Q[v][i].len)seg::ins(seg::rt[v],1,m,ad[v][last].second),--last;
			ans[Q[v][i].id]=seg::query(seg::rt[v],1,m,Q[v][i].l,Q[v][i].r);
		}
		while(last>=0)seg::ins(seg::rt[v],1,m,ad[v][last].second),--last;
	}
}
int main()
{
	scanf("%s",s+1);
	n=strlen(s+1);
	SAM::build();
	scanf("%d",&m);
	for(int i=1;i<=m;++i)
	{
		scanf("%s",a+1);
		SAM::run(i);
	}
	scanf("%d",&q);
	int x,y,xx,yy;
	for(int i=1;i<=q;++i)
	{
		scanf("%d %d %d %d",&x,&y,&xx,&yy);
	//	printf("%d\n",SAM::get(xx,yy));
		SAM::Q[SAM::get(xx,yy)].push_back(query{x,y,yy-xx+1,i});
	}
	SAM::solve(1);
	for(int i=1;i<=q;++i)printf("%d %d\n",ans[i].p,ans[i].mx);
	return 0;
}