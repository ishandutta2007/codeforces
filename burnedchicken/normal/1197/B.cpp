#include <bits/stdc++.h>
 
#define ll long long
#define rep(a) rep1(i,a)
#define rep1(i,a) rep2(i,0,a)
#define rep2(i,b,a) for(int i=(b); i<(int(a)); i++)
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
	list<int> lis;
	rep(n){
		cin >> x;
		lis.pb(x);
	}
	rep(n){
		if(lis.front()!=i+1&&lis.back()!=i+1){
			cout << "NO\n";
			return 0;
		}
		if(lis.front()==i+1) lis.pop_front();
		else if(lis.back()==i+1) lis.pop_back();
	}
	cout << "YES\n";
	return 0;
}