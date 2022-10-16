#include <iostream>
#include <cstdio> 
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
#include <queue>
#define ll long long
using namespace std;
struct node{
	ll a,b;
	inline bool operator <(const node &x)const{
		return x.a/x.b<a/b;
	} 
}c;
std::priority_queue <node>q;
int n,k;
ll a[200005],b[200005];
inline bool check(register ll x){
	while(!q.empty())q.pop();
	for (register int i=1;i<=n;i++)
		if (a[i]/b[i]<k-1)q.push((node){a[i],b[i]});
	for (register int i=1;i<=k&&!q.empty();i++){
		c=q.top();
		if (c.a/c.b<i-1)return 0;
		if (i==k)return 1;
		q.pop();
		if ((c.a+x)/c.b<k-1)q.push((node){c.a+x,c.b});
	}
	return 1;
}
inline ll read(){
	register ll x=0;
	register char ch=getchar();
	while(ch>'9'||ch<'0')ch=getchar();
	while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
	return x;
}
signed main(){
	cin>>n>>k;
	for (register int i=1;i<=n;i++)a[i]=read();
	for (register int i=1;i<=n;i++)b[i]=read();
	register ll l=0,r=0,ans=-1;
	for (register int i=1;i<=n;i++)r=max(r,b[i]*(k-1));
	while(l<=r){
		register ll mid=(l+r)>>1;
		if (check(mid))ans=mid,r=mid-1;
		else l=mid+1;
	}
	cout<<ans<<endl;
}