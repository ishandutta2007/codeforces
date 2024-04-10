/*




D P 




 l l
*/
#pragma GCC optimize(3)
#include<bits/stdc++.h>
using namespace std;
#define pb push_back 
char _buf[10000005],*_st,*_ed;
char gc(){return _st==_ed&&(_ed=(_st=_buf)+fread(_buf,1,10000000,stdin),_st==_ed)?-1:*_st++;}
void read(int &x){
	x=0;char c=gc();
	while(!isdigit(c))c=gc();
	while(isdigit(c))x=(x<<1)+(x<<3)+(c^48),c=gc();
}
const int QU=300000;
int n,qu;
struct query{int l,r,kd;}qry[QU+1];
vector<int> nums;
void discrete(){
	sort(nums.begin(),nums.end());
	nums.resize(unique(nums.begin(),nums.end())-nums.begin());
	for(int i=1;i<=qu;i++)
		qry[i].l=lower_bound(nums.begin(),nums.end(),qry[i].l)-nums.begin(),
		qry[i].r=lower_bound(nums.begin(),nums.end(),qry[i].r)-nums.begin();
}
struct segtree{
	struct node{int l,r,cnt,lz;bool is;}nd[QU<<4];
	#define l(p) nd[p].l
	#define r(p) nd[p].r
	#define cnt(p) nd[p].cnt
	#define lz(p) nd[p].lz
	#define is(p) nd[p].is
	void sprup(int p){cnt(p)=cnt(p<<1)+cnt(p<<1|1);is(p)=is(p<<1);}
	void bld(int l=0,int r=max(0,(int)nums.size()-2),int p=1){
		l(p)=l;r(p)=r;lz(p)=0;
		if(l==r){cnt(p)=nums[l+1]-nums[l];is(p)=true;return;}
		int mid=l+r>>1;
		bld(l,mid,p<<1);bld(mid+1,r,p<<1|1);
		sprup(p);
	}
	void init(){bld();}
	void sprdwn(int p){
		if(lz(p)==1){
			cnt(p<<1)=cnt(p<<1|1)=0;
			is(p<<1)=is(p<<1|1)=false;
			lz(p<<1)=lz(p<<1|1)=1;
		}
		else if(lz(p)==2){
			cnt(p<<1)=nums[r(p<<1)+1]-nums[l(p<<1)];cnt(p<<1|1)=nums[r(p<<1|1)+1]-nums[l(p<<1|1)];
			is(p<<1)=is(p<<1|1)=true;
			lz(p<<1)=lz(p<<1|1)=2;
		}
		lz(p)=0;
	}
	void chg_rg(int l,int r,int kd,int p=1){
		if(l>r)return;
		if(l<=l(p)&&r>=r(p)){cnt(p)=kd==1?0:nums[r(p)+1]-nums[l(p)];is(p)=kd==2;lz(p)=kd;return;}
		sprdwn(p);
		int mid=l(p)+r(p)>>1;
		if(l<=mid)chg_rg(l,r,kd,p<<1);
		if(r>mid)chg_rg(l,r,kd,p<<1|1);
		sprup(p);
	}
	void chg_sg(int x,int kd,int p=1){
		if(l(p)==r(p)){kd==1?cnt(p)-=is(p):cnt(p)+=!is(p);is(p)=kd==2;return;}
		sprdwn(p);
		int mid=l(p)+r(p)>>1;
		chg_sg(x,kd,p<<1|(x>mid));
		sprup(p);
	}
	int ask_cnt(){return cnt(1);}
}segt;
int main(){
//	freopen("C:\\Users\\chenx\\OneDrive\\\\data.in","r",stdin);freopen("C:\\Users\\chenx\\OneDrive\\\\ycx.out","w",stdout);
	read(n);read(qu);
	nums.pb(1);nums.pb(n);nums.pb(n+1);
	for(int i=1;i<=qu;i++)read(qry[i].l),read(qry[i].r),read(qry[i].kd),nums.pb(qry[i].l),nums.pb(qry[i].r);
	discrete();
	segt.init();
//	cout<<segt.ask_cnt()<<"\n";
	for(int i=1;i<=qu;i++){
		segt.chg_rg(qry[i].l,qry[i].r-1,qry[i].kd);
		segt.chg_sg(qry[i].r,qry[i].kd);
		cout<<segt.ask_cnt()<<"\n";
	}
	return 0;
}
/*1
4
6
1 2 1
3 4 1
2 3 2
1 3 2
2 4 1
1 4 2
*/
/*2
3
8
2 2 1
3 3 2
1 1 1
1 3 2
2 3 2
3 3 1
1 2 1
2 2 2
*/