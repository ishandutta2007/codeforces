#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
#define fi first
#define se second
const int M=998244353;
int n,X[55],Y[55],t,ans;
vector<int>all;
vector<pair<pii,int> >seg[105];
int d[105][105];
int getarea(int T){
	int ans=0;
	vector<int>ax,ay;
	for(int i=1;i<=n;i++)ax.push_back(X[i]-T),ax.push_back(X[i]+T+1),ay.push_back(Y[i]-T),ay.push_back(Y[i]+T+1);
	sort(ax.begin(),ax.end()),ax.erase(unique(ax.begin(),ax.end()),ax.end());
	sort(ay.begin(),ay.end()),ay.erase(unique(ay.begin(),ay.end()),ay.end());
	for(int i=0;i<ax.size();i++)seg[i].clear();
	memset(d,0,sizeof(d));
	for(int i=1;i<=n;i++){
		int lb=lower_bound(ax.begin(),ax.end(),X[i]-T)-ax.begin();
		int rb=lower_bound(ax.begin(),ax.end(),X[i]+T+1)-ax.begin();
		int ub=lower_bound(ay.begin(),ay.end(),Y[i]-T)-ay.begin();
		int db=lower_bound(ay.begin(),ay.end(),Y[i]+T+1)-ay.begin();
		seg[lb].push_back({{ub,db},1});
		seg[rb].push_back({{ub,db},-1});
	}
	for(int i=0;i<ax.size()-1;i++){
		if(i>0)memcpy(d[i],d[i-1],sizeof(d[i]));
		for(auto x:seg[i])for(int j=x.fi.fi;j<x.fi.se;j++)d[i][j]+=x.se;
		for(int j=0;j<ay.size()-1;j++)if(d[i][j]>0)(ans+=(ll)(ax[i+1]-ax[i])*(ay[j+1]-ay[j])%M)%=M;
	}
	return ans;
}
int mypow(int x,int t){
	int ans=1,ret=x;
	for(;t;ret=(ll)ret*ret%M,t>>=1)if(t&1)ans=(ll)ans*ret%M;
	return ans;
}
int rgrg(const vector<pii>&x,int k){
	int ans=0;
	for(int i=0;i<4;i++){
		int s1=1,s2=1;
		for(int j=0;j<4;j++)if(i!=j)
			s1=((ll)s1*(k-x[j].fi)%M+M)%M,s2=((ll)s2*(x[i].fi-x[j].fi)%M+M)%M;
		s1=((ll)s1*x[i].se%M+M)%M;
		s1=(ll)s1*mypow(s2,M-2)%M;
		ans=(ans+s1)%M;
	}
	return ans;
}
int main(){
	scanf("%d%d",&n,&t);
	for(int i=1;i<=n;i++)scanf("%d%d",&X[i],&Y[i]);
	all.push_back(0),all.push_back(t+1);
	for(int i=1;i<=n;i++)for(int j=i+1;j<=n;j++){
		int dx=abs(X[i]-X[j]),dy=abs(Y[i]-Y[j]);
		int tx=max((dx+1)/2,(dy+1)/2);
		if(tx<=t)all.push_back(tx);
	}
	sort(all.begin(),all.end()),all.erase(unique(all.begin(),all.end()),all.end());
	for(int q=0;q<all.size()-1;q++){
		int L=all[q],R=all[q+1];
		if(R-L<=4)for(int i=L;i<R;i++)(ans+=getarea(i))%=M;
		else{
			vector<pii>tmp;
			int sum=0;
			for(int j=0;j<4;j++){
				(sum+=getarea(L+j))%=M;
				tmp.push_back({L+j,sum});
			}
			(ans+=rgrg(tmp,R-1))%=M;
		}
	}
	printf("%d",((ll)getarea(t)*(t+1)%M-ans+M)%M);
}