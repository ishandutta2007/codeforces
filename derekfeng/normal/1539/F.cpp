#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define fi first
#define se second 
int n,ans[200004];
pii a[200004];
int dat[524300],mn[524300],mx[524300];
void built(int l,int r,int id){
	if(l==r){
		dat[id]=0,mn[id]=mx[id]=-l;
		return;
	}
	int mid=(l+r)>>1;
	built(l,mid,id<<1),built(mid+1,r,id<<1|1);
	dat[id]=0,mn[id]=-r,mx[id]=-l;
}
void upd(int l,int r,int id,int a,int b){
	if(r<a||b<l)return;
	if(a<=l&&r<=b){
		dat[id]+=2,mn[id]+=2,mx[id]+=2;
		return;
	}
	int mid=(l+r)>>1;
	upd(l,mid,id<<1,a,b),upd(mid+1,r,id<<1|1,a,b);
	mn[id]=min(mn[id<<1],mn[id<<1|1])+dat[id];
	mx[id]=max(mx[id<<1],mx[id<<1|1])+dat[id];
}
int q1(int l,int r,int id,int a,int b,int x){
	if(r<a||b<l)return -1e9;
	if(a<=l&&r<=b)return mx[id]+x;
	int mid=(l+r)>>1;
	return max(q1(l,mid,id<<1,a,b,x+dat[id]),q1(mid+1,r,id<<1|1,a,b,x+dat[id]));
}
int q2(int l,int r,int id,int a,int b,int x){
	if(r<a||b<l)return 0;
	if(a<=l&&r<=b)return mn[id]+x;
	int mid=(l+r)>>1;
	return min(q2(l,mid,id<<1,a,b,x+dat[id]),q2(mid+1,r,id<<1|1,a,b,x+dat[id]));
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i].fi),a[i].se=i;
	sort(a+1,a+n+1); 
	built(1,n,1);
	for(int i=1,j;i<=n;i=j){
		for(j=i+1;j<=n&&a[j].fi==a[i].fi;j++);
		for(int k=i;k<j;k++)upd(1,n,1,a[k].se,n);
		for(int k=i;k<j;k++)ans[a[k].se]=max(ans[a[k].se],q1(1,n,1,a[k].se,n,0)-q2(1,n,1,1,a[k].se-1,0)-1);
	}
	reverse(a+1,a+n+1);
	built(1,n,1);
	for(int i=1,j;i<=n;i=j){
		for(j=i+1;j<=n&&a[j].fi==a[i].fi;j++);
		for(int k=i;k<j;k++)upd(1,n,1,a[k].se,n);
		for(int k=i;k<j;k++)ans[a[k].se]=max(ans[a[k].se],q1(1,n,1,a[k].se,n,0)-q2(1,n,1,1,a[k].se-1,0));
	}
	for(int i=1;i<=n;i++)printf("%d ",ans[i]/2);
}