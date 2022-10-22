#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int T,n,a[300100],LG[300100];
ll s[300100],st[300100][20],ts[300100][20],res;
int t[300100];
ll MIN(int l,int r){int k=LG[r-l+1];return min(st[l][k],st[r-(1<<k)+1][k]);}
ll MAX(int l,int r){int k=LG[r-l+1];return max(ts[l][k],ts[r-(1<<k)+1][k]);}
vector<ll>v;
vector<int>u[300100];
#define all(x) x.begin(),x.end()
void solve(int w){
	s[w-1]=0;for(int i=w;i<=n+2;i+=2){
		s[i]=s[i-1]-a[i];
		s[i+1]=s[i]+a[i+1];
	}
	for(int i=w-1;i<=n+2;i+=2)st[i][0]=s[i],st[i+1][0]=0x3f3f3f3f3f3f3f3f;
	for(int i=w;i<=n+2;i+=2)ts[i][0]=s[i],ts[i-1][0]=-0x3f3f3f3f3f3f3f3f;
	for(int j=1;j<=LG[n];j++)for(int i=w-1;i+(1<<j)-1<=n+2;i++)
		st[i][j]=min(st[i][j-1],st[i+(1<<(j-1))][j-1]),
		ts[i][j]=max(ts[i][j-1],ts[i+(1<<(j-1))][j-1]);
	for(int i=w-1;i<=n+2;i++)v.push_back(s[i]);
	sort(all(v)),v.resize(unique(all(v))-v.begin());
	for(int i=w-1;i<=n+2;i++)u[t[i]=lower_bound(all(v),s[i])-v.begin()].push_back(i);
//	for(int i=w-1;i<=n;i++)printf("%d ",t[i]);puts("");
	for(int i=w;i<=n;i+=2){
		int l=i,r=n;
		while(l<r){
			int mid=(l+r+1)>>1;
			if(MIN(i,mid)<s[i-1]||MAX(i,mid)>s[i-1])r=mid-1;
			else l=mid;
		}
		int tmp=upper_bound(all(u[t[i-1]]),l)-upper_bound(all(u[t[i-1]]),i-1);
		res+=tmp;
	}
	for(int i=0;i<v.size();i++)u[i].clear();v.clear();
}
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n),res=0;
		for(int i=2;i<=n;i++)LG[i]=LG[i>>1]+1;
		for(int i=1;i<=n;i++)scanf("%d",&a[i]);
		solve(1),solve(2);
		printf("%lld\n",res);
	}
	return 0;
}
/*
1
7
1 5 0 0 0 0 0
*/