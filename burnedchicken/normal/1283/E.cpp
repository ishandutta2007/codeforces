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
	int n;
	cin >> n;
	int a[n];
	rep(n) cin >> a[i];
	sort(a,a+n);
	int x=0,ans1=1,ans2=0;
	rep(n){
		if(a[i]>a[x]+2){
			x=i;
			ans1++;
		}
	}
	vector<pii> vec;
	rep(n){
		if(vec.empty()){
			vec.pb(mp(a[i],1));
			continue;
		}
		if(a[i]==vec.back().first) vec.back().second++;
		else vec.pb(mp(a[i],1));
	}
	bool b[n+2];
	rep(n+2) b[i]=false;
	rep(vec.size()){
		if(vec[i].second>2) b[vec[i].first-1]=b[vec[i].first]=b[vec[i].first+1]=true;
		else if(vec[i].second==2){
			if(b[vec[i].first-1]) b[vec[i].first]=b[vec[i].first+1]=true;
			else b[vec[i].first-1]=b[vec[i].first]=true;
		}
		else{
			if(!b[vec[i].first-1]) b[vec[i].first-1]=true;
			else if(!b[vec[i].first]) b[vec[i].first]=true;
			else b[vec[i].first+1]=true;
		}
	}
	rep(n+2) if(b[i]) ans2++;
	cout << ans1 << ' ' << ans2 << "\n";
	return 0;
}