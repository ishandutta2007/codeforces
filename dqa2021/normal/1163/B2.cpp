#include<cstdio>
#include<algorithm>
#include<cctype>
#include<queue>
using namespace std;
#define G getchar()
int read()
{
	int x=0; bool flg=false; char ch=G;
	for (;!isdigit(ch);ch=G) if (ch=='-') flg=true;
	for (;isdigit(ch);ch=G) x=(x<<3)+(x<<1)+(ch^48);
	if (flg) x=-x;
	return x;
}

int n,w[100010];
int c[100010];
int cc[100010];
#define lson (cur<<1)
#define rson (cur<<1|1)
#define mid (l+r>>1)
struct Node{
	int val;
}node[400010];
void update(int cur,int l,int r,int pos,int val)
{
	node[cur].val+=val;
	if (l==r) return;
	if (pos<=mid) update(lson,l,mid,pos,val);
	else update(rson,mid+1,r,pos,val);
}
int rec[10]; //(*rec)=0
void query(int cur,int l,int r)
{
	if (!node[cur].val) return;
	if (l==r) return rec[++*rec]=l,void();
	query(lson,l,mid); query(rson,mid+1,r);
}

int ans;
int main()
{
	bool all1=true;
	n=read();
	for (int i=1;i<=n;i++)
	{
		w[i]=read(); int x=w[i];
		if (i!=1&&w[i]!=w[1]) all1=false;
		if (!c[x])
		{
			if (cc[1])
			{
				cc[++c[x]]++;
			if (node[1].val>2) continue;
			(*rec)=0; query(1,1,100000);
			if (all1||node[1].val==1&&rec[1]==1||node[1].val==2&&(rec[1]==1&&cc[rec[1]]==1||rec[2]==rec[1]+1&&cc[rec[2]]==1)) ans=i;		
				continue;
			}
			update(1,1,100000,1,1);
			cc[++c[x]]++;
			if (node[1].val>2) continue;
			(*rec)=0; query(1,1,100000);
			if (all1||node[1].val==1&&rec[1]==1||node[1].val==2&&(rec[1]==1&&cc[rec[1]]==1||rec[2]==rec[1]+1&&cc[rec[2]]==1)) ans=i;			
			continue;
		}
		if (cc[c[x]]==1) update(1,1,100000,c[x],-1),cc[c[x]]--;
		else cc[c[x]]--;
		c[x]++;
		if (!cc[c[x]]) update(1,1,100000,c[x],1),cc[c[x]]++;
		else cc[c[x]]++;
			if (node[1].val>2) continue;
			(*rec)=0; query(1,1,100000);
			if (all1||node[1].val==1&&rec[1]==1||node[1].val==2&&(rec[1]==1&&cc[rec[1]]==1||rec[2]==rec[1]+1&&cc[rec[2]]==1)) ans=i;	
	}
	printf("%d\n",ans);
	return 0;
}