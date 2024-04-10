#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,s[100004];
int l[100004],r[100004];
vector<int>t[100004];
int tg[263000],dat[263000];
ll ans;
void push(int i,int len){
	tg[i]^=1,dat[i]=len-dat[i];
}
void pushdown(int i,int l,int r){
	if(tg[i]){
		int md=(l+r)>>1;
		push(i<<1,md-l+1);
		push(i<<1|1,r-md);
		tg[i]=0;
	}
}
void pushup(int i){
	dat[i]=dat[i<<1]+dat[i<<1|1];
}
void upd(int i,int l,int r,int a,int b){
	if(r<a||b<l)return;
	if(a<=l&&r<=b){
		push(i,r-l+1);
		return;
	}
	pushdown(i,l,r);
	int md=(l+r)>>1;
	upd(i<<1,l,md,a,b),upd(i<<1|1,md+1,r,a,b);
	pushup(i);
}
int qry(int i,int l,int r,int a,int b){
	if(r<a||b<l)return 0;
	if(a<=l&&r<=b)return dat[i];
	pushdown(i,l,r);
	int md=(l+r)>>1;
	return qry(i<<1,l,md,a,b)+qry(i<<1|1,md+1,r,a,b);
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&s[i]);
	sort(s+1,s+n+1);
	for(int i=1;i<=m;i++){
		int a,b;scanf("%d%d",&a,&b);
		l[i]=lower_bound(s+1,s+n+1,a)-s;
		r[i]=upper_bound(s+1,s+n+1,b)-s-1;
	}
	for(int i=1;i<=m;i++){
		if(r[i]<l[i])continue;
		if(r[i]<0||l[i]>n)continue;
		t[l[i]].push_back(i);
		t[r[i]+1].push_back(i);
	}
	for(int i=1;i<=n;i++){
		for(auto x:t[i])
			upd(1,1,n,l[x],r[x]);
		if(i>0)upd(1,1,n,1,i-1);
		int tmp=(i==0?0:qry(1,1,n,1,i-1))+(i==n?0:qry(1,1,n,i+1,n));
		ans+=(ll)tmp*(tmp-1)/2;
		if(i>0)upd(1,1,n,1,i-1);
	}
	printf("%lld",(ll)n*(n-1)*(n-2)/6-ans);
}