#include<cstdio>
#include<algorithm>
#define int long long
using namespace std;
int n,m,cnt,len[200010],a[200010],b[200010];
struct node{
	int lson,rson,l,r,sum;
}p[6000010];
int build(int l,int r){
	int pos=++cnt;
	p[pos].l=l;
	p[pos].r=r;
	if(l==r) return pos;
	int mid=(l+r)>>1;
	p[pos].lson=build(l,mid);
	p[pos].rson=build(mid+1,r);
	return pos;
}
void insert(int x,int &node,int k){
	node=++cnt;
	p[node]=p[x];
	p[node].sum++;
	if(p[node].l==p[node].r) return;
	int mid=(p[node].l+p[node].r)>>1;
	if(mid>=k) insert(p[x].lson,p[node].lson,k);
	else insert(p[x].rson,p[node].rson,k);
}
int query(int k,int x,int y){
    if(y<x) return 0;
    if(!k) return 0;
	if(x<=p[k].l&&p[k].r<=y) return p[k].sum; 
    int mid=(p[k].l+p[k].r)/2,an=0;
    if(x<=mid) an+=query(p[k].lson,x,y);
    if(mid<y) an+=query(p[k].rson,x,y);
    return an;
}
int ask(int x0,int y0,int x1,int y1){
    return query(len[x1],1,y1)-query(len[x1],1,y0-1)-query(len[x0-1],1,y1)+query(len[x0-1],1,y0-1);
}
signed main(){
	scanf("%lld %lld",&n,&m);
    len[0]=build(1,n);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]),insert(len[i-1],len[i],a[i]);
    int x0,y0,x1,y1;
	while(m--){
        scanf("%lld %lld %lld %lld",&x0,&y0,&x1,&y1);
        if(x0>x1) swap(x0,x1);
        if(y0>y1) swap(y0,y1);
        int ans=n*(n-1)/2,val;
        val=x0-1;
        ans-=val*(val-1)/2;
        val=y0-1;
        ans-=val*(val-1)/2;
        val=n-x1;
        ans-=val*(val-1)/2;
        val=n-y1;
        ans-=val*(val-1)/2;
        val=ask(1,1,x0-1,y0-1);
        ans+=val*(val-1)/2;
        val=ask(1,y1+1,x0-1,n);
        ans+=val*(val-1)/2;
        val=ask(x1+1,1,n,y0-1);
        ans+=val*(val-1)/2;
        val=ask(x1+1,y1+1,n,n);
        ans+=val*(val-1)/2;
        printf("%lld\n",ans);
    }
	return 0;
}