
#include<cstdio>
#include<algorithm>
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

int n,m,p;
struct Rec{
	int opt,x,y,z;  //A:{0,val,cost}  C:{1,val1,val2,cost}
}rec[400010]; int rectop;
bool operator<(const Rec x,const Rec y){
	if (x.x^y.x) return x.x<y.x;
	return x.opt>y.opt;
}
struct B{
	int val,fee;
}b[200010];
bool operator<(B x,B y){
	return x.val<y.val;
} 
#define lson (cur<<1)
#define rson (cur<<1|1)
#define mid (l+r>>1)
struct Node{
	ll tag,maxn;
}node[524288];
void pushdown(int cur){
	if (!node[cur].tag) return;
	node[lson].tag+=node[cur].tag;
	node[lson].maxn+=node[cur].tag;
	node[rson].tag+=node[cur].tag;
	node[rson].maxn+=node[cur].tag;
	node[cur].tag=0;
}
void pushup(int cur){
	node[cur].maxn=max(node[lson].maxn,node[rson].maxn);
}
void build(int cur,int l,int r){
	if (l==r) return node[cur]=(Node){0,-b[l].fee},void();
	build(lson,l,mid); build(rson,mid+1,r);
	pushup(cur);
}
void update(int cur,int l,int r,int ql,int qr,int val){
	if (l==ql&&r==qr){
		node[cur].tag+=val;
		node[cur].maxn+=val;
		return;
	}
	pushdown(cur);
	if (qr<=mid) update(lson,l,mid,ql,qr,val);
	else if(ql>mid) update(rson,mid+1,r,ql,qr,val);
	else update(lson,l,mid,ql,mid,val),update(rson,mid+1,r,mid+1,qr,val);
	pushup(cur);
}
#undef lson
#undef rson
#undef mid
int main()
{
	n=read(),m=read(),p=read();
	for(int i=1,x,y;i<=n;i++){
		x=read()-1,y=read();
		rec[++rectop]=(Rec){0,x,y,0}; 
	}
	for (int i=1,x,y;i<=m;i++){
		x=read()-1,y=read();
		b[i]=(B){x,y};
	}
	for (int i=1,x,y,z;i<=p;i++){
		x=read(),y=read(),z=read();
		rec[++rectop]=(Rec){1,x,y,z};
	}
	sort(rec+1,rec+rectop+1); sort(b+1,b+m+1);
	build(1,1,m);
	ll ans=-1e18;
	for (int i=1;i<=rectop;i++){
		if (rec[i].opt==1){
			if (rec[i].y>b[m].val) continue;
			int l=1,r=m,mid;
			while (l<r){
				mid=l+r>>1;
				if (rec[i].y<=b[mid].val) r=mid;
				else l=mid+1;
			}
			update(1,1,m,l,m,rec[i].z);
			continue;
		}
//		printf("check %d  %d\n",-rec[i].y,node[1].maxn);
		ans=max(ans,0LL-rec[i].y+node[1].maxn);
	}
	printf("%I64d\n",ans);
	return 0;
}