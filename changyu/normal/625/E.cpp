#include<bits/stdc++.h>
#define int long long
const int N=1e5+3;
int n,m,a[N],v[N],r[N],x[N],l[N];
struct node{
	int p;
	bool operator<(const node&b)const{return a[p]<a[b.p];}
};
std::set<node>p;
typedef std::set<node>::iterator iterp;
struct edge{
	int p;
	bool operator<(const edge&b)const{return r[p]==r[b.p]?p<b.p:r[p]<r[b.p];}
};
std::set<edge>q;
typedef std::set<edge>::iterator iterq;
inline int Find_next(int i){
	iterp it=p.upper_bound((node){i});
	if((*it).p==n+1)it=p.upper_bound((node){0});
	return(*it).p;
}
inline int Find_last(int i){
	iterp it=p.lower_bound((node){i});--it;
	if((*it).p==0)it=p.lower_bound((node){n+1}),--it;
	return(*it).p;
}
inline int Calc(int i,int j){return(x[j]-x[i]+(a[j]<a[i])*m+l[i]*v[i]-(l[j]+(j>i))*v[j]+v[i]-v[j]-1)/(v[i]-v[j]);}
signed main(){
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
	  scanf("%lld%lld",a+i,v+i);
	  p.insert((node){i});
	  x[i]=a[i],l[i]=0;
	}
	a[0]=0,a[n+1]=m+1;
	p.insert((node){0}),p.insert((node){n+1});
	for(int i=1,j;i<=n;i++){
	  j=Find_next(i);
	  if(i<j&&a[i]+v[i]>=a[j]+(a[j]<a[i])*m)r[i]=1,q.insert((edge){i});
	  else if(v[i]>v[j])r[i]=Calc(i,j),q.insert((edge){i});
	}
	for(int i,j;!q.empty();){
	  i=(*q.begin()).p,q.erase(q.begin());
	  x[i]+=(r[i]-l[i])*v[i],l[i]=r[i];
	  for(;;){
		j=Find_next(i);
		if(j==i)goto Brk;
		if(x[i]<x[j]+(r[i]-(j>i)-l[j])*v[j]+(a[j]<a[i])*m){
		  if(v[i]>v[j])r[i]=Calc(i,j),q.insert((edge){i});
		  j=Find_last(i);
		  if(j==i)goto Brk;
		  if(q.count((edge){j}))q.erase((edge){j});
		  if(v[j]>v[i])r[j]=Calc(j,i),q.insert((edge){j});
		  break;
		}
		--v[i];
		p.erase((node){j});
		if(q.count((edge){j}))q.erase((edge){j});
	  }
	}
	Brk:;
	printf("%d\n",p.size()-2);
	for(iterp it=p.begin();it!=p.end();++it)(*it).p>=1&&(*it).p<=n&&printf("%lld ",*it);puts("");
	return 0;
}