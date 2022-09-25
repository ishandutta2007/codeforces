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
	if(a[n-1]>=a[n-2]+a[n-3]){
		cout << "NO\n";
		return 0;
	}
	vector<int> vec1,vec2;
	rep(n){
		if(i%2) vec2.pb(a[i]);
		else vec1.pb(a[i]);
	}
	reverse(all(vec2));
	cout << "YES\n";
	rep(vec1.size()) cout << vec1[i] << ' ';
	rep(vec2.size()) cout << vec2[i] << ' ';
	cout << "\n";
	return 0;
}