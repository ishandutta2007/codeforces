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
	int n,x,y;
	cin >> n >> x >> y;
	int a[n];
	rep(n) cin >> a[i];
	rep(n){
		if(*min_element(a+max(0,i-x),a+min(n,i+y+1))==a[i]){
			cout << i+1 << "\n";
			return 0;
		}
	}
	return 0;
}