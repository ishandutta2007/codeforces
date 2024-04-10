#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector>
#define sheap priority_queue<Node,vector<Node>,cmp1>
#define bheap priority_queue<Node,vector<Node>,cmp2>
using namespace std;
typedef long long ll;
const ll MAXN=3e5+10,INF=2e18;
ll n,w,a[MAXN],b[MAXN],ans;
ll op[MAXN];
struct Node{
	ll idx,v;
};
struct cmp1{
	bool operator()(const Node& n1,const Node& n2){
		return n1.v>n2.v; // 
	}
};	
struct cmp2{
	bool operator()(const Node& n1,const Node& n2){
		return n1.v<n2.v; // 
	}
};
sheap q1,q2,q3;
bheap q4,q5;
int main(){
	scanf("%lld%lld",&n,&w);
	for(int i=1;i<=n;i++){
		scanf("%lld%lld",&a[i],&b[i]);
		q1.push((Node){i,a[i]});
		q3.push((Node){i,b[i]});
	}
	for(int i=1;i<=w;i++){
		ll minn=INF,cs=0;
		// 
		while(!q1.empty() && op[q1.top().idx]!=0)q1.pop();
		while(!q2.empty() && op[q2.top().idx]!=1)q2.pop();
		while(!q3.empty() && op[q3.top().idx]!=0)q3.pop();
		while(!q4.empty() && op[q4.top().idx]!=1)q4.pop();
		while(!q5.empty() && op[q5.top().idx]!=2)q5.pop();
		//0->1
		if(!q1.empty()){
			minn=q1.top().v;
			cs=1;
		}
		//1->2
		if(!q2.empty()){
			if(q2.top().v<minn){
				minn=q2.top().v;
				cs=2;
			}
		}
		//0->2 && 1->0
		if(!q3.empty() && !q4.empty()){
			if((q3.top().v)-(q4.top().v) < minn){
				minn=(q3.top().v)-(q4.top().v);
				cs=3;
			}
		}
		//0->2 && 2->1
		if(!q3.empty() && !q5.empty()){
			if((q3.top().v)-(q5.top().v) < minn){
				minn=(q3.top().v)-(q5.top().v);
				cs=4;
			}
		}
		ans+=minn;
		if(cs==1){
			Node now=q1.top();q1.pop();
			op[now.idx]=1;
			q2.push((Node){now.idx,b[now.idx]-a[now.idx]});
			q4.push((Node){now.idx,a[now.idx]});
		}else if(cs==2){
			Node now=q2.top();q2.pop();
			op[now.idx]=2;
			q5.push((Node){now.idx,b[now.idx]-a[now.idx]});
		}else if(cs==3){
			Node now=q3.top();q3.pop();
			op[now.idx]=2;
			q5.push((Node){now.idx,b[now.idx]-a[now.idx]});
			now=q4.top();q4.pop();
			op[now.idx]=0;
			q1.push((Node){now.idx,a[now.idx]});
			q3.push((Node){now.idx,b[now.idx]});
		}else{
			Node now=q3.top();q3.pop();
			op[now.idx]=2;
			q5.push((Node){now.idx,b[now.idx]-a[now.idx]});
			now=q5.top();q5.pop();
			op[now.idx]=1;
			q2.push((Node){now.idx,b[now.idx]-a[now.idx]});
			q4.push((Node){now.idx,a[now.idx]});
		}
	}
	printf("%lld\n",ans);
	for(int i=1;i<=n;i++){
		printf("%d",op[i]);
	}
	return 0;
}