#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second
int n,q,a[200004],p[200004];
int s[200004][2],rt;
stack<int>st;
int L[200004],R[200004];
void calc(int i){
	L[i]=R[i]=i;
	if(s[i][0])calc(s[i][0]),L[i]=L[s[i][0]];
	if(s[i][1])calc(s[i][1]),R[i]=R[s[i][1]];
}
vector<pii>v[200004];
vector<pair<pii,pii> >Ent;
struct BIT{
	ll bit1[200004],bit2[200004];
	void init(){
		memset(bit1,0,sizeof(bit1));
		memset(bit2,0,sizeof(bit2));
	}
	void add(int id,ll x,ll y){
		for(;id<=n;id+=(id&-id))bit1[id]+=x,bit2[id]+=y;
	}
	void upd(int l,int r,ll x){
		add(l,x,-x*(l-1)),add(r+1,-x,x*r);
	}
	ll ask(int id){
		ll res1=0,res2=0,x=id;
		for(;id;id-=(id&-id))res1+=bit1[id],res2+=bit2[id];
		return res1*x+res2;
	}
	ll qry(int l,int r){
		return ask(r)-ask(l-1);
	}
}tr1,tr2;
vector<pii>add1[200004],add2[200004];
vector<pair<pii,int> >ask1[200004],ask2[200004];
ll ans[1000004];
int main(){
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]),p[a[i]]=i;
	for(int i=1;i<=n;i++){
		int lst=0;
		while(!st.empty()&&a[st.top()]<a[i])lst=st.top(),st.pop();
		if(!st.empty())s[st.top()][1]=i;
		s[i][0]=lst,st.push(i);
	}
	while(!st.empty())rt=st.top(),st.pop();
	calc(rt);
	for(int i=1;i<=n;i++)for(int j=1;i*j<=n;j++)if(i!=j){
		int l=min(p[i*j],min(p[i],p[j]));
		int r=max(p[i*j],max(p[i],p[j]));
		int ld=L[p[i*j]],rd=R[p[i*j]];
		if(ld>l||r>rd)continue;
		v[i*j].push_back({l,r});
	}
	for(int i=1;i<=n;i++)if(!v[i].empty()){
		vector<int>lp;map<int,int>mp;
		for(auto [l,r]:v[i]){
			lp.push_back(l);
			if(!mp.count(l))mp[l]=r;
			else mp[l]=min(mp[l],r);
		}
		sort(lp.begin(),lp.end());
		lp.erase(unique(lp.begin(),lp.end()),lp.end());
		int suf=n+1;
		for(int j=lp.size()-1;~j;j--){
			int lst=j==0?L[p[i]]:lp[j-1]+1;
			suf=min(suf,mp[lp[j]]);
			Ent.push_back({{lst,lp[j]},{suf,R[p[i]]}});
		}
	}
	for(auto [a,b]:Ent){
		add1[a.fi].push_back(b);
		add2[a.se].push_back(b);
	}
	for(int i=1;i<=q;i++){
		int l,r;scanf("%d%d",&l,&r);
		ask1[l-1].push_back({{l,r},i});
		ask2[r].push_back({{l,r},i});
	}
	tr1.init(),tr2.init();
	for(int i=1;i<=n;i++){
		for(auto [l,r]:add1[i])tr1.upd(l,r,1),tr2.upd(l,r,-(i-1));
		for(auto [l,r]:add2[i])tr1.upd(l,r,-1),tr2.upd(l,r,i);
		for(auto [rg,j]:ask1[i]){
			auto [l,r]=rg;
			ans[j]-=tr1.qry(l,r)*i+tr2.qry(l,r);
		}
		for(auto [rg,j]:ask2[i]){
			auto [l,r]=rg;
			ans[j]+=tr1.qry(l,r)*i+tr2.qry(l,r);
		}
	}
	for(int i=1;i<=q;i++)printf("%lld\n",ans[i]);
}