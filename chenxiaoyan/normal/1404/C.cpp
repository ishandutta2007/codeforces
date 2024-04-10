/*





D P 




 l l
*/
#include<bits/stdc++.h>
using namespace std;
#define pb push_back
const int inf=0x3f3f3f3f;
const int N=300000,QU=N;
int n,qu;
int a[N+1];
struct query{int l,r;}qry[QU+1];
vector<int> pos[N+1];
int ans[QU+1];
struct segtree{
	struct node{int l,r,dif,rl,lz;}nd[N<<2];
	#define l(p) nd[p].l
	#define r(p) nd[p].r
	#define dif(p) nd[p].dif
	#define rl(p) nd[p].rl
	#define lz(p) nd[p].lz
	void bld(int l=1,int r=n,int p=1){
		l(p)=l;r(p)=r;dif(p)=rl(p)=-inf;lz(p)=0;
		if(l==r)return;
		int mid=l+r>>1;
		bld(l,mid,p<<1);bld(mid+1,r,p<<1|1);
	}
	void init(){bld();}
	void sprup(int p){dif(p)=max(dif(p<<1),dif(p<<1|1));rl(p)=max(rl(p<<1),rl(p<<1|1));}
	void sprdwn(int p){
		if(lz(p)){
			dif(p<<1)+=lz(p);rl(p<<1)+=lz(p);lz(p<<1)+=lz(p);
			dif(p<<1|1)+=lz(p);rl(p<<1|1)+=lz(p);lz(p<<1|1)+=lz(p);
			lz(p)=0;
		}
	}
	void chg(int x,int v1,int v2,int p=1){
		if(l(p)==r(p))return dif(p)=v1,rl(p)=v2,void();
		sprdwn(p);
		int mid=l(p)+r(p)>>1;
		chg(x,v1,v2,p<<1|(x>mid));
		sprup(p);
	}
	void add(int l,int r,int v,int p=1){
		if(l>r)return;
		if(l<=l(p)&&r>=r(p))return dif(p)+=v,rl(p)+=v,lz(p)+=v,void();
		sprdwn(p);
		int mid=l(p)+r(p)>>1;
		if(l<=mid)add(l,r,v,p<<1);
		if(r>mid)add(l,r,v,p<<1|1);
		sprup(p);
	}
	int mx(int l,int r,int p=1){
		if(l<=l(p)&&r>=r(p))return rl(p);
		sprdwn(p);
		int mid=l(p)+r(p)>>1,res=-inf;
		if(l<=mid)res=max(res,mx(l,r,p<<1));
		if(r>mid)res=max(res,mx(l,r,p<<1|1));
		return res;
	}
	int fst(){
		int p=1;
		if(dif(p)<0)return 0;
		while(l(p)<r(p)){
			sprdwn(p);
			if(dif(p<<1)>=0)p=p<<1;
			else p=p<<1|1;
		}
		return l(p);
	}
}segt;
int main(){
	cin>>n>>qu;
	for(int i=1;i<=n;i++)scanf("%d",a+i),a[i]=i-a[i];
	for(int i=1;i<=qu;i++)scanf("%d%d",&qry[i].l,&qry[i].r),qry[i].l++,qry[i].r=n-qry[i].r,pos[qry[i].l].pb(i);
	segt.init();
	for(int i=n;i;i--){
		if(a[i]==0){
			segt.chg(i,-inf,0);segt.add(i+1,n,1);
			int fd;
			while(fd=segt.fst()){
				segt.chg(fd,-inf,segt.mx(1,fd-1)+1);segt.add(fd+1,n,1);
			}
		}
		else if(a[i]>0)segt.chg(i,-a[i],-inf);
		for(int j=0;j<pos[i].size();j++)ans[pos[i][j]]=max(0,segt.mx(1,qry[pos[i][j]].r)+1);
	}
	for(int i=1;i<=qu;i++)printf("%d\n",ans[i]);
	return 0;
}
/*1
13 5
2 2 3 9 5 4 6 5 7 8 3 11 13
3 1
0 0
2 4
5 0
0 12
*/
/*2
5 2
1 4 1 2 4
0 0
1 0
*/