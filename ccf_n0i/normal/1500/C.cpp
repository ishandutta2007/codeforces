#include <bits/stdc++.h>
#define rep(i,n) for ((i)=1;(i)<=(n);(i)++)
#define dzd(c,itr) for (__typeof((c).begin()) itr=(c).begin();itr!=(c).end();++itr)
using namespace std;
const int e1=1e6+3,e2=1e6+33,e3=97;
const int mod1=1e9+7,mod2=1e9+9,mod3=19491001;
int n,m,i,j,a[1505][1505],b[1505][1505];
map<pair<pair<int,int>,int>,vector<int> > mp;
int vis[1505],spt[1505];
int leq[1505][1505],sme[1505][1505];
int ivl[1505];
vector<int> ans;
bool check(){
	int i,j;
	rep(i,n-1)if(!spt[i]){
		if(b[i][m+1]>b[i+1][m+1]) return 0;
	}
	return 1;
}
void inc(int l,int r,int v){
	int i;
	rep(i,m){
		if(leq[l][i]+l<r) ivl[i]+=v;
	}
}
int main(){
	scanf("%d%d",&n,&m);
	rep(i,n)rep(j,m) scanf("%d",&a[i][j]);
	for(i=n;i;i--){
		int h1=0,h2=0,h3=0;
		rep(j,m){
			h1=(1ll*h1*e1+a[i][j])%mod1;
			h2=(1ll*h2*e2+a[i][j])%mod2;
			h3=(1ll*h3*e3+a[i][j])%mod3;
		}
		mp[make_pair(make_pair(h1,h2),h3)].push_back(i);
	}
	rep(i,n)rep(j,m) scanf("%d",&b[i][j]);
	rep(i,n){
		int h1=0,h2=0,h3=0;
		rep(j,m){
			h1=(1ll*h1*e1+b[i][j])%mod1;
			h2=(1ll*h2*e2+b[i][j])%mod2;
			h3=(1ll*h3*e3+b[i][j])%mod3;
		}
		if(!mp[make_pair(make_pair(h1,h2),h3)].empty()){
			b[i][m+1]=mp[make_pair(make_pair(h1,h2),h3)].back();
			mp[make_pair(make_pair(h1,h2),h3)].pop_back();
		}
		else{
			puts("-1");
			return 0;
		}
	}
	for(i=n;i;i--){
		rep(j,m){
			if(b[i][j]==b[i+1][j]){
				sme[i][j]=sme[i+1][j]+1;
			}
			if(b[i][j]<=b[i+1][j]){
				leq[i][j]=leq[i+1][j]+1;
			}
		}
	}
	inc(1,n,1);
	while(!check()){
		rep(i,m)if(!vis[i]&&!ivl[i]){
			break;
		}
		if(i>m){
			puts("-1");
			return 0;
		}
		int t=i,lst=1;
		vis[t]=1;
		rep(i,n-1){
			if(spt[i]){
				lst=i+1;
				continue;
			}
			if(b[i][t]<b[i+1][t]){
				int tl=lst,tr=i+1;
				while(tr<n&&!spt[tr]) tr++;
				inc(tl,tr,-1);
				spt[i]=1;
				inc(tl,i,1);
				inc(i+1,tr,1);
				lst=i+1;
			}
		}
		ans.push_back(t);
	}
	printf("%d\n",ans.size());
	reverse(ans.begin(),ans.end());
	dzd(ans,it) printf("%d ",*it);
	return 0;
}