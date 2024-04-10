/*




D P 




 l l
*/
#include<bits/stdc++.h>
using namespace std;
#define pb push_back
const int inf=0x3f3f3f3f;
const int N=200000,QU=200000;
int n,qu;
int a[N+1],b[N+1];
struct query{int a,b;}qry[QU+1];
vector<int> nums;
void discrete(){
	sort(nums.begin(),nums.end());
	nums.resize(unique(nums.begin(),nums.end())-nums.begin());
	for(int i=1;i<=n;i++)b[i]=lower_bound(nums.begin(),nums.end(),a[i])-nums.begin();
}
vector<int> pos[N];
vector<int> hav[N+1];
struct segtree{
	struct node{int l,r,mx,lz;}nd[N<<2];
	#define l(p) nd[p].l
	#define r(p) nd[p].r
	#define mx(p) nd[p].mx
	#define lz(p) nd[p].lz
	void bld(int l=1,int r=n,int p=1){
		l(p)=l;r(p)=r;mx(p)=-inf;lz(p)=0;
		if(l==r)return;
		int mid=l+r>>1;
		bld(l,mid,p<<1);bld(mid+1,r,p<<1|1);
	}
	void init(){bld();}
	void sprup(int p){mx(p)=max(mx(p<<1),mx(p<<1|1));}
	void sprdwn(int p){
		mx(p<<1)+=lz(p);mx(p<<1|1)+=lz(p);
		lz(p<<1)+=lz(p);lz(p<<1|1)+=lz(p);
		lz(p)=0;
	}
	void chg(int x,int v,int p=1){
		if(l(p)==r(p)){mx(p)=v;return;}
		sprdwn(p);
		int mid=l(p)+r(p)>>1;
		chg(x,v,p<<1|(x>mid));
		sprup(p);
	}
	int ask_mx(int l,int r,int p=1){
		if(l(p)==r(p))return mx(p);
		sprdwn(p);
		int mid=l(p)+r(p)>>1,res=0;
		if(l<=mid)res=max(res,ask_mx(l,r,p<<1));
		if(r>mid)res=max(res,ask_mx(l,r,p<<1|1));
		return res;
	}
	void add(int l,int r,int p=1){
		if(l(p)==r(p)){mx(p)++;lz(p)++;return;}
		sprdwn(p);
		int mid=l(p)+r(p)>>1;
		if(l<=mid)add(l,r,p<<1);
		if(r>mid)add(l,r,p<<1|1);
		sprup(p);
	}
	int fd(int x){
		int p=1;
		while(l(p)<r(p)){
			sprdwn(p);
			if(mx(p<<1)>=x)p<<=1;
			else (p<<=1)|=1;
		}
		return a[l(p)];
	}
}segt;
map<int,int> ans[N+1];
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)scanf("%d",a+i),nums.pb(a[i]);
	discrete();
	for(int i=1;i<=n;i++)pos[b[i]].pb(i);
	cin>>qu;
	for(int i=1;i<=qu;i++)scanf("%d%d",&qry[i].a,&qry[i].b),hav[qry[i].a].pb(qry[i].b);
	segt.init();
	int now=0;
	for(int i=nums.size()-1;~i;i--)
		for(int j=0;j<pos[i].size();j++){
//			printf("pos[%d][%d]=%d\n",i,j,pos[i][j]);
			segt.chg(pos[i][j],segt.ask_mx(1,pos[i][j]-1)+1);segt.add(pos[i][j]+1,n);
			now++;
			for(int k=0;k<hav[now].size();k++)ans[now][hav[now][k]]=segt.fd(hav[now][k]);
		}
	for(int i=1;i<=qu;i++)cout<<ans[qry[i].a][qry[i].b]<<"\n";
	return 0;
}