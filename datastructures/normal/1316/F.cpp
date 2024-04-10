#include <iostream>
#include <cstdio>
#include <ctime>
#include <random>
#define mod 1000000007
#define ll long long
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
int n,p[300005],q,x,y;
ll pow_2[300005],pow_inv2[300005];
mt19937 rnd(time(NULL));
struct fhq_node{
	int l,r,key,sz;
	ll val,lsum,rsum,ans;
	fhq_node(){
		l=r=key=sz=val=lsum=rsum=ans=0;
		return;
	}
}fhq[600005];
int cnt,root;
fhq_node new_node(int val){
	fhq_node ans;
	ans.l=ans.r=0;
	ans.key=rnd()%1000000000;
	ans.sz=1;
	ans.val=ans.lsum=ans.rsum=val;
	ans.ans=0;
	return ans; 
}
void pushup(int now){
	fhq[now].sz=fhq[fhq[now].l].sz+fhq[fhq[now].r].sz+1;
	fhq[now].lsum=(fhq[fhq[now].l].lsum+fhq[fhq[now].r].lsum*pow_2[fhq[fhq[now].l].sz+1]+fhq[now].val*pow_2[fhq[fhq[now].l].sz])%mod;
	fhq[now].rsum=(fhq[fhq[now].r].rsum+fhq[fhq[now].l].rsum*pow_2[fhq[fhq[now].r].sz+1]+fhq[now].val*pow_2[fhq[fhq[now].r].sz])%mod;
	fhq[now].ans=(fhq[fhq[now].l].ans*pow_2[fhq[fhq[now].r].sz+1]+fhq[fhq[now].r].ans*pow_2[fhq[fhq[now].l].sz+1]+fhq[fhq[now].l].lsum*fhq[fhq[now].r].rsum+fhq[now].val*fhq[fhq[now].l].lsum%mod*pow_2[fhq[fhq[now].r].sz]+fhq[now].val*fhq[fhq[now].r].rsum%mod*pow_2[fhq[fhq[now].l].sz])%mod;
	return;
}
int merge(int x,int y){
	if (x==0)return y;
	if (y==0)return x;
	if (fhq[x].key>fhq[y].key){
		fhq[x].r=merge(fhq[x].r,y);
		pushup(x);
		return x;
	} 
	else{
		fhq[y].l=merge(x,fhq[y].l);
		pushup(y);
		return y;
	}
	return 0;
}
void split(int now,int val,int &x,int &y){
	if (now==0){
		x=y=0;
		return;
	}
	if (fhq[now].val<=val){
		x=now;
		split(fhq[now].r,val,fhq[now].r,y);
	}
	else{
		y=now;
		split(fhq[now].l,val,x,fhq[now].l);
	}
	pushup(now); 
	return;
}
void ins(int val){
	int x,y;
	split(root,val,x,y);
	++cnt;
	fhq[cnt]=new_node(val);
	root=merge(merge(x,cnt),y);
	return;
}
void del(int val){
	int x,y,z;
	split(root,val,y,z);
	split(y,val-1,x,y);
	y=merge(fhq[y].l,fhq[y].r);
	y=merge(y,z);
	root=merge(x,y);
	return;
}
int main(){
	cin>>n;
	pow_2[0]=1;
	for (int i=1;i<=n;i++)pow_2[i]=pow_2[i-1]*2%mod; 
	pow_inv2[0]=1;
	for (int i=1;i<=n;i++)pow_inv2[i]=pow_inv2[i-1]*(mod+1)/2%mod;
	for (int i=1;i<=n;i++)p[i]=read(),ins(p[i]);
	cout<<fhq[root].ans*pow_inv2[n]%mod<<endl;
	cin>>q;
	while(q--){
		x=read(),y=read();
		del(p[x]);
		p[x]=y;
		ins(p[x]);
		write(fhq[root].ans*pow_inv2[n]%mod);
	}
	return 0;
}