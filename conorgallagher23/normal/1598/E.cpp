#include<bits/stdc++.h>
#define ll long long
#define N 2005
#define mp make_pair
#define pii pair<int,int>
#define pb push_back
#define fi first
#define se second
using namespace std;
int n,m,q,id[N][N],zzx,cnt,a[N][N],l[N];
ll ans;
vector<pii>rv[N*N];
set<int>s[N];
ll calc(ll x){
	return x*(x+1ll)/2ll-x;
}
int pre(int t,int pos){
	auto it=s[t].lower_bound(pos);
	it--;
	return *it;
}
int nxt(int t,int pos){
	auto it=s[t].upper_bound(pos);
	return *it;
}
void del(int x,int y){
	int tmp=id[x][y];
	for(auto uu:rv[tmp]){
		int t=uu.fi,pos=uu.se,l=pre(t,pos),r=nxt(t,pos);
		ans-=calc(r-l-1);
		ans+=calc(pos-l-1);
		ans+=calc(r-pos-1);
		s[t].insert(pos);
	}
}
void ins(int x,int y){
	int tmp=id[x][y];
	for(auto uu:rv[tmp]){
		int t=uu.fi,pos=uu.se,l=pre(t,pos),r=nxt(t,pos);
		ans+=calc(r-l-1);
		ans-=calc(pos-l-1);
		ans-=calc(r-pos-1);
		s[t].erase(pos);
	}
}
int main(){
	cin>>n>>m>>q;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)id[i][j]=++zzx,a[i][j]=1,ans++;
	for(int ii=1;ii<=n;ii++)
		for(int jj=1,op;jj<=m;jj++){
			int i=ii,j=jj;
			if(ii==1){
				op=0,cnt++;
				while(i<=n&&j<=m){
					l[cnt]++;
					rv[id[i][j]].pb(mp(cnt,l[cnt]));
					if(op&1)i++;
					else j++;
					op^=1;
				}
			}
			i=ii;j=jj;
			if(jj==1){
				op=1,cnt++;
				while(i<=n&&j<=m){
					l[cnt]++;
					rv[id[i][j]].pb(mp(cnt,l[cnt]));
					if(op&1)i++;
					else j++;
					op^=1;
				}
			}
		}
	for(int i=1;i<=cnt;i++)s[i].insert(0),s[i].insert(l[i]+1),ans+=calc(l[i]);
	while(q--){
		int x,y;cin>>x>>y;
		a[x][y]^=1;
		if(!a[x][y])del(x,y),ans--;
		else ins(x,y),ans++;
		cout<<ans<<'\n';	
	}
	return 0;
}