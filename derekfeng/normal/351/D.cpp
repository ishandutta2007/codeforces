#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define fi first
#define se second
pii operator+(const pii A,const pii B){
	return {min(A.fi,B.fi),A.se+B.se};
}
int n,q,a[100004];
int l[100004],ans[100004];
vector<int>ask[100004],v[100004];
int n_=1;
pii dat[262200];
pii upd(int i,pii x){
	i+=n_-1;
	pii ret=dat[i];
	dat[i]=x;
	while(i>1)i>>=1,dat[i]=dat[i<<1]+dat[i<<1|1];
	return ret;
}
pii qry(int i,int l,int r,int a,int b){
	if(r<a||b<l)return {n+1,0};
	if(a<=l&&r<=b)return dat[i];
	int md=(l+r)>>1;
	return qry(i<<1,l,md,a,b)+qry(i<<1|1,md+1,r,a,b);
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	scanf("%d",&q);
	for(int i=1;i<=q;i++){
		int r;scanf("%d%d",&l[i],&r);
		ask[r].push_back(i); 
	}
	while(n_<n)n_<<=1;
	for(int i=1;i<n_+n_;i++)dat[i]={n+1,0};
	for(int i=1;i<=n;i++){
		int x=a[i];pii lst;
		if(!v[x].empty()){
			int pos=v[x].back();
			lst=upd(pos,{n+1,0});
		}
		int N=v[x].size();
		v[x].push_back(i);
		if(v[x].size()<3)upd(i,{1,1});
		else{
			int d=v[x][N-2]+1;
			if(v[x][N-1]-v[x][N-2]==v[x][N]-v[x][N-1])d=lst.fi;
			upd(i,{d,1});
		}
		for(auto t:ask[i]){
			int L=l[t];
			pii tmp=qry(1,1,n_,L,i);
			ans[t]=tmp.se+(tmp.fi>L);
		}
	}
	for(int i=1;i<=q;i++)printf("%d\n",ans[i]);
}