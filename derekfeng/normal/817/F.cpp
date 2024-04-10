#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF=1e18+1;
int q,m;
int op[100004];
ll l[100004],r[100004];
vector<ll>all;
bool d0[524300],d1[524300];
int lz[524300];
void built(int l,int r,int id){
	d0[id]=1;
	if(l!=r){
		int mid=(l+r)>>1;
		built(l,mid,id<<1),built(mid+1,r,id<<1|1); 
	}
}
void push(int id,int x){
	if(x==1){
		lz[id]=1;
		d0[id]=0,d1[id]=1;
	}
	if(x==2){
		lz[id]=2;
		d1[id]=0,d0[id]=1;
	}
	if(x==3){
		lz[id]=3-lz[id];
		swap(d0[id],d1[id]);
	}
}
void pushdown(int id){
	if(lz[id]){
		push(id<<1,lz[id]);
		push(id<<1|1,lz[id]);
		lz[id]=0;
	}
}
void pushup(int id){
	d0[id]=d1[id]=0;
	d0[id]=d0[id<<1]|d0[id<<1|1];
	d1[id]=d1[id<<1]|d1[id<<1|1];
}
void upd(int id,int l,int r,int a,int b,int x){
	if(r<a||b<l)return;
	if(a<=l&&r<=b){
		push(id,x);
		return;
	}
	pushdown(id);
	int mid=(l+r)>>1;
	upd(id<<1,l,mid,a,b,x),upd(id<<1|1,mid+1,r,a,b,x);
	pushup(id);
}
int got(int id,int l,int r){
	if(l==r)return l;
	int mid=(l+r)>>1;
	pushdown(id);
	if(d0[id<<1])return got(id<<1,l,mid);
	return got(id<<1|1,mid+1,r);
}
int main(){
	scanf("%d",&q);
	all.push_back(0);
	all.push_back(1);
	for(int i=1;i<=q;i++)scanf("%d%I64d%I64d",&op[i],&l[i],&r[i]),all.push_back(l[i]),all.push_back(r[i]+1);
	sort(all.begin(),all.end()),all.erase(unique(all.begin(),all.end()),all.end());
	m=all.size()-1;
	built(1,m,1);
	for(int i=1;i<=q;i++){
		int L=lower_bound(all.begin(),all.end(),l[i])-all.begin();
		int R=lower_bound(all.begin(),all.end(),r[i]+1)-all.begin()-1;
		upd(1,1,m,L,R,op[i]);
		printf("%I64d\n",all[got(1,1,m)]);
	}
}