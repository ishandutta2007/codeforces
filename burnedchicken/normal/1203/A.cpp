#include <bits/stdc++.h>
 
#define ll long long
#define rep(a) rep1(i,a)
#define rep1(i,a) rep2(i,0,a)
#define rep2(i,b,a) for(int i=b; i<(int(a)); i++)
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
	int q,n,x,y;
	cin >> q;
	bool ok;
	rep1(noob,q){
		cin >> n;
		int a[n];
		rep(n){
			cin >> a[i];
			if(a[i]==1) x=i;
			if(a[i]==n) y=i;
		}
		ok=true;
		rep(n) if(a[(x+i)%n]!=i+1) ok=false; 
		if(ok){
			cout << "YES\n";
			continue;
		}
		ok=true;
		rep(n) if(a[(y+i)%n]!=n-i) ok=false;
		if(ok){
			cout << "YES\n";
			continue;
		}
		cout << "NO\n";
	}
	return 0;
}