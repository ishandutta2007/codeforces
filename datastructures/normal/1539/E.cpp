#include <iostream>
#include <cstdio>
#include <algorithm>
#include <set>
#include <vector>
#define inf 1000000000
using namespace std;
int read(){
	int x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
	return x;
}
struct BIT{
	int tree[1000005],maxn;
	BIT(){
		maxn=1000000;
		for (int i=0;i<=maxn;i++)tree[i]=inf;
		return;
	}
	int lowbit(int x){
		return x&(-x);
	}
	void add(int pos,int val){
		while(pos<=maxn)tree[pos]=min(tree[pos],val),pos+=lowbit(pos);
		return;
	}
	int ask(int pos){
		int ans=inf;
		while(pos)ans=min(ans,tree[pos]),pos-=lowbit(pos);
		return ans;
	}
};
struct SEG_WORK{
	BIT bit1,bit2;
	int maxn;
	SEG_WORK(){
		maxn=1000000;
		return;
	}
	void add(int l,int r,int id){
		bit1.add(r+1,id);
		bit2.add(maxn-(l-1),id);
		return;
	}
	int ask(int pos){
		return min(bit1.ask(pos),bit2.ask(maxn-pos));
	}
}sl,sr;
struct QWQ_SET{
	set<int> c;
	void ins(int x){
		c.insert(x);
		return;
	}
	void del(int x){
		c.erase(x);
		return;
	}
	int ask(){
	    if (c.begin()==c.end())return -1;
		set<int>::iterator it=c.end();
		it--;
		return (*it);
	}
}df,dg;
int n,m,k[100005],al[100005],bl[100005],ar[100005],br[100005];
int s[500005],tot;
int nxtl[100005],nxtr[100005],f[100005],g[100005],pref[100005],preg[100005];
int lower(int x){
	int l=1,r=tot,ans=0;
	while(l<=r){
		int mid=(l+r)/2;
		if (s[mid]<=x)ans=mid,l=mid+1;
		else r=mid-1;
	}
	return ans;
}
int ans[100005];
void find_ans(int now,int fg){
	if (now==0)return;
	int pre;
	if (fg==0)pre=pref[now];
	if (fg==1)pre=preg[now];
	for (int i=pre+1;i<=now;i++)ans[i]=fg;
	if (fg==0)find_ans(pre,1);
	if (fg==1)find_ans(pre,0);
	return;
}
int chkl[100005],chkr[100005];
vector<int> delf[100005],delg[100005];
bool cl(int l,int r){
	if (l>r)return 1;
	if (chkl[l-1]==chkl[r])return 1;
	return 0;
}
bool cr(int l,int r){
	if (l>r)return 1;
	if (chkr[l-1]==chkr[r])return 1;
	return 0;
}
int main(){
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		k[i]=read();
		al[i]=read(),bl[i]=read();
		ar[i]=read(),br[i]=read();
		s[++tot]=k[i];
		s[++tot]=al[i],s[++tot]=ar[i];
		s[++tot]=bl[i],s[++tot]=br[i];
	}
	s[++tot]=0;
	sort(s+1,s+1+tot);
	for (int i=1;i<=n;i++){
		k[i]=lower(k[i]);
		al[i]=lower(al[i]),bl[i]=lower(bl[i]);
		ar[i]=lower(ar[i]),br[i]=lower(br[i]);
	}
	for (int i=n;i>=1;i--){
		sl.add(al[i],bl[i],i);
		sr.add(ar[i],br[i],i);
		nxtl[i]=sl.ask(k[i]);
		nxtr[i]=sr.ask(k[i]);
	}
	for (int i=1;i<=n;i++){
		chkl[i]=chkl[i-1],chkr[i]=chkr[i-1];
		if (k[i]<al[i]||k[i]>bl[i])chkl[i]++;
		if (k[i]<ar[i]||k[i]>br[i])chkr[i]++;
	}
	df.ins(0),dg.ins(0);
	nxtl[0]=sl.ask(lower(0)),nxtr[0]=sr.ask(lower(0));
	if (nxtl[0]<=n)delf[nxtl[0]].push_back(0);
	if (nxtr[0]<=n)delg[nxtr[0]].push_back(0);
	for (int i=1;i<=n;i++){
		for (int j=0,len=delf[i].size();j<len;j++)df.del(delf[i][j]);
		for (int j=0,len=delg[i].size();j<len;j++)dg.del(delg[i][j]);
		int pf=df.ask(),pg=dg.ask();
		if (pg>=0&&cl(pg+1,i))f[i]=1,pref[i]=pg;
		if (pf>=0&&cr(pf+1,i))g[i]=1,preg[i]=pf;
		if (f[i]==1){
			df.ins(i);
			if (nxtl[i]<=n)delf[nxtl[i]].push_back(i);
		}
		if (g[i]==1){
			dg.ins(i);
			if (nxtr[i]<=n)delg[nxtr[i]].push_back(i);
		}
	}
	if (f[n]==0&&g[n]==0)puts("No");
	else{
		puts("Yes");
		if (f[n]==1)find_ans(n,0);
		else find_ans(n,1);
		for (int i=1;i<=n;i++)printf("%d ",ans[i]);
		puts("");
	}
	return 0;
}