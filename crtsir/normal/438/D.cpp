#include<bits/stdc++.h>
using namespace std;
int dat[262144],n,m;
long long sum[262144];
long long query(int l,int r,int _l,int _r,int k){
	if(_l<=l&&r<=_r)
		return sum[k];
	if(l>_r||r<_l)return 0;
	return query(l,l+r>>1,_l,_r,k<<1)+query(l+r+1>>1,r,_l,_r,k<<1|1);
}
void calc(int l,int r,int _l,int _r,int x,int k){
	if(l>_r||r<_l||dat[k]<x)return;
	if(l==r){
		sum[k]%=x;
		dat[k]%=x;
		return;
	}
	calc(l,l+r>>1,_l,_r,x,k<<1);
	calc(l+r+1>>1,r,_l,_r,x,k<<1|1);
	sum[k]=sum[k<<1]+sum[k<<1|1];
	dat[k]=max(dat[k<<1],dat[k<<1|1]);
}
void modify(int k,int x){
	k+=131072;
	sum[k]=x;
	dat[k]=x;
	k>>=1;
	while(k){
		sum[k]=sum[k<<1]+sum[k<<1|1];
		dat[k]=max(dat[k<<1],dat[k<<1|1]);
		k>>=1;
	}
}
int main(){
	cin>>n>>m;
	for(int i=0;i<n;i++){
		scanf("%d",&dat[i+131072]);
		sum[i+131072]=dat[i+131072];
	}
	for(int i=131071;i>=0;i--){
		sum[i]=sum[i<<1]+sum[i<<1|1];
		dat[i]=max(dat[i<<1],dat[i<<1|1]);
	}
	while(m--){
		int tp;
		scanf("%d",&tp);
		if(tp==1){
			int l,r;
			scanf("%d%d",&l,&r);l--;r--;
			printf("%lld\n",query(0,131071,l,r,1));
		}
		if(tp==2){
			int l,r,x;
			scanf("%d%d%d",&l,&r,&x);l--;r--;
			calc(0,131071,l,r,x,1);
		}
		if(tp==3){
			int k,x;
			scanf("%d%d",&k,&x);k--;
			modify(k,x);
		}
	}
}