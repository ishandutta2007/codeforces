#include<bits/stdc++.h>
using namespace std;
int n,q,x,y,opt;
char c[1];
struct DDT{
	int dat[6500000],L[6500000],R[6500000],cnt;
	int sml(int id,int l,int r,int pos){
		if(id==0)return 0;
		if(l==r)return dat[id];
		int mid=(l+r)/2,tmp;
		if(pos<=mid)tmp=sml(L[id],l,mid,pos);
		else tmp=sml(R[id],mid+1,r,pos);
		return max(tmp,dat[id]);
	}
	int upd(int id,int l,int r,int a,int b,int x){
		if(id==0){
			id=++cnt;
			dat[id]=0;
			L[id]=R[id]=0;
		}
		if(r<a||b<l)return id;
		if(a<=l&&r<=b){
			dat[id]=max(dat[id],x);
			return id;
		}
		int mid=(l+r)/2;
		L[id]=upd(L[id],l,mid,a,b,x);
		R[id]=upd(R[id],mid+1,r,a,b,x);
		return id;
	}
}st[2];
int main(){
	scanf("%d%d",&n,&q);
	for(int i=0;i<2;i++)st[i].cnt=0,st[i].upd(0,1,n,1,n,0);
	while(q--){
		scanf("%d%d%s",&x,&y,c);
		if(*c=='U'){
			int P=st[0].sml(1,1,n,x);
			printf("%d\n",y-P);
			st[0].upd(1,1,n,x,x,y);
			st[1].upd(1,1,n,P+1,y,x);
		}else{
			int P=st[1].sml(1,1,n,y);
			printf("%d\n",x-P);
			st[1].upd(1,1,n,y,y,x);
			st[0].upd(1,1,n,P+1,x,y);		
		}
	}
}