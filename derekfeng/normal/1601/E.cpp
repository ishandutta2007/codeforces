#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second
int st[19][300004],lg[300004];
int qry(int l,int r){
	int p=lg[r-l+1];
	return min(st[p][l],st[p][r-(1<<p)+1]);
}
int n,q,K,N;
ll ans[300004];
vector<pair<pii,int> >qr[300004];
int cur[300004];
vector<int>tmp;
vector<int>ask[1100000];
void clr(int l,int r,int i){
	ask[i].clear();
	if(l!=r){
		int mid=(l+r)>>1;
		clr(l,mid,i<<1),clr(mid+1,r,i<<1|1);
	}
}
void add(int l,int r,int i,int a,int b,int x){
	if(r<a||b<l)return;
	if(a<=l&&r<=b){
		ask[i].push_back(x);
		return;
	}
	int mid=(l+r)>>1;
	add(l,mid,i<<1,a,b,x),add(mid+1,r,i<<1|1,a,b,x);
}
void solve(int l,int r,int i){
	vector<int>v;
	vector<ll>pre;
	int w=1e9;
	ll sum=0;
	for(int i=l;i<=r;i++){
		w=min(w,qry(tmp[i]-K+1,tmp[i]));
		sum+=w;
		v.push_back(w);
		pre.push_back(sum);
	}
	for(auto x:ask[i]){
		if(cur[x]<=w){
			ans[x]+=(ll)cur[x]*(r-l+1);
			continue;
		}
		if(cur[x]>=v[0]){
			ans[x]+=(ll)pre.back();
			cur[x]=v.back();
			continue;
		}
		int lb=l-1,rb=r+1;
		while(rb>lb+1){
			int mid=(lb+rb)>>1;
			if(v[mid-l]>=cur[x])lb=mid;
			else rb=mid;
		}
		ans[x]+=(ll)(lb-l+1)*cur[x]+pre.back()-pre[lb-l];
		cur[x]=v.back();
	}
	if(l!=r){
		int mid=(l+r)>>1;
		solve(l,mid,i<<1),solve(mid+1,r,i<<1|1);
	}
}
int main(){
	scanf("%d%d%d",&n,&q,&K);
	for(int i=2;i<=n;i++)lg[i]=lg[i>>1]+1;
	for(int i=1;i<=n;i++)scanf("%d",&st[0][i]);
	for(int i=1;i<=lg[n];i++)for(int j=1;j+(1<<i)-1<=n;j++)
		st[i][j]=min(st[i-1][j],st[i-1][j+(1<<(i-1))]);
	for(int i=1;i<=q;i++){
		int l,r;scanf("%d%d",&l,&r);
		int Len=r-l;Len=Len/K*K;
		qr[l%K].push_back({{l,l+Len},i});
		cur[i]=1e9;
	}
	for(int i=0;i<K;i++){
		tmp.clear();
		for(int j=i;j<=n;j+=K)tmp.push_back(j);
		N=tmp.size();
		clr(0,N-1,1);
		for(auto x:qr[i]){
			ans[x.se]=st[0][x.fi.fi];
			cur[x.se]=st[0][x.fi.fi];
			if(x.fi.fi<x.fi.se){
				int lb=x.fi.fi+K,rb=x.fi.se;
				lb=lower_bound(tmp.begin(),tmp.end(),lb)-tmp.begin();
				rb=lower_bound(tmp.begin(),tmp.end(),rb)-tmp.begin();
				add(0,N-1,1,lb,rb,x.se);
			}
		}
		solve(0,N-1,1);
	}
	for(int i=1;i<=q;i++)printf("%I64d\n",ans[i]);
}