#include <iostream>
#include <cstdio>
#include <cstring>
#define int long long
#define maxV 1000000
using namespace std;
int read(){
	int x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
	return x;
}
void write(int x){
	if (x<0)putchar('-'),x=-x;
	if (x<10){
		putchar('0'+x);
		return;
	}
	write(x/10);
	putchar('0'+x%10);
	return;
}
struct BIT{
	int tree[2097152],maxn;
	BIT(){
		memset(tree,0,sizeof(tree));
		maxn=2097151;
		return;
	}
	int lowbit(int x){
		return x&(-x);
	}
	void add(int pos,int val){
		pos++;
		while(pos<=maxn)tree[pos]+=val,pos+=lowbit(pos);
		return;
	}
	int ask(int pos){
		if (pos<0)return 0;
		pos++;
		int ans=0;
		while(pos)ans+=tree[pos],pos-=lowbit(pos);
		return ans;
	}
	int kth(int x){
		int pos=0;
		for (int i=20;i>=0;i--)
			if (x>tree[pos+(1<<i)])x-=tree[pos+(1<<i)],pos+=(1<<i);
		return pos;
	}
	int pre(int x){
		int t=ask(x);
		if (t==0)return -1;
		return kth(t);
	}
	int nxt(int x){
		int t=ask(x);
		return kth(t+1);
	}
}a0,b0,a1,b1;
int n,m,q,a[200005],b[200005];
int suma,sumb;
int opt,x,y,mn;
int aska(int x,int k){
	int ans=suma+n*(k-x);
	if (x-mn-k>0)ans+=(n-1)*(x-mn-k);
	ans-=(sumb-b1.ask(x-k))+(m-b0.ask(x-k))*(k-x);
	return ans;
}
int askb(int x,int k){
	int ans=suma+n*(k-x);
	if (x-mn-k>0)ans+=n*(x-mn-k);
	ans-=(sumb-b1.ask(x-k))+(m-b0.ask(x-k))*(k-x);
	return ans;
}
signed main(){
	n=read(),m=read(),q=read();
	for (int i=1;i<=n;i++){
		a[i]=read();
		suma+=a[i];
		a0.add(a[i],1);
		a1.add(a[i],a[i]);
	}
	for (int i=1;i<=m;i++){
		b[i]=read();
		sumb+=b[i];
		b0.add(b[i],1);
		b1.add(b[i],b[i]);
	}
	while(q--){
		opt=read();
		if (opt==1){
			x=read(),y=read();
			suma-=a[x];
			a0.add(a[x],-1);
			a1.add(a[x],-a[x]);
			a[x]=y;
			suma+=a[x];
			a0.add(a[x],1);
			a1.add(a[x],a[x]);
		}
		if (opt==2){
			x=read(),y=read();
			sumb-=b[x];
			b0.add(b[x],-1);
			b1.add(b[x],-b[x]);
			b[x]=y;
			sumb+=b[x];
			b0.add(b[x],1);
			b1.add(b[x],b[x]);
		}
		if (opt==3){
			mn=min(a0.kth(1),b0.kth(1));
			x=read();
			int ans=-1e18;
			if (m<=n)ans=max(ans,max(aska(a0.kth(1),x),askb(b0.kth(1),x)));
			else{
				int val=b0.kth(m-n)+x;
				if (a0.pre(val)!=-1)ans=max(ans,aska(a0.pre(val),x));
				if (a0.nxt(val)<=maxV)ans=max(ans,aska(a0.nxt(val),x));
				if (b0.pre(val)!=-1)ans=max(ans,askb(b0.pre(val),x));
				if (b0.nxt(val)<=maxV)ans=max(ans,askb(b0.nxt(val),x));
			}
			int val=b0.kth(m)+x;
			if (a0.pre(val)!=-1)ans=max(ans,aska(a0.pre(val),x));
			if (a0.nxt(val)<=maxV)ans=max(ans,aska(a0.nxt(val),x));
			if (b0.pre(val)!=-1)ans=max(ans,askb(b0.pre(val),x));
			if (b0.nxt(val)<=maxV)ans=max(ans,askb(b0.nxt(val),x));
			write(ans);
			putchar('\n');
		}
	}
	return 0;
}
//mod zjf