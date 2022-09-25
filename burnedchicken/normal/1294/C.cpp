#include <bits/stdc++.h>
 
#define ll long long
#define ull unsigned long long
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
int t,n,x,y;
 
int main(){
	ios_base::sync_with_stdio(0),cin.tie(0);
	cin >> t;
	while(t--){
		cin >> n;
		x=y=-1;
		rep2(i,2,n+1){
			if(n%i==0){
				x=i;
				break;
			}
			if(i*i>n) break;
		}
		if(x==-1){
			cout << "NO\n";
			continue;
		}
		n=n/x;
		rep2(i,x+1,n+1){
			if(n%i==0){
				y=i;
				break;
			}
			if(i*i>n) break;
		}
		if(y==-1){
			cout << "NO\n";
			continue;
		}
		n=n/y;
		if(n<=y){
			cout << "NO\n";
			continue;
		}
		cout << "YES\n" << x << ' ' << y << ' ' << n << "\n";
	}
	return 0;
}