#include <iostream>
#include <cstdio>
#include <map>
#include <queue>
#define int long long
using namespace std;
struct node{
	int pos,dis;
	bool operator <(const node &x)const{
		return x.dis<dis;
	} 
}res;
map <long long,long long>a;
priority_queue <node>h;
int n,m,x[1000005],ans,tot,y[1000005];
signed main(){
//	freopen("1283D.in","r",stdin);
//	freopen("1283D.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		scanf("%I64d",&x[i]);
		a[x[i]]=1ll;
	}
	for (int i=1;i<=n;i++){
		if (a[x[i]-1]==0){
			res.dis=1,res.pos=x[i]-1;
			h.push(res);
			a[x[i]-1]=1;
		}
		if (a[x[i]+1]==0){
			res.dis=1,res.pos=x[i]+1;
			h.push(res);
			a[x[i]+1]=1ll;
		}
	}
	while(!h.empty()&&tot<m){
		node c=h.top();
		h.pop();
		ans+=c.dis;
		y[++tot]=c.pos;
		if (a[c.pos-1]==0ll){
			res.dis=c.dis+1,res.pos=c.pos-1;
			h.push(res);
			a[res.pos]=1ll;
		}
		if (a[c.pos+1]==0ll){
			res.dis=c.dis+1,res.pos=c.pos+1;
			h.push(res);
			a[res.pos]=1;
		}
	}
	cout<<ans<<endl;
	for (int i=1;i<=m;i++)printf("%I64d ",y[i]);
	return 0;
}