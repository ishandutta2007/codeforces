/*





D P 




 l l
*/
#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
#define X first
#define Y second
#define pb push_back
#define ppb pop_back
const double inf=1e14;
const int N=100000;
int n;
pair<int,int> a[2*N+1];
int son[2*N+1][2],prod[2*N+1][2];
vector<int> v;
pair<int,int> operator+(pair<int,int> x,pair<int,int> y){return mp(x.X+y.X,x.Y+y.Y);}
pair<int,int> operator*(int x,pair<int,int> y){return mp(x*y.X,x*y.Y);}
pair<int,int> operator-(pair<int,int> x,pair<int,int> y){return x+(-1)*y;}
double len(pair<int,int> x){return sqrt(1ll*x.X*x.X+1ll*x.Y*x.Y);}
int ans[N+1];
void dfs(int x=2*n-1,int now=1){
	if(x>n){
		dfs(son[x][0],now*prod[x][0]);
		dfs(son[x][1],now*prod[x][1]);
	}
	else ans[x]=now;
}
int main(){
	cin>>n;
	if(n==1)return puts("1"),0;
	for(int i=1;i<=n;i++)scanf("%d%d",&a[i].X,&a[i].Y),v.pb(i);
	for(int i=1;i<=n-2;i++){
		int x=v.back();v.ppb();
		int y=v.back();v.ppb();
		int z=v.back();v.ppb();
		pair<double,pair<pair<int,int>,pair<int,int> > > mn;
		mn.X=inf;
		mn=min(mn,mp(len(a[x]+a[y]),mp(mp(x,1),mp(y,1))));
		mn=min(mn,mp(len(a[x]-a[y]),mp(mp(x,1),mp(y,-1))));
		mn=min(mn,mp(len(a[x]+a[z]),mp(mp(x,1),mp(z,1))));
		mn=min(mn,mp(len(a[x]-a[z]),mp(mp(x,1),mp(z,-1))));
		mn=min(mn,mp(len(a[y]+a[z]),mp(mp(y,1),mp(z,1))));
		mn=min(mn,mp(len(a[y]-a[z]),mp(mp(y,1),mp(z,-1))));
		a[i+n]=mn.Y.X.Y*a[mn.Y.X.X]+mn.Y.Y.Y*a[mn.Y.Y.X];
		son[i+n][0]=mn.Y.X.X,prod[i+n][0]=mn.Y.X.Y;
		son[i+n][1]=mn.Y.Y.X,prod[i+n][1]=mn.Y.Y.Y;
		v.pb(i+n);
		if(son[i+n][0]==x&&son[i+n][1]==y)v.pb(z);
		if(son[i+n][0]==x&&son[i+n][1]==z)v.pb(y);
		if(son[i+n][0]==y&&son[i+n][1]==z)v.pb(x);
	}
	int x=v.back();v.ppb();
	int y=v.back();v.ppb();
	pair<double,pair<pair<int,int>,pair<int,int> > > mn;
	mn.X=inf;
	mn=min(mn,mp(len(a[x]+a[y]),mp(mp(x,1),mp(y,1))));
	mn=min(mn,mp(len(a[x]-a[y]),mp(mp(x,1),mp(y,-1))));
	a[2*n-1]=mn.Y.X.Y*a[mn.Y.X.X]+mn.Y.Y.Y*a[mn.Y.Y.X];
	son[2*n-1][0]=mn.Y.X.X,prod[2*n-1][0]=mn.Y.X.Y;
	son[2*n-1][1]=mn.Y.Y.X,prod[2*n-1][1]=mn.Y.Y.Y;
	dfs();
	for(int i=1;i<=n;i++)printf("%d ",ans[i]);
	return 0;
}