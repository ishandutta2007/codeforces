#include <bits/stdc++.h>
#define rep0(i,r) for (int i=0,i##end=r;i<i##end;++i)
#define rep(i,l,r) for (int i=l;i<=r;++i)
#define per(i,r,l) for (int i=r;i>=l;--i)
#define pr pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define vit vector<int>::iterator
#define sit set<int>::iterator
#define pb push_back
#define ll long long
using namespace std;
const int N=1e6+6; 
int x[N],c[N],r[N]; pr a[N];
int main(){
	int n; scanf("%d",&n);
	rep(i,1,n){
		scanf("%d%d",&x[i],&c[i]);
		a[i]=mp(x[i],c[i]);
	}
	sort(a+1,a+1+n);
	rep(i,1,n) r[i]=max(r[i-1],a[i].fi+a[i].se);
	ll ans=0; rep(i,1,n) ans+=c[i];
	rep(i,2,n) ans+=max(0,a[i].fi-r[i-1]);
	cout<<ans<<endl;
	return 0;
}