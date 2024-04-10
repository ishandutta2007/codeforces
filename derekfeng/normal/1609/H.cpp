#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second
int n,K,q,a[1005];
ll t[1005],ans[1005];
int f[105][55],TT,N;
pair<pii,int>sta[105];
vector<ll>Process(vector<ll>pos,ll turns){
	vector<int>F;
	vector<ll>ans;
	for(int i=0;i<n;i++)F.push_back(f[i][turns%K]);
	N=0;
	for(int i=0;i<n;i++){
		sta[++N]={{i,i},F[i]};
		for(;;){
			if(N<2)break;
			pair<pii,int> p=sta[N--];
			pair<pii,int> q=sta[N--];
			if(pos[q.fi.se]+1==pos[p.fi.fi]&&(q.se>0||p.se<0)){
				p.fi.fi=q.fi.fi;
				p.se+=q.se;
				sta[++N]=p;
			}else{
				sta[++N]=q,sta[++N]=p;
				break;
			}
		}
	}
	for(int i=2;i<=N;i++){
		if(pos[sta[i-1].fi.se]+1==pos[sta[i].fi.fi]-1&&(sta[i-1].se>0&&sta[i].se<0)){
			int X=sta[i-1].se,Y=sta[i].se;
			if(abs(X)<=abs(Y))sta[i-1].se=0;
			else sta[i].se=0;
		}
	}
	for(int i=1;i<=N;i++){
		int L=sta[i].fi.fi,R=sta[i].fi.se;
		int X=sta[i].se;
		if(X<0)for(int i=L;i<=R;i++)ans.push_back(pos[i]-1);
		if(X==0)for(int i=L;i<=R;i++)ans.push_back(pos[i]);
		if(X>0)for(int i=L;i<=R;i++)ans.push_back(pos[i]+1);
	}
	return ans;
}
ll del[105];
vector<ll>pos;
ll Nxt;
int main(){
	scanf("%d%d",&n,&K);
	for(int i=1,x;i<=n;i++)scanf("%d",&x),pos.push_back(x);
	for(int i=0;i<n;i++)for(int j=0;j<K;j++)scanf("%d",&f[i][j]);
	scanf("%d",&q);
	for(int i=1;i<=q;i++)scanf("%d%lld",&a[i],&t[i]),--a[i];
	vector<pair<ll,int> >qry;
	for(int i=1;i<=q;i++)qry.push_back({t[i],i});
	sort(qry.begin(),qry.end());
	ll cur=0;int iter=0;
	Nxt=0;
	while(iter<qry.size()){
		ll lst=cur;
		ll Nxt1=qry[iter].fi/K;
		if(Nxt1<Nxt)cur=Nxt1;
		else cur=Nxt;
		for(int i=0;i<n;i++)pos[i]+=(cur-lst)*del[i];
		vector<ll>npos=pos;
		for(ll T=cur*K;T<(cur+1)*K;T++){
			if(iter==qry.size())break;
			while(iter<qry.size()&&qry[iter].fi==T){
				int i=qry[iter].se;
				ans[i]=pos[a[i]],iter++;
			}
			pos=Process(pos,T);
		}
		if(iter==qry.size())break;
		cur++;
		vector<ll>d1,d2;
		for(int i=1;i<n;i++)d1.push_back(npos[i]-npos[i-1]),d2.push_back(pos[i]-pos[i-1]);
		ll P=1e18;
		for(int i=0;i<n-1;i++){
			if(d1[i]-d2[i]!=0&&d2[i]<=K*2+2)P=0;
			else if(d1[i]-d2[i]>0){
				ll T=(d2[i]-K*2-2)/(d1[i]-d2[i]);
				P=min(P,T);
			}
		}
		Nxt=cur+P;
		for(int i=0;i<n;i++)del[i]=pos[i]-npos[i];
	}
	for(int i=1;i<=q;i++)printf("%lld\n",ans[i]);
}