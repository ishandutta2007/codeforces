#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#define mod 998244353
#define inf 1000000000
using namespace std;
void upd(int &x,int y){
	x+=y;
	if (x>=mod)x-=mod;
	return;
}
int n,k,c[100005],f[100005];
vector<int> e[100005];
int B=180;
int Bcnt,Bid[100005],Bl[100005],Br[100005];
int tag[100005];
struct node{
	int pos,val,f;
}a[100005];
int sum[100005];
bool cmp(node a,node b){
	return a.val<b.val;
}
void pushup(int id){
	sort(a+Bl[id],a+Br[id]+1,cmp);
	for (int i=Bl[id];i<=Br[id];i++)sum[i]=0;
	for (int i=Bl[id];i<=Br[id];i++)sum[i]=a[i].f;
	for (int i=Bl[id]+1;i<=Br[id];i++)upd(sum[i],sum[i-1]);
	return;
}
void upd_val(int pos,int val){
	int id=Bid[pos];
	int l=Bl[id],r=Br[id];
	for (int i=l;i<=r;i++)
		if (a[i].pos==pos)a[i].val=val-tag[id];
	return;
}
void upd_f(int pos,int f){
	int id=Bid[pos];
	int l=Bl[id],r=Br[id];
	for (int i=l;i<=r;i++)
		if (a[i].pos==pos)a[i].f=f;
	return;
}
int qwq_pos[100005];
void qwq_add(int l,int r,int val){
	int id=Bid[l];
	for (int i=Bl[id];i<=Br[id];i++)
		qwq_pos[a[i].pos]=i;
	for (int i=l;i<=r;i++)a[qwq_pos[i]].val+=val;
	pushup(id);
	return;
}
void add(int l,int r,int val){
	if (l<1||r>n||l>r)return;
	int lid=Bid[l],rid=Bid[r];
	if (lid==rid)qwq_add(l,r,val);
	else{
		qwq_add(l,Br[lid],val);
		qwq_add(Bl[rid],r,val);
		for (int i=lid+1;i<=rid-1;i++)tag[i]+=val;
	}
	return;
}
int ask(int id){
	int l=Bl[id],r=Br[id],pos=0;
	while(l<=r){
		int mid=(l+r)/2;
		if (a[mid].val+tag[id]<=k)pos=mid,l=mid+1;
		else r=mid-1;
	}
	return sum[pos];
}
int query(){
	int ans=0;
	for (int i=1;i<=Bcnt;i++)upd(ans,ask(i));
	return ans;
}
void B_build(){
	for (int i=1;i<=n;i++){
		if (i%B==1)Bcnt++,Bl[Bcnt]=i;
		Bid[i]=Bcnt;
		Br[Bcnt]=i;
	}
	return;
}
int main(){
	cin>>n>>k;
	for (int i=1;i<=n;i++)cin>>c[i];
	for (int i=0;i<=n;i++)a[i].pos=i,a[i].val=inf,a[i].f=0;
	B_build();
	f[0]=1;
	for (int i=1;i<=n;i++)e[i].push_back(-1),e[i].push_back(0);
	for (int i=1;i<=n;i++){
		e[c[i]].push_back(i);
		int len=e[c[i]].size()-1;
		int pre1=e[c[i]][len-2],pre2=e[c[i]][len-1];
		upd_f(i,f[i-1]);
		upd_val(i,0);
		pushup(Bid[i]);
		add(pre2+1,i,1);
		add(pre1+1,pre2,-1);
		f[i]=query();
	}
	cout<<f[n]<<endl;
	return 0;
}