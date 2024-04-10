#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct vl{
	int L,R,val;
	vl(int L=0,int R=0,int val=0):L(L),R(R),val(val){}
};
int n,c[300004];
ll ans;
stack<vl>st1,st2;
int mn[1048580],dat[1048580],num[1048580];
void built(int l,int r,int id){
	mn[id]=l,num[id]=1;
	if(l<r){
		int mid=(l+r)>>1;
		built(l,mid,id<<1),built(mid+1,r,id<<1|1);
	}
}
void upd(int l,int r,int id,int a,int b,int x){
	if(r<a||b<l)return;
	if(a<=l&&r<=b){
		mn[id]+=x,dat[id]+=x;
		return;
	}
	int mid=(l+r)>>1;
	upd(l,mid,id<<1,a,b,x),upd(mid+1,r,id<<1|1,a,b,x);
	mn[id]=min(mn[id<<1],mn[id<<1|1])+dat[id];
	num[id]=0;
	if(mn[id]==mn[id<<1]+dat[id])num[id]+=num[id<<1];
	if(mn[id]==mn[id<<1|1]+dat[id])num[id]+=num[id<<1|1];
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		int R,C;scanf("%d%d",&R,&C);
		c[R]=C;
	}
	built(1,n,1);
	for(int i=1;i<=n;i++){
		int p=c[i];
		vl X=vl(i,i,p);
		vl Y=vl(i,i,p);
		while(!st1.empty()&&st1.top().val>p){
			vl x=st1.top();st1.pop();
			upd(1,n,1,x.L,x.R,x.val);
			X.L=x.L;
		}
		while(!st2.empty()&&st2.top().val<p){
			vl x=st2.top();st2.pop();
			upd(1,n,1,x.L,x.R,-x.val);
			Y.L=x.L;
		}
		st1.push(X),st2.push(Y);
		upd(1,n,1,X.L,X.R,-p),upd(1,n,1,Y.L,Y.R,p);
		ans+=num[1];
	}
	printf("%lld",ans);
}