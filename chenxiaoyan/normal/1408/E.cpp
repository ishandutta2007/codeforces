/*





D P 




 l l
*/
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define mp make_pair
#define X first
#define Y second
const int M=100000,N=M;
int m,n;
int a[M+1],b[N+1];
vector<pair<int,pair<int,int> > > eg;
struct ufset{
	int fa[N+M+1];
	void init(){memset(fa,0,sizeof(fa));}
	int root(int x){return fa[x]?fa[x]=root(fa[x]):x;}
	void mrg(int x,int y){fa[root(x)]=root(y);}
}ufs;
signed main(){
	cin>>m>>n;
	for(int i=1;i<=m;i++)scanf("%lld",a+i);
	for(int i=1;i<=n;i++)scanf("%lld",b+i);
	int tot=0;
	for(int i=1;i<=m;i++){
		int s;
		scanf("%lld",&s);
		while(s--){
			int x;
			scanf("%lld",&x);
			eg.pb(mp(a[i]+b[x],mp(i,m+x)));
			tot+=a[i]+b[x];
		}
	}
	sort(eg.begin(),eg.end());
	reverse(eg.begin(),eg.end());
	ufs.init();
	int ans=0;
	for(int i=0;i<eg.size();i++){
		int x=eg[i].Y.X,y=eg[i].Y.Y,len=eg[i].X;
		if(ufs.root(x)!=ufs.root(y))ans+=len,ufs.mrg(x,y);
	}
	cout<<tot-ans;
	return 0;
}