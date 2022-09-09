#include <bits/stdc++.h>
#define rep(i,n) for(i=1;i<=(n);i++)
#define rep0(i,n) for(i=0;i<(n);i++)
using namespace std;
long long ans;
int n,m,i,j,lg[200005],lim,al[200005],ar[200005];
int a[200005],b[200005];
int f[200005][19],g[200005][19];
int fmi(int x,int y){return a[x]>a[y]?x:y;}
int gmi(int x,int y){return b[x]<b[y]?x:y;}
int qryf(int l,int r){
	int t=lg[r-l+1];
	return fmi(f[l][t],f[r-(1<<t)+1][t]);
}
int qryg(int l,int r){
	int t=lg[r-l+1];
	return gmi(g[l][t],g[r-(1<<t)+1][t]);
}
priority_queue<pair<int,int> > pq;
int ord[200005];bool cmp(int x,int y){if(a[x]==a[y]) return x>y;return a[x]<a[y];}
set<pair<int,int> > s;
vector<int> all;
int c[200005];
void add(int x,int y){
	while(x<=m){
		c[x]+=y;x+=(x&-x);
	} 
}
int query(int x){
	int s=0;
	while(x){
		s+=c[x];x-=(x&-x);
	} 
	return s; 
}
void add_rng(int l,int r,int y){
	int x=qryg(l,r);
	add(upper_bound(all.begin(),all.end(),b[x])-all.begin(),y);
}
void del(int x){
	set<pair<int,int> >::iterator it=s.upper_bound(make_pair(x,123456789));it--;
	int l=it->first,r=it->second;s.erase(it);add_rng(l,r,-1);
	if(l<x){s.insert(make_pair(l,x-1));add_rng(l,x-1,1);}
	if(x<r){s.insert(make_pair(x+1,r));add_rng(x+1,r,1);}
}
int solve(int x){
	return query(upper_bound(all.begin(),all.end(),x)-all.begin()); 
}
int main(){
	scanf("%d%d%d",&n,&m,&lim);for(i=2;i<=200002;i++)lg[i]=lg[i/2]+1;
	rep(i,n)scanf("%d",&a[i]);rep(i,m)scanf("%d",&b[i]);
	rep(i,m) all.push_back(b[i]);sort(all.begin(),all.end());all.resize(unique(all.begin(),all.end())-all.begin());
	rep(i,n)f[i][0]=i;rep(i,m)g[i][0]=i;
	rep(j,18)rep(i,n-(1<<j)+1) f[i][j]=fmi(f[i][j-1],f[i+(1<<(j-1))][j-1]);
	rep(j,18)rep(i,m-(1<<j)+1) g[i][j]=gmi(g[i][j-1],g[i+(1<<(j-1))][j-1]);
	rep(i,m){
		pq.push(make_pair(b[i],i));
	}
	rep(i,n)ord[i]=i;sort(ord+1,ord+n+1,cmp);
	vector<int> stk;
	rep(i,n){
		while(!stk.empty()&&a[stk.back()]>=a[i]){
			ar[stk.back()]=i;stk.pop_back();
		}stk.push_back(i);
	}
	stk.clear();
	for(i=n;i>=1;i--){
		while(!stk.empty()&&a[stk.back()]>a[i]){
			al[stk.back()]=i;stk.pop_back();
		}stk.push_back(i);
	}
	stk.clear();
	s.insert(make_pair(1,m));add_rng(1,m,1);
	rep(i,n){
		int x=ord[i];
		while(!pq.empty()&&pq.top().first+a[x]>lim){
			del(pq.top().second);pq.pop();
		}
		int limr=lim-a[x];
		int liml=0;
		if(al[x]){
			int t=qryf(al[x],x);
			liml=max(liml,lim-a[t]);
		}
		if(ar[x]){
			int t=qryf(x,ar[x]);
			liml=max(liml,lim-a[t]);
		}
		if(liml<=limr){
			ans+=solve(limr);
			ans-=solve(liml);
		}
	}
	cout<<ans<<endl;
	return 0;
}