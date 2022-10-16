#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <map>
#include <vector>
#include <queue>
#include <set>
#define int long long
#define inf 10000000000000000
using namespace std;
int read(){
	int x=0;
	int fg=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if (ch=='-')fg=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
	return x*fg;
}
struct SGT{
	int tree[2000005];
	int maxn;
	void init(int n){
		maxn=n;
		for (int i=1;i<=4*maxn;i++)tree[i]=-inf;
		return;
	}
	void tree_upd(int now,int nowl,int nowr,int pos,int val){
		if (nowl==nowr){
			tree[now]=max(tree[now],val);
			return;
		}
		int mid=(nowl+nowr)/2;
		if (pos<=mid)tree_upd(now*2,nowl,mid,pos,val);
		else tree_upd(now*2+1,mid+1,nowr,pos,val);
		tree[now]=max(tree[now*2],tree[now*2+1]);
		return;
	}
	void upd(int pos,int val){
		tree_upd(1,1,maxn,pos,val);
		return;
	}
	int tree_ask(int now,int nowl,int nowr,int lt,int rt){
		if (nowl>=lt&&nowr<=rt)return tree[now];
		int mid=(nowl+nowr)/2,s=-inf;
		if (mid>=lt)s=max(s,tree_ask(now*2,nowl,mid,lt,rt));
		if (mid+1<=rt)s=max(s,tree_ask(now*2+1,mid+1,nowr,lt,rt));
		return s;
	}
	int ask(int l,int r){
		return tree_ask(1,1,maxn,l,r);
	}
}sgt;
int n,q,qwq[5][500005],sum[5][500005],a[500005],b[500005];
vector<int> ql[500005],qr[500005],qk[500005],qc[500005];
int ans;
int f[500005];
void calc(int l,int r,int val){
	if (l==r){
		ans=max(ans,val+a[l]+b[l]);
		return;
	}
	int mid=(l+r)/2;
	int lval=val,rval=val;
	for (int i=l;i<=mid+1;i++)
		for (int j=0;j<(int)qr[i].size();j++)
			if (qr[i][j]>=r)rval=max(rval,qc[i][j]);
	for (int i=mid;i<=r;i++)
		for (int j=0;j<(int)ql[i].size();j++)
			if (ql[i][j]<=l)lval=max(lval,qk[i][j]);
	calc(l,mid,lval);
	calc(mid+1,r,rval);
	sgt.init(r-l+2);
	sgt.upd(1,a[l]);
	for (int i=l;i<=mid;i++){
		int val=-inf;
		if (i<mid)val=a[i+1];
		for (int j=0;j<(int)ql[i].size();j++)val=max(val,sgt.ask(max(l-1,ql[i][j]-1)-l+2,i-l+2)+qk[i][j]);
		sgt.upd(i-l+2,val);
	}
	for (int i=mid+1;i<=r;i++){
		f[i]=-inf;
		for (int j=0;j<(int)ql[i].size();j++){
			f[i]=max(f[i],sgt.ask(max(l-1,ql[i][j]-1)-l+2,i-l+2)+qk[i][j]);
		}
        sgt.upd(i-l+2,f[i]);
	}
	for (int i=l;i<=r;i++)
		for (int j=0;j<(int)qr[i].size();j++)
			if (qr[i][j]>=r)f[r]=max(f[r],sgt.ask(max(l-1,i-1)-l+2,r-l+2)+qc[i][j]);
	f[r]=max(f[r],sgt.ask(1,r-l+2)+val);
	f[r+1]=-inf;
	for (int i=r;i>mid;i--){
		f[i]=max(f[i],f[i+1]);
		ans=max(ans,f[i]+b[i]);
	}
	return;
}
signed main(){
	cin>>n>>q;
	for (int i=1;i<=3;i++){
		for (int j=1;j<=n;j++)qwq[i][j]=read(),sum[i][j]=sum[i][j-1]+qwq[i][j];
	}
	for (int i=1;i<=n;i++)a[i]=sum[1][i]-sum[2][i-1],b[i]=sum[3][n]-sum[3][i-1]+sum[2][i];
	int val=-inf;
	for (int i=1;i<=q;i++){
		int l,r,c;
		l=read(),r=read(),c=-read();
		if (l==1&&r==n)val=max(val,c);
		ql[r].push_back(l);
		qk[r].push_back(c);
		qr[l].push_back(r);
		qc[l].push_back(c);
	}
	ans=-inf;
	calc(1,n,val);
	cout<<ans<<endl;
	return 0;
}