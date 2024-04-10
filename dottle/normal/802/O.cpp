#include<bits/stdc++.h>
#define int long long
#define mid ((l+r)>>1)
const int N=1000050;
using namespace std;

int a[N],b[N],n,m,l=-2e9,r=2e9,ans=-2e9,res,c;

struct node{
	int x,t;
	bool operator<(node b)const{return x==b.x?t<b.t:x>b.x;}
};

int chk(int k){	
	priority_queue<node> q;
	c=0,res=0;
	for(int i=1;i<=n;i++){
		q.push((node){a[i],1});
		if(q.top().x+b[i]+k<=0){
			res+=q.top().x+b[i]+k,c+=q.top().t;
			q.pop(),q.push((node){-b[i]-k,0});
		}
	}
	return c;
}

main(){
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	for(int i=1;i<=n;i++)scanf("%lld",&b[i]);
	while(l<=r)
		if(chk(mid)>=m)ans=mid,l=mid+1;
		else r=mid-1;
	chk(ans);
	printf("%lld",res-ans*m); 
}