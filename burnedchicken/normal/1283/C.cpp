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
	int n,x;
	cin >> n;
	int a[n];
	rep(n) cin >> a[i];
	bool used[n+1];
	rep(n+1) used[i]=false;
	used[0]=true;
	rep(n) used[a[i]]=true;
	vector<int> vec,vec1;
	rep(n+1) if(!used[i]) vec.pb(i);
	rep(n) if(!a[n-1-i]) vec1.pb(n-1-i);
	rep(n){
		if(a[i]) continue;
		vec1.pop_back();
		if(vec.back()==i+1||(vec.size()==2&&vec1.back()+1==vec[0])){
			x=vec.back();
			vec.pop_back();
			a[i]=vec.back();
			vec.pop_back();
			vec.pb(x);
		}
		else{
			a[i]=vec.back();
			vec.pop_back();
		}
	}
	rep(n) cout << a[i] << ' ';
	cout << "\n";
	return 0;
}