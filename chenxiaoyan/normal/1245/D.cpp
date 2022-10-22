/*




D P 




 l l
*/
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define mp make_pair
#define X first
#define Y second
#define pb push_back
const int N=2000;
int n;
int x[N+1],y[N+1];
int a[N+1],b[N+1];
vector<pair<int,pair<int,int> > > eg;
struct ufset{
	int fa[N+2];
	void init(){memset(fa,0,sizeof(fa));}
	int root(int x){return fa[x]?fa[x]=root(fa[x]):x;}
	void merge(int x,int y){fa[root(x)]=root(y);}
	bool same(int x,int y){return root(x)==root(y);}
}ufs;
signed main(){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>x[i]>>y[i];
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)cin>>b[i];
	for(int i=1;i<=n;i++)for(int j=i+1;j<=n;j++){
		int len=(b[i]+b[j])*(abs(x[i]-x[j])+abs(y[i]-y[j]));
		eg.pb(mp(len,mp(i,j)));
	}
	for(int i=1;i<=n;i++)eg.pb(mp(a[i],mp(i,n+1)));
	sort(eg.begin(),eg.end());
	int ans=0;vector<int> v1;vector<pair<int,int> > v2;
	for(int i=0;i<eg.size();i++)if(!ufs.same(eg[i].Y.X,eg[i].Y.Y)){
		ans+=eg[i].X;
		if(eg[i].Y.Y==n+1)v1.pb(eg[i].Y.X);
		else v2.pb(eg[i].Y);
		ufs.merge(eg[i].Y.X,eg[i].Y.Y);
	}
	cout<<ans<<"\n"<<v1.size()<<"\n";
	for(int i=0;i<v1.size();i++)cout<<v1[i]<<" ";puts("");
	cout<<v2.size()<<"\n";
	for(int i=0;i<v2.size();i++)cout<<v2[i].X<<" "<<v2[i].Y<<"\n";
	return 0;
}