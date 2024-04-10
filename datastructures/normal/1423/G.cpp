#include <iostream>
#include <cstdio>
#include <set>
#include <cstring>
#define int long long
#define maxn 200000
using namespace std;
int read(){
	int x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
	return x;
}
void write_num(int x){
	if (x==0)return;
	write_num(x/10);
	putchar('0'+x%10);
	return; 
}
void write(int x){
	if (x==0)putchar('0');
	else write_num(x);
	puts("");
	return;
}
struct BIT{
	int tree[200005];
	BIT(){
		memset(tree,0,sizeof(tree));
		return;
	}
	int lowbit(int x){
		return x&(-x);
	}
	void add(int pos,int val){
		while(pos<=maxn)tree[pos]+=val,pos+=lowbit(pos);
		return;
	}
	int ask(int pos){
		int ans=0;
		while(pos)ans+=tree[pos],pos-=lowbit(pos);
		return ans;
	}
}bit1,bit2;
void ins(int len){
	bit1.add(maxn-len+1,1);
	bit2.add(maxn-len+1,len);
	return;
}
void del(int len){
	bit1.add(maxn-len+1,-1);
	bit2.add(maxn-len+1,-len);
	return;
}
int ask(int len){
	return bit2.ask(maxn-len+1)-(len-1)*bit1.ask(maxn-len+1);
}
struct seg{
	int col,l,r;
	seg(){
		col=l=r=0;
		return;
	}
	bool operator <(const seg &x)const{
		return l<x.l;
	}
};
seg make_seg(int col,int l,int r){
	seg ans;
	ans.col=col,ans.l=l,ans.r=r;
	return ans;
}
set<seg> c[100005],d;
seg pre(int col,int l,int r){
	seg now=make_seg(col,l,r);
	set<seg>::iterator it=c[col].lower_bound(now);
	it--;
	return (*it);
}
seg nxt(int col,int l,int r){
	seg now=make_seg(col,l,r);
	set<seg>::iterator it=c[col].upper_bound(now);
	return (*it); 
}
void set_ins(int col,int l,int r){
	seg now=make_seg(col,l,r);
	seg x=pre(col,l,r),y=nxt(col,l,r);
	del(y.l-x.r-1);
	ins(now.l-x.r-1);
	ins(y.l-now.r-1);
	c[col].insert(now);
	d.insert(now);
	return;
}
void set_del(int col,int l,int r){
	seg now=make_seg(col,l,r);
	seg x=pre(col,l,r),y=nxt(col,l,r);
	del(now.l-x.r-1);
	del(y.l-now.r-1);
	ins(y.l-x.r-1);
	c[col].erase(now);
	d.erase(now);
	return;
}
void cover(int col,int l,int r){
	seg now=make_seg(col,l,r);
	set<seg>::iterator it=d.lower_bound(now);
	while((*it).r>=l)it--;
	it++;
	while((*it).l<=r){
		set<seg>::iterator _it=it;
		_it++;
		seg now=(*it);
		set_del(now.col,now.l,now.r);
		if (now.l<l)set_ins(now.col,now.l,l-1);
		if (now.r>r)set_ins(now.col,r+1,now.r);
		it=_it;
	}
	set_ins(col,l,r);
	return;
}
int n,m,a[100005],opt,l,r,x;
signed main(){
	n=read(),m=read();
	for (int i=1;i<=100000;i++){
		c[i].insert(make_seg(i,0,0));
		c[i].insert(make_seg(i,n+1,n+1));
		ins(n);
	}
	d.insert(make_seg(0,0,0));
	d.insert(make_seg(0,n+1,n+1));
	for (int i=1;i<=n;i++){
		a[i]=read();
		set_ins(a[i],i,i);
	}
	for (int i=1;i<=m;i++){
		opt=read();
		if (opt==1){
			l=read(),r=read(),x=read();
			cover(x,l,r);
		}
		if (opt==2){
			x=read();
			write((n-x+1)*100000-ask(x));
		}
	}
	return 0;
}