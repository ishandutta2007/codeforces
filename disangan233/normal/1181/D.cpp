#include<bits/stdc++.h>
#define inf 1e9
#define eps 1e-6
#define N 500010
using namespace std;
#define re register int
#define int long long
#define gc() getchar()
#define ak *
#define in inline
#define ls(x) t[x].ch[0]
#define rs(x) t[x].ch[1]
char qwq;
in int read()
{
    int cz=0,ioi=1;qwq=gc();
    while(qwq<'0'||qwq>'9') ioi=qwq=='-'?~ioi+1:1,qwq=gc();
    while(qwq>='0'&&qwq<='9') cz=(cz<<3)+(cz<<1)+(qwq^48),qwq=gc();
    return cz ak ioi;
}
int tot,c,pos=1,C;
struct node {int val;int id;} v[N];
int n,m,q,val[N],hmha;
struct treap{int size,ch[2],val,key;}t[N];
struct ask{int woc,id;}qr[N];
int ans[N],rt,len;
in void pushup(int x) {t[x].size=t[ls(x)].size+t[rs(x)].size+1;}
in void rotate(int &now,int opt)
{
	int x=t[now].ch[opt];
	t[now].ch[opt]=t[x].ch[opt^1];
	t[x].ch[opt^1]=now;
	pushup(now);
	pushup(x);
	now=x;
}
void insert(int val,int &now)
{
	if(!now)
	{
		tot++;now=++len;
		ls(len)=rs(len)=0;
		t[len].size=1;
		t[len].val=val;
		t[len].key=rand();
	}
	else if(val>=t[now].val)
	{
		insert(val,t[now].ch[1]);
		pushup(now);
		int r=t[now].ch[1];
		if(t[r].key>t[now].key)
		{
			rotate(now,1);
			pushup(now);
		}
	}
	else 
	{
		insert(val,t[now].ch[0]);
		pushup(now);
		int l=t[now].ch[0];
		if(t[l].key>t[now].key)
		{	
			rotate(now,0);
			pushup(now);
		}
	}
}
int query(int now,int k)
{
	if(t[now].size<k) return 0;
	if(t[t[now].ch[0]].size+1==k) return t[now].val;
	else if(t[t[now].ch[0]].size>=k) return query(t[now].ch[0],k);
	return query(t[now].ch[1],k-t[t[now].ch[0]].size-1);
}
in void clear()
{
	int P=pos;C+=tot*c;
	insert(v[pos].id,rt);
	pos=m+1;
	for(re i=P+1;i<=m;i++)
	{
		if(t[i].val!=t[P].val)
		{
			pos=i;
			c=v[i].val-v[P].val;
			break;
		}
		else insert(v[i].id,rt);
	}
	if(pos==m+1) hmha=1;
}
in int cmpq(ask x,ask y) 
{
	return x.woc<y.woc;
}
in int cmp(node p,node q) 
{
	if(p.val==q.val) return p.id<q.id;
	else return p.val<q.val;
}
signed main()
{
	n=C=read(),m=read(),q=read();
	for(re i=1;i<=n;i++) val[read()]++;
	for(re i=1;i<=q;i++) qr[i].woc=read(),qr[i].id=i;
	sort(qr+1,qr+q+1,cmpq);
	for(re i=1;i<=m;i++) v[i].val=val[i],v[i].id=i;
	sort(v+1,v+m+1,cmp);
	clear();
	for(re i=1;i<=q;i++)
	{
		if(hmha) ans[qr[i].id]=query(rt,(qr[i].woc-C-1)%tot+1);
		else
		{
			while((qr[i].woc-C)>tot*c&&!hmha) clear();
			ans[qr[i].id]=query(rt,(qr[i].woc-C-1)%tot+1);
		}
	}
	for(re i=1;i<=q;i++) printf("%lld\n",ans[i]);
	return 0;
}