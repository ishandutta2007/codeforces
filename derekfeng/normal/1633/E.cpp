#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=1e9;
struct edge{int u,v,w,i;};
int n,m;
vector<edge>E;
bool cmp(edge A,edge B){
	if(A.w!=B.w)return A.w<B.w;
	return A.i<B.i;
}
int L[100005],R[100005];
int f[100005];
int F(int x){return f[x]==x?x:f[x]=F(f[x]);}
bool merge(int u,int v){
	u=F(u),v=F(v);
	if(u==v)return 0;
	f[u]=v;return 1;
}
vector<edge>s;
vector<int>all;
int k[200005];
ll b[200005];
ll ask(int w){
	int p=upper_bound(all.begin(),all.end(),w)-all.begin()-1;
	return (ll)k[p]*w+b[p];
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		int u,v,w;scanf("%d%d%d",&u,&v,&w);
		E.push_back((edge){u,v,w,i});
		L[i]=0,R[i]=INF;
	}
	sort(E.begin(),E.end(),cmp);
	for(auto x:E){
		iota(f+1,f+n+1,1);
		vector<edge>t;
		merge(x.u,x.v),t.push_back(x);
		for(auto y:s){
			if(merge(y.u,y.v))t.push_back(y);
			else{
				int T=(y.w+x.w+1)/2;
				R[y.i]=T-1,L[x.i]=T;
			}
		}
		swap(s,t);
	}
	for(auto x:E)all.push_back(x.w),all.push_back(L[x.i]),all.push_back(R[x.i]+1);
	sort(all.begin(),all.end()),all.erase(unique(all.begin(),all.end()),all.end());
	for(auto x:E){
		int ld=lower_bound(all.begin(),all.end(),L[x.i])-all.begin();
		int md=lower_bound(all.begin(),all.end(),x.w)-all.begin();
		int rd=lower_bound(all.begin(),all.end(),R[x.i]+1)-all.begin();
		if(ld>=rd)continue;
		if(ld<md){
			k[ld]--,b[ld]+=x.w;
			k[md]++,b[md]-=x.w;
		}
		if(md<rd){
			k[md]++,b[md]-=x.w;
			k[rd]--,b[rd]+=x.w;
		}
	}
	for(int i=1;i<all.size();i++)k[i]+=k[i-1],b[i]+=b[i-1];
	ll ans=0;
	int Q,K,a,b,c,z;scanf("%d%d%d%d%d",&Q,&K,&a,&b,&c);
	for(int i=1;i<=Q;i++)scanf("%d",&z),ans^=ask(z);
	for(int i=Q+1;i<=K;i++)z=((ll)z*a+b)%c,ans^=ask(z);
	printf("%lld",ans);
}