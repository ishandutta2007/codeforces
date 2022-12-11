#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cctype>
using namespace std;
#define G getchar()
int read()
{
	int x=0; char ch=G;
	for (;!isdigit(ch);ch=G);
	for (;isdigit(ch);ch=G) x=(x<<3)+(x<<1)+(ch^48);
	return x;
}
#undef G
typedef long long ll;

int T,n,pos[300010],mrk[300010];
char s[300010],t[300010];
int nxt[300010];
namespace Trie{
	struct Node{
		int tot,fil,nxt[26];
	}node[4800010]; int idtot;
	void ins(int &rt,char *s,int len,int k)  //[0,len)
	{
		if (!rt) rt=++idtot;
		int cur=rt;
		for (int i=0,id;i<len;i++)
		{
			id=s[i]-'a';
			if (!node[cur].nxt[id]) node[cur].nxt[id]=++idtot;
			cur=node[cur].nxt[id];
		}
		node[cur].tot+=k;
	}
	int que[300010],hd,tl;
	inline int check(int cur,int rt)
	{
		if (cur) return cur; return rt;
	}
	void bfs(int rt)
	{
		hd=tl=0;
		for (int i=0;i<26;i++)
			if (node[rt].nxt[i]) que[++tl]=node[rt].nxt[i];
		while (hd<tl)
		{
			int u=que[++hd],v,c=check(node[u].fil,rt);
			for (int i=0;i<26;i++)
				if (node[u].nxt[i])
				{
					v=node[u].nxt[i];
					node[v].fil=node[c].nxt[i];
					que[++tl]=v;
				}
				else node[u].nxt[i]=node[c].nxt[i];
		}
		for (int i=1,u;i<=tl;i++) u=que[i],node[u].tot+=node[node[u].fil].tot;
	}
}
#define mid (l+r>>1)
#define lson (cur<<1)
#define rson (cur<<1|1)
struct Node{
	int rt;
}node[1048576];
ll query(int cur,int l,int r,int ql,int qr,int len)
{
	if (l==ql&&r==qr)
	{
		if (r-l<32)
		{
			int res=0;
			for (int u=l,st;u<=r;u++)
			{
				st=(u?pos[u-1]:0);
				for (int i=0,j=st;i<len;i++)
				{
					for (;j!=st&&s[j+1]!=t[i];j=nxt[j]);
					if (s[j+1]==t[i]) {j++; if (j==pos[u]) res+=mrk[u],j=nxt[j];}
				}
			}
			return res;
		}
		ll res=0;
		for (int i=0,u=node[cur].rt;i<len;i++)
		{
			u=Trie::node[u].nxt[t[i]-'a'];
			if (!u) u=node[cur].rt;
			res+=Trie::node[u].tot;
		}
		return res;
	}
	if (qr<=mid) return query(lson,l,mid,ql,qr,len);
	if (ql>mid) return query(rson,mid+1,r,ql,qr,len);
	return query(lson,l,mid,ql,mid,len)+query(rson,mid+1,r,mid+1,qr,len);
}
#undef mid
#undef lson
#undef rson
int main()
{
	T=read();
	while (T--)
	{
		int opt=read();
		if (opt<=2)
		{
			mrk[n]=(opt==1?1:-1);
			char *str; int len;
			if (!n) scanf("%s",str=s+1),pos[n]=len=strlen(str);
			else scanf("%s",str=s+pos[n-1]+1),pos[n]=pos[n-1]+(len=strlen(str));
			
			int st=(n?pos[n-1]:0);
			nxt[st+1]=st;
			for (int i=st+2,j;i<=pos[n];i++)
			{
				for (j=nxt[i-1];j!=st&&s[j+1]!=s[i];j=nxt[j]);
				if (s[j+1]==s[i]) nxt[i]=j+1;
				else nxt[i]=st;
			}
			
			int cur=1; for (int i=18;i>=0;i--) cur=cur<<1|((n>>i)&1);
			for (int i=6;i<=19;i++) Trie::ins(node[cur>>i].rt,str,len,mrk[n]);
			if ((n&31)==31) for (int i=6;i<=19&&((n>>i-1)&1);i++) Trie::bfs(node[cur>>i].rt);
			n++;
			continue;
		}
		scanf("%s",t); int L=strlen(t);
		printf("%lld\n",n?query(1,0,524287,0,n-1,L):0LL);
		fflush(stdout);
	}
	return 0;
}