#include<bits/stdc++.h>
using namespace std;
const int N=6e5+50;
int n,q[N],pos[N],ans[N];
struct node{
	int lmn,rmx,sum;
	node operator +(const node &b){
		return (node){min(lmn,sum+b.lmn),max(b.rmx,b.sum+rmx),sum+b.sum};
	}
}t[N*4];
void change(int x,int l,int r,int p,int d){
	if(l==r){t[x].sum+=d;t[x].rmx+=d;t[x].lmn+=d;return;}
	int mid=(l+r)>>1;
	if(p<=mid)change(x<<1,l,mid,p,d);
	else change(x<<1|1,mid+1,r,p,d);
	t[x]=t[x<<1]+t[x<<1|1];
}
node query(int x,int l,int r,int ql,int qr){
	if(l>=ql&&r<=qr)return t[x];
	int mid=(l+r)>>1;
	if(qr<=mid)return query(x<<1,l,mid,ql,qr);
	if(ql>mid)return query(x<<1|1,mid+1,r,ql,qr);
	return query(x<<1,l,mid,ql,qr)+query(x<<1|1,mid+1,r,ql,qr);
}
bool check(int x){
	int p=pos[x],dat=p^1?query(1,1,n,1,p-1).rmx:0;
	dat=max(dat,0);
	int pp=query(1,1,n,p+1,n).lmn;
	return -pp<=dat;
}
int main(){
	scanf("%d",&n);
	for(int i=1,x;i<=n;i++)scanf("%d",&x),pos[x]=2*i-1;
	for(int i=1;i<=n;i++)scanf("%d",&q[i]),q[i]*=2;n*=2;
	for(int i=n/2,j=0;i;i--){
		while(check(i)&&j<n)ans[j++]=i,change(1,1,n,q[j],-1);
		change(1,1,n,pos[i],1);
	}
	for(int i=0;i<n/2;i++)printf("%d ",ans[i]);
	return 0;
}