#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=4e5+50,M=3e7+50;
int n,cnt,c[N],m,f[N];
struct node{
	int a,b,c,d;
	void init(){scanf("%d%d%d%d",&a,&b,&c,&d);}
	bool friend operator <(node a,node b){return a.b<b.b;}
}a[N];
struct T{
	int sum[M],lc[M],rc[M],rt[N];
	void change(int &x,int l,int r,int p){
		if(!x)x=++cnt;sum[x]++;
		if(l==r)return;int mid=(l+r)>>1;
		if(p<=mid)change(lc[x],l,mid,p);
		else change(rc[x],mid+1,r,p);
	}
	int query(int x,int l,int r,int ql,int qr){
		if(!x||l>qr||r<ql)return 0;
		if(l>=ql&&r<=qr)return sum[x];
		int mid=(l+r)>>1;
		return query(lc[x],l,mid,ql,qr)+query(rc[x],mid+1,r,ql,qr);
	}
	void add(int x,int y){
		// cout<<y<<endl;
		for(;x<=m;x+=x&-x)change(rt[x],1,m,y);
	}
	int ask(int x,int l,int r){
		if(l>r)return 0;
		int ret=0;//cout<<l<<"---"<<r<<endl;
		for(;x;x-=x&-x)ret+=query(rt[x],1,m,l,r);
		return ret;
	}
	void clear(){
		memset(sum,0,sizeof(sum));
		memset(lc,0,sizeof(lc));
		memset(rc,0,sizeof(rc));
		memset(rt,0,sizeof(rt));
		cnt=0;
	}
}T1,T2;
void add(int x){for(;x<=m;x+=x&-x)f[x]++;}
int ask(int x){int y=0;for(;x;x-=x&-x)y+=f[x];return y;}
int get(int x){return lower_bound(c+1,c+m+1,x)-c;}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)a[i].init(),
		c[i]=a[i].a,c[i+n]=a[i].b,c[i+2*n]=a[i].c,c[i+3*n]=a[i].d;
	sort(c+1,c+4*n+1);m=unique(c+1,c+4*n+1)-c-1;
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		a[i].a=get(a[i].a);a[i].b=get(a[i].b);
		a[i].c=get(a[i].c);a[i].d=get(a[i].d);
		T1.add(a[i].b,a[i].c);
		T2.add(a[i].b,a[i].d);//cout<<a[i].c-1<<endl;
		int dd=T1.ask(a[i].a-1,a[i].d+1,m)+T2.ask(a[i].a-1,1,a[i].c-1);
		// cout<<dd<<" "<<ask(a[i].a-1)<<endl;
		if(dd!=ask(a[i].a-1))puts("NO"),exit(0);
		add(a[i].b);
	}
	T1.clear();T2.clear();memset(f,0,sizeof(f));
	for(int i=1;i<=n;i++)
		swap(a[i].a,a[i].c),swap(a[i].b,a[i].d);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		T1.add(a[i].b,a[i].c);
		T2.add(a[i].b,a[i].d);//cout<<a[i].c-1<<endl;
		int dd=T1.ask(a[i].a-1,a[i].d+1,m)+T2.ask(a[i].a-1,1,a[i].c-1);
		// cout<<dd<<" "<<ask(a[i].a-1)<<endl;
		if(dd!=ask(a[i].a-1))puts("NO"),exit(0);
		add(a[i].b);
	}
	puts("YES");
	return 0;
}