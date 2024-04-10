#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second
#define mkp make_pair
int n,m,q;
ll ans_B,cur;
ll match[200004];
int a[200004],b[200004];
vector<pii>ga[200004],gb[200004];
ll dat[524300],mn[524300];
multiset<ll>st;
void built(int l,int r,int id){
	if(l==r){
		dat[id]=mn[id]=b[l];
		return;
	}
	int mid=(l+r)>>1;
	built(l,mid,id<<1),built(mid+1,r,id<<1|1);
	mn[id]=min(mn[id<<1],mn[id<<1|1]);
}
void upd(int l,int r,int id,int a,int b,int x){
	if(r<a||b<l)return;
	if(a<=l&&r<=b){
		dat[id]+=x,mn[id]+=x;
		return;
	}
	int mid=(l+r)>>1;
	upd(l,mid,id<<1,a,b,x),upd(mid+1,r,id<<1|1,a,b,x);
	mn[id]=min(mn[id<<1],mn[id<<1|1])+dat[id];
}
int main(){
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1;i<n;i++)scanf("%d%d",&a[i],&b[i]);
	for(int i=0;i<m;i++){
		int u,v,w;scanf("%d%d%d",&u,&v,&w);
		ga[u].push_back(mkp(v,w)),gb[v].push_back(mkp(u,w));
		ans_B+=w;
	}
	for(int i=n-1;i;i--){
		for(auto x:gb[i+1])cur+=x.se;
		ans_B=min(ans_B,cur+b[i]);
	}
	cur=0;
	for(int i=1;i<n;i++){
		for(auto x:ga[i])cur+=x.se;
		match[i]=cur;
	}
	built(1,n-1,1);
	for(int i=1;i<n;i++){
		for(auto x:ga[i])upd(1,n-1,1,1,x.fi-1,x.se);
		match[i]=min(match[i],mn[1]);
		st.insert(match[i]+a[i]);
	}
	printf("%I64d\n",min(ans_B,(*st.begin())));
	while(q--){
		int p,w;scanf("%d%d",&p,&w);
		st.erase(st.find(match[p]+a[p]));
		a[p]=w,st.insert(match[p]+w);
		printf("%I64d\n",min(ans_B,(*st.begin())));
	}
}