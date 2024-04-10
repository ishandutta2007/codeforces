#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,q;
bool tg[5300005];
int dat[530005][6][2];
int a[200005];
void push(int i){
	tg[i]^=1;
	for(int j=0;j<=m;j++)swap(dat[i][j][0],dat[i][j][1]);
}
void pushdown(int i){
	if(tg[i]){
		int ls=i<<1,rs=i<<1|1;
		push(ls),push(rs);
		tg[i]=0;
	}
}
void merge(int i){
	int ls=i<<1,rs=i<<1|1;
	for(int j=0;j<=m;j++)for(int k=0;k<2;k++)
		dat[i][j][k]=dat[ls][dat[rs][j][k]][k];
}
void built(int i,int l,int r){
	if(l==r){
		for(int j=0;j<=m;j++){
			if(j==0){
				if(a[l]&1)dat[i][j][0]=1,dat[i][j][1]=0;
				else dat[i][j][0]=0,dat[i][j][1]=1;
			}else{
				if(j==m)dat[i][j][0]=dat[i][j][1]=0;
				else dat[i][j][0]=dat[i][j][1]=j+1;
			}
		}
		return;
	}
	int md=(l+r)>>1;
	built(i<<1,l,md),built(i<<1|1,md+1,r);
	merge(i);
}
void upd(int i,int l,int r,int a,int b){
	if(r<a||b<l)return;
	if(a<=l&&r<=b){
		push(i);
		return;
	}
	pushdown(i);
	int md=(l+r)>>1;
	upd(i<<1,l,md,a,b),upd(i<<1|1,md+1,r,a,b);
	merge(i);
}
int stat;
void qry(int i,int l,int r,int a,int b){
	if(r<a||b<l)return;
	if(a<=l&&r<=b){
		stat=dat[i][stat][0];
		return;
	}
	pushdown(i);
	int md=(l+r)>>1;
	qry(i<<1|1,md+1,r,a,b),qry(i<<1,l,md,a,b);
}
int g[200005];
int main(){
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1;i<=n;i++){
		ll x;scanf("%lld",&x);
		a[i]=x&1;
	}
	built(1,1,n);
	while(q--){
		int op,l,r;scanf("%d%d%d",&op,&l,&r);
		if(op==1){
			ll d;scanf("%lld",&d);
			if(d&1)upd(1,1,n,l,r);
		}else{
			stat=0;
			qry(1,1,n,l,r);
			if(stat==1)puts("2");
			else puts("1");
		}
	}
}