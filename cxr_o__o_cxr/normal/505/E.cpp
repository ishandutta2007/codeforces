//starusc
#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int read(){
	int x=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<1)+(x<<3)+(c^48);c=getchar();}
	return f==1?x:-x;
}
const int N=1e5+4;
int n,m,k,p,mx,a[N],h[N],c[N];
priority_queue<pair<int,int> >q;
inline bool check(int ed){
	memset(c,0,sizeof(c));
	while(!q.empty())q.pop();
	for(int i=1;i<=n;i++)
		if(ed-h[i]<a[i]*m)q.push(make_pair(-ed/a[i],i));
	for(int i=1,x,d;i<=m&&!q.empty();i++){
		for(int j=1;j<=k&&!q.empty();j++){
			d=-q.top().first;x=q.top().second;q.pop();
			if(d<i)return 0;
			++c[x];
			if(ed-h[x]+c[x]*p<a[x]*m)q.push(make_pair(-(ed+c[x]*p)/a[x],x));
		}
	}
	return q.empty();
}
signed main(){
	n=read();m=read();k=read();p=read();
	for(int i=1;i<=n;i++){
		h[i]=read();a[i]=read();
		mx=max(mx,h[i]+a[i]*m);
	} 
	int l=0,r=mx,mid;
	while(l<r){
		mid=(l+r)>>1;
		if(check(mid))r=mid;
		else l=mid+1;
	} 
	cout<<r;
	return (0-0);
}