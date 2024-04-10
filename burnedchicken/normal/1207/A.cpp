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
	int t,b,p,f,h,c;
	cin >> t;
	rep1(noob,t){
		cin >> b >> p >> f >> h >> c;
		if(h<c) swap(p,f),swap(h,c);
		if(b/2<=p) cout << h*(b/2) << "\n";
		else if(b/2<=p+f) cout << h*p+c*((b-2*p)/2) << "\n";
		else cout << h*p+c*f << "\n";
	}
	return 0;
}