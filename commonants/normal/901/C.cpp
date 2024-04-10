#include<bits/stdc++.h>

using namespace std;

const int MX=600005,inf=0x3f3f3f3f;
int n,m,q;
vector<int>G[MX];
pair<pair<int,int>,int>Q[MX];
#define pb push_back

int stk[MX],stc,vis[MX],instk[MX];
int mxr[MX];
vector<pair<int,int>>odr;
void dfs(int k,int f){
	stk[++stc]=k;vis[k]=1;instk[k]=1;
	for(auto i:G[k])if(i!=f){
		if(vis[i]){
			if(instk[i]){
				int mn=i,mx=i;
				for(int j=stc;stk[j]!=i;j--)mn=min(mn,stk[j]),mx=max(mx,stk[j]);
				odr.pb(make_pair(mn,mx));
			}
		}else dfs(i,k);
	}
	stk[stc--]=0;instk[k]=0;
}
typedef long long LL;
LL ans[MX];
struct seg{
	int ad;LL s;
}sg[1049233];
inline void add(int no,int d,int l){sg[no].ad+=d,sg[no].s+=(LL)d*l;}
inline void psdw(int no,int l,int r,int mid){
	if(sg[no].ad){int d=sg[no].ad;sg[no].ad=0,add(no<<1,d,mid-l+1),add(no<<1|1,d,r-mid);}
}
inline void psup(int no){sg[no].s=sg[no<<1].s+sg[no<<1|1].s;}
inline void add(int no,int l,int r,int ll,int rr,int d){
	if(ll>rr)return;
	if(ll<=l&&rr>=r)add(no,d,r-l+1);
	else{
		int mid=(l+r)>>1;
		psdw(no,l,r,mid);
		if(ll<=mid)add(no<<1,l,mid,ll,rr,d);
		if(rr>mid)add(no<<1|1,mid+1,r,ll,rr,d);
		psup(no);
	}
}
inline LL que(int no,int l,int r,int ll,int rr){
	if(ll<=l&&rr>=r)return sg[no].s;
	else{
		int mid=(l+r)>>1;
		psdw(no,l,r,mid);
		LL ans=0;
		if(ll<=mid)ans+=que(no<<1,l,mid,ll,rr);
		if(rr>mid)ans+=que(no<<1|1,mid+1,r,ll,rr);
		return ans;
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int a,b;cin>>a>>b;
		G[a].pb(b),G[b].pb(a);
	}
	for(int i=1;i<=n;i++)if(!vis[i])dfs(i,0);
	//for(auto i:odr)cout<<i.first<<' '<<i.second<<endl;
	for(int i=1;i<=n;i++)mxr[i]=n;
	for(auto i:odr)mxr[i.first]=min(mxr[i.first],i.second-1);
	for(int i=n-1;i;i--)mxr[i]=min(mxr[i],mxr[i+1]);
	//for(int i=1;i<=n;i++)cout<<mxr[i]<<endl;
	cin>>q;
	for(int i=1;i<=q;i++)cin>>Q[i].first.first>>Q[i].first.second,Q[i].second=i;
	sort(Q+1,Q+q+1);
	int it=n;
	for(int i=q;i;i--){
		while(it>=Q[i].first.first)add(1,1,n,it,mxr[it],1),it--;
		ans[Q[i].second]=que(1,1,n,Q[i].first.first,Q[i].first.second);
	}
	for(int i=1;i<=q;i++)cout<<ans[i]<<endl;
	return 0;
}