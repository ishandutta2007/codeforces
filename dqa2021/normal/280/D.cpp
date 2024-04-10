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
#undef G

int n,m;
#define mid (l+r>>1)
#define lson (cur<<1)
#define rson (cur<<1|1)
struct Rec{
	int l,r,sum;
};
Rec operator+(Rec x,Rec y){return (Rec){x.l,y.r,x.sum+y.sum};}
bool operator<(Rec x,Rec y){return x.sum<y.sum;}
void rev(Rec &x){x.sum=-x.sum;}
struct Node{
	Rec maxtot,mintot,maxpre,minpre,maxsuf,minsuf,sum;
	bool rev;
}node[262144];  //50MB
void pushdown(int cur)
{
	if (!node[cur].rev) return;
	Node &x=node[lson],&y=node[rson];
	swap(x.maxtot,x.mintot); rev(x.maxtot); rev(x.mintot);
	swap(x.minpre,x.maxpre); rev(x.minpre); rev(x.maxpre);
	swap(x.minsuf,x.maxsuf); rev(x.minsuf); rev(x.maxsuf);
	rev(x.sum); x.rev^=1;
	swap(y.maxtot,y.mintot); rev(y.maxtot); rev(y.mintot);
	swap(y.minpre,y.maxpre); rev(y.minpre); rev(y.maxpre);
	swap(y.minsuf,y.maxsuf); rev(y.minsuf); rev(y.maxsuf);
	rev(y.sum); y.rev^=1;
	node[cur].rev=0;
}
void pushup(int cur)
{
	Node &x=node[lson],&y=node[rson];
	node[cur]=(Node){max(max(x.maxtot,y.maxtot),x.maxsuf+y.maxpre),
					 min(min(x.mintot,y.mintot),x.minsuf+y.minpre),
					 max(x.maxpre,x.sum+y.maxpre),
					 min(x.minpre,x.sum+y.minpre),
					 max(y.maxsuf,x.maxsuf+y.sum),
					 min(y.minsuf,x.minsuf+y.sum),
					 x.sum+y.sum,0};
}
void build(int cur,int l,int r)
{
	if (l==r){
		Rec t=(Rec){l,r,read()};
		node[cur]=(Node){t,t,t,t,t,t,t,0};
		return;
	}
	build(lson,l,mid); build(rson,mid+1,r);
	pushup(cur);
}
void modify(int cur,int l,int r,int pos)
{
	if (l==r){
		Rec t=(Rec){l,r,read()};
		node[cur]=(Node){t,t,t,t,t,t,t,0};
		return;
	}
	pushdown(cur);
	if (pos<=mid) modify(lson,l,mid,pos);
	else modify(rson,mid+1,r,pos);
	pushup(cur);
}
void reverse(int cur,int l,int r,int ql,int qr)
{
	if (l==ql&&r==qr){
		#define x node[cur]
		swap(x.maxtot,x.mintot); rev(x.maxtot); rev(x.mintot);
		swap(x.minpre,x.maxpre); rev(x.minpre); rev(x.maxpre);
		swap(x.minsuf,x.maxsuf); rev(x.minsuf); rev(x.maxsuf);
		rev(x.sum); x.rev^=1;
		#undef x
		return;
	}
	pushdown(cur);
	if (qr<=mid) reverse(lson,l,mid,ql,qr);
	else if (ql>mid) reverse(rson,mid+1,r,ql,qr);
	else reverse(lson,l,mid,ql,mid),reverse(rson,mid+1,r,mid+1,qr);
	pushup(cur);
}
Node query(int cur,int l,int r,int ql,int qr)
{
	if (l==ql&&r==qr) return node[cur];
	pushdown(cur);
	if (qr<=mid) return query(lson,l,mid,ql,qr);
	if (ql>mid) return query(rson,mid+1,r,ql,qr);
	Node x=query(lson,l,mid,ql,mid),y=query(rson,mid+1,r,mid+1,qr);
	return (Node){max(max(x.maxtot,y.maxtot),x.maxsuf+y.maxpre),
					 min(min(x.mintot,y.mintot),x.minsuf+y.minpre),
					 max(x.maxpre,x.sum+y.maxpre),
					 min(x.minpre,x.sum+y.minpre),
					 max(y.maxsuf,x.maxsuf+y.sum),
					 min(y.minsuf,x.minsuf+y.sum),
					 x.sum+y.sum,0};
}
#undef mid
#undef lson
#undef rson
Node bin[30]; int bintop;

int main()
{
	n=read(); build(1,1,n);
	m=read();
	while (m--)
	{
		if (!read()) modify(1,1,n,read());
		else{
			int ans=0,l=read(),r=read(),k=read(); bintop=0;
			for(int i=1;i<=k;i++)
			{
				bin[++bintop]=query(1,1,n,l,r);
				if (bin[bintop].maxtot.sum<=0){--bintop;break;}
				ans+=bin[bintop].maxtot.sum;
//				printf("get %d %d %d\n",bin[bintop].maxtot.l,bin[bintop].maxtot.r,bin[bintop].maxtot.sum);
				reverse(1,1,n,bin[bintop].maxtot.l,bin[bintop].maxtot.r);
			}
			printf("%d\n",ans);
			for (int i=bintop;i;i--) reverse(1,1,n,bin[i].maxtot.l,bin[i].maxtot.r);
		}
	}
	return 0;
}