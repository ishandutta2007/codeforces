#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define mod 1000000007
#define int long long
#define maxn 500000
using namespace std;
int read(){
	int x=0,fg=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if (ch=='-')fg=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
	return x*fg;
}
void write_num(int x){
	if (x==0)return;
	write_num(x/10);
	putchar('0'+x%10);
	return;
}
void write(int x){
	if (x<0)putchar('-'),x=-x;
	if (x==0)putchar('0');
	if (x>0)write_num(x);
	puts("");
	return;
}
void upd(int &x,int y){
	x+=y;
	if (x>=mod)x-=mod;
	return;
}
struct BIT{
	int tree[500005];
	void mem(){
		memset(tree,0,sizeof(tree));
		return;
	}
	int lowbit(int x){
		return x&(-x);
	}
	void add(int pos,int val){
		while(pos<=maxn)upd(tree[pos],val),pos+=lowbit(pos);
		return;
	}
	int ask(int l,int r){
		if (l>r)return 0;
		int ans=0;
		while(r)upd(ans,tree[r]),r-=lowbit(r);
		l--;
		while(l)upd(ans,mod-tree[l]),l-=lowbit(l);
		return ans;
	}
}bit1,bit2,bit3,bit4,bit5,bit6;
int n,m,p[200005],a[200005],sum[200005];
int _s[500005],tot;
int l[500005],r[500005];
vector<int> ql[200005],opt[200005],qid[200005];
int ans[200005];
int lower(int x){
	int l=1,r=tot,ans=0;
	while(l<=r){
		int mid=(l+r)/2;
		if (_s[mid]<=x)ans=mid,l=mid+1;
		else r=mid-1;
	}
	return ans;
}
signed main(){
	n=read(),m=read();
	for (int i=1;i<=n;i++)p[i]=read();
	for (int i=1;i<=n;i++){
		a[i]=read();
		sum[i]=sum[i-1]+a[i];
		_s[++tot]=sum[i-1];
		_s[++tot]=sum[i-1]+a[i];
	}
	sort(_s+1,_s+1+tot);
	for (int i=1;i<=m;i++){
		l[i]=read(),r[i]=read();
		ql[l[i]-1].push_back(l[i]),qid[l[i]-1].push_back(i);
		ql[r[i]].push_back(l[i]),qid[r[i]].push_back(i);
	}
	bit1.mem(),bit2.mem(),bit3.mem(),bit4.mem(),bit5.mem(),bit6.mem();
	for (int i=1;i<=n;i++){
		if (a[i]>0){
			int t=lower(sum[i-1]),r=lower(sum[i-1]+a[i]);
			bit1.add(t,p[i]),bit2.add(t,sum[i-1]%mod*p[i]%mod),bit3.add(t,a[i]*p[i]%mod);
			bit4.add(r,p[i]),bit5.add(r,sum[i-1]%mod*p[i]%mod),bit6.add(r,a[i]*p[i]%mod);
		}
		for (int j=0;j<(int)ql[i].size();j++){
			int l=ql[i][j];
			int t=lower(sum[l-1]);
			int qwq=-bit3.ask(t+1,maxn)+bit6.ask(1,t-1);
			qwq=(qwq+2*sum[l-1]%mod*bit1.ask(1,t)-2*bit2.ask(1,t)-bit3.ask(1,t)-2*sum[l-1]%mod*bit4.ask(1,t-1)+2*bit5.ask(1,t-1)+bit6.ask(1,t-1));
			qwq=(qwq%mod+mod)%mod;
			if (l>i)upd(ans[qid[i][j]],mod-qwq);
			else upd(ans[qid[i][j]],qwq);
		}
	}
	tot=0;
	for (int i=1;i<=n;i++){
		a[i]=-a[i];
		sum[i]=sum[i-1]+a[i];
		_s[++tot]=sum[i-1];
		_s[++tot]=sum[i-1]+a[i];
	}
	sort(_s+1,_s+1+tot);
	bit1.mem(),bit2.mem(),bit3.mem(),bit4.mem(),bit5.mem(),bit6.mem();
	for (int i=1;i<=n;i++){
		if (a[i]>0){
			int t=lower(sum[i-1]),r=lower(sum[i-1]+a[i]);
			bit1.add(t,p[i]),bit2.add(t,sum[i-1]%mod*p[i]%mod),bit3.add(t,a[i]*p[i]%mod);
			bit4.add(r,p[i]),bit5.add(r,sum[i-1]%mod*p[i]%mod),bit6.add(r,a[i]*p[i]%mod);
		}
		for (int j=0;j<(int)ql[i].size();j++){
			int l=ql[i][j];
			int t=lower(sum[l-1]);
			int qwq=-bit3.ask(t+1,maxn)+bit6.ask(1,t-1);
			qwq=(qwq+2*sum[l-1]%mod*bit1.ask(1,t)-2*bit2.ask(1,t)-bit3.ask(1,t)-2*sum[l-1]%mod*bit4.ask(1,t-1)+2*bit5.ask(1,t-1)+bit6.ask(1,t-1));
			qwq=(qwq%mod+mod)%mod;
			if (l>i)upd(ans[qid[i][j]],mod-qwq);
			else upd(ans[qid[i][j]],qwq);
		}
	}
	for (int i=1;i<=m;i++)printf("%lld\n",ans[i]);
	return 0;
}