#include <bits/stdc++.h>
 
#define ll long long
#define rep(a) rep1(i,a)
#define rep1(i,a) rep2(i,0,a)
#define rep2(i,b,a) for(int i=(b); i<(int(a)); i++)
#define all(a) a.begin(),a.end()
#define forall(a,type) for(type::iterator it=a.begin(); it!=a.end(); it++)
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pb push_back
#define mp make_pair
#define pow2(x) (1ll<<(x))
 
using namespace std;

const int Mod=1e9+7;
 
int main(){
	ios_base::sync_with_stdio(0),cin.tie(0);
	int n,m;
	cin >> n >> m;
	int a[n];
	rep(n) cin >> a[i];
	sort(a,a+n);
	set<int> s;
	rep(n) s.insert(a[i]);
	int l=1,r=m,x,y,cnt;
	ll z;
	bool ok;
	vector<pii> vec;
	while(l!=r){
		x=(l+r)/2;
		vec.clear();
		rep(n) vec.pb(mp(a[i]-x,-1));
		rep(n) vec.pb(mp(a[i]+x,1));
		sort(all(vec));
		cnt=z=0;
		rep(2*n){
			if(!cnt) y=vec[i].first;
			cnt+=vec[i].second;
			if(!cnt) z+=vec[i].first-y+1;
		}
		if(z>=m+n) ok=true;
		else ok=false;
		if(ok) r=x;
		else l=x+1;
	}
	x=l-1;
	vec.clear();
	rep(n) vec.pb(mp(a[i]-x,-1));
	rep(n) vec.pb(mp(a[i]+x,1));
	sort(all(vec));
	cnt=z=0;
	vector<int> ans;
	rep(2*n){
		if(!cnt) y=vec[i].first;
		cnt+=vec[i].second;
		if(!cnt){
			z+=vec[i].first-y+1;
			rep2(j,y,vec[i].first+1){
				if(!s.count(j)){
					ans.pb(j);
					s.insert(j);
				}
			}
		}
	}
	x++;
	rep(n){
		if(ans.size()==m) break;
		if(!s.count(a[i]-x)){
			ans.pb(a[i]-x);
			s.insert(a[i]-x);
		}
		if(ans.size()==m) break;
		if(!s.count(a[i]+x)){
			ans.pb(a[i]+x);
			s.insert(a[i]+x);
		}
	}
	sort(all(ans));
	z=0;
	x=0;
	rep(m){
		while(ans[i]>a[x]&&x<n) x++;
		if(x==0) z+=a[0]-ans[i];
		else if(x==n) z+=ans[i]-a[n-1];
		else z+=min(ans[i]-a[x-1],a[x]-ans[i]);
	}
	cout << z << "\n";
	rep(m) cout << ans[i] << ' ';
	cout << "\n";
	return 0;
}