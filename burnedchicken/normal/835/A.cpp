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
	int a,b,c,d,e;
	cin >> a >> b >> c >> d >> e;
	if(a*b+2*d>a*c+2*e) cout << "Second\n";
	else if(a*b+2*d<a*c+2*e) cout << "First\n";
	else cout << "Friendship\n";
	return 0;
}