#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define inf 1000000000
#define mod 998244353
#define maxn 500000
using namespace std;
int n,a[500005],b[500005];
int l[2],c[2][500005];
int fac[500005],invfac[500005];
int mx,ans;
int book[500005],awa[2][500005];
int Qpow(int a,int p){
	if (p==0)return 1;
	int t=Qpow(a,p/2);
	t=1ll*t*t%mod;
	if (p&1)t=1ll*t*a%mod;
	return t;
}
int C(int n,int m){
	if (m>n||m<0)return 0;
	return 1ll*fac[n]*invfac[m]%mod*invfac[n-m]%mod;
}
struct BIT{
	int tree[500005];
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
}bit;
int tree[2000005],tag[2000005];
void pushup(int now){
	tree[now]=max(tree[now*2],tree[now*2+1]);
	return;
}
void pushdown(int now){
	tree[now*2]+=tag[now],tag[now*2]+=tag[now];
	tree[now*2+1]+=tag[now],tag[now*2+1]+=tag[now];
	tag[now]=0;
	return;
}
void upd(int now,int nowl,int nowr,int lt,int rt,int val){
	if (nowl!=nowr)pushdown(now);
	if (nowl>=lt&&nowr<=rt){
		tree[now]+=val;
		tag[now]+=val;
		return;
	}
	int mid=(nowl+nowr)/2;
	if (mid>=lt)upd(now*2,nowl,mid,lt,rt,val);
	if (mid+1<=rt)upd(now*2+1,mid+1,nowr,lt,rt,val);
	pushup(now);
	return;
}
int find(int now,int nowl,int nowr){
	if (nowl!=nowr)pushdown(now);
	if (nowl==nowr)return nowl;
	int mid=(nowl+nowr)/2;
	if (tree[now*2+1]>=tree[now*2])return find(now*2+1,mid+1,nowr);
	return find(now*2,nowl,mid);
}
int main(){
	cin>>n;
	int fg=1;
	for (int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if (i>1&&a[i]!=a[1])fg=0;
	}
	for (int i=1;i<=n;i++){
		scanf("%d",&b[i]);
		c[b[i]][++l[b[i]]]=a[i];
	}
	fac[0]=1;
	for (int i=1;i<=n;i++)fac[i]=1ll*fac[i-1]*i%mod;
	invfac[n]=Qpow(fac[n],mod-2);
	for (int i=n-1;i>=0;i--)invfac[i]=1ll*invfac[i+1]*(i+1)%mod;
	if (fg==1){
		cout<<fac[n]<<endl;
		return 0;
	}
	sort(c[0]+1,c[0]+1+l[0]);
	sort(c[1]+1,c[1]+1+l[1]);
	if (l[1]==0){
		cout<<0<<endl;
		return 0;
	}
	mx=c[1][1]+n-1;
	int cnt=0;
	while(c[1][l[1]]==mx)cnt++,l[1]--;
	ans=1ll*C(n,cnt)*fac[cnt]%mod;
	fg=1;
	for (int i=1;i<=l[1];i++){
		if (i>1&&c[1][i]==c[1][i-1]){
			fg=0;
			break;
		}
		book[c[1][i]]=1;
	}
	if (fg==0){
		cout<<0<<endl;
		return 0;
	}
	for (int i=1;i<=n;i++){
		bit.add(a[i],1);
		if (a[i]>1)upd(1,1,maxn,1,a[i]-1,1);
	}
	for (int i=1;i<=2*n;i++)
		if (book[i]==0)upd(1,1,maxn,i,i,-inf);
		else upd(1,1,maxn,i,i,i);
	int p0=1;
	while(p0<=l[0]||tree[1]>0){
		int f0=0,f1=0;
		if (p0<=l[0]&&c[0][p0]+bit.ask(c[0][p0]-1)==mx)f0=1;
		if (tree[1]==mx)f1=1;
		if (f0==0&&f1==0){
			fg=0;
			break;
		}
		if (f0==1&&f1==1){
			if (c[0][p0]<=find(1,1,maxn)){
				int val=find(1,1,maxn);
				bit.add(val,-1);
				bit.add(mx,1);
				upd(1,1,maxn,val,val,-inf);
				if (val>1)upd(1,1,maxn,1,val-1,-1);
				upd(1,1,maxn,1,mx-1,1);
			}
			else{
				bit.add(c[0][p0],-1);
				bit.add(mx,1);
				if (c[0][p0]>1)upd(1,1,maxn,1,c[0][p0]-1,-1);
				upd(1,1,maxn,1,mx-1,1);
				p0++,cnt++;
			}
		}
		else if (f0==1){
			bit.add(c[0][p0],-1);
			bit.add(mx,1);
			if (c[0][p0]>1)upd(1,1,maxn,1,c[0][p0]-1,-1);
			upd(1,1,maxn,1,mx-1,1);
			p0++,cnt++;
		}
		else{
			int val=find(1,1,maxn);
			bit.add(val,-1);
			bit.add(mx,1);
			upd(1,1,maxn,val,val,-inf);
			if (val>1)upd(1,1,maxn,1,val-1,-1);
			upd(1,1,maxn,1,mx-1,1);
		}
	}
	for (int i=1;i<=n;i++)awa[b[i]][a[i]]++;
	for (int i=1;i<=2*n;i++)ans=1ll*ans*fac[awa[0][i]]%mod;
	if (fg==0)cout<<0<<endl;
	else cout<<ans<<endl;
	return 0;
}