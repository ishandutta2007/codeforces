#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define fi first
#define se second
const int M=1e9+7;
int n,m,K;
vector<pii>add[1000005],del[1000005];
set<pii>st;
bool tg[2097200];
int sum[2097200];
void upd(int i,int l,int r,int p,int x){
	if(l==r){
		sum[i]=x;
		return;
	}
	if(tg[i]){
		tg[i<<1]=tg[i<<1|1]=1;
		sum[i<<1]=sum[i<<1|1]=0;
		tg[i]=0;
	}
	int mid=(l+r)>>1;
	if(p<=mid)upd(i<<1,l,mid,p,x);
	else upd(i<<1|1,mid+1,r,p,x);
	sum[i]=(sum[i<<1]+sum[i<<1|1])%M;
}
void clr(int i,int l,int r,int a,int b){
	if(r<a||b<l)return;
	if(a<=l&&r<=b){
		tg[i]=1;
		sum[i]=0;
		return;
	}
	if(tg[i]){
		tg[i<<1]=tg[i<<1|1]=1;
		sum[i<<1]=sum[i<<1|1]=0;
		tg[i]=0;
	}
	int mid=(l+r)>>1;
	clr(i<<1,l,mid,a,b),clr(i<<1|1,mid+1,r,a,b);
	sum[i]=(sum[i<<1]+sum[i<<1|1])%M;
}
int qry(int i,int l,int r,int a,int b){
	if(r<a||b<l)return 0;
	if(a<=l&&r<=b)return sum[i];
	if(tg[i]){
		tg[i<<1]=tg[i<<1|1]=1;
		sum[i<<1]=sum[i<<1|1]=0;
		tg[i]=0;
	}
	int mid=(l+r)>>1;
	return (qry(i<<1,l,mid,a,b)+qry(i<<1|1,mid+1,r,a,b))%M;
}
int main(){
	scanf("%d%d%d",&n,&m,&K);
	for(int i=1;i<=K;i++){
		int X1,Y1,X2,Y2;
		scanf("%d%d%d%d",&X1,&Y1,&X2,&Y2);
		add[X1].push_back({Y1,Y2});
		del[X2+1].push_back({Y1,Y2});
	}
	st.insert({0,0});
	for(auto x:add[1])st.insert(x);
	upd(1,1,m,1,1);
	for(int i=2;i<=n;i++){
		sort(add[i].begin(),add[i].end(),greater<pii>());
		for(auto [x,y]:add[i]){
			if(y==m)continue;
			auto it=--st.lower_bound({y+2,0});
			int ans=0;
			auto sg=*it;
			if(sg.se<=y)ans=qry(1,1,m,sg.se+1,y+1);
			upd(1,1,m,y+1,ans);
		}
		for(auto x:del[i])st.erase(x);
		for(auto [x,y]:add[i]){
			st.insert({x,y});
			clr(1,1,m,x,y);
		}
	}
	auto it=--st.end();
	printf("%d",qry(1,1,m,(*it).se+1,m));
}