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
	int t,n,s,k;
	cin >> t;
	set<int> st;
	while(t--){
		cin >> n >> s >> k;
		int a[k];
		rep(k) cin >> a[i];
		st.clear();
		rep(k) st.insert(a[i]);
		rep(100000){
			if(s+i<=n){
				if(!st.count(s+i)){
					cout << i << "\n";
					break;
				}
			}
			if(1<=s-i){
				if(!st.count(s-i)){
					cout << i << "\n";
					break;
				}
			}
		}
	}
	return 0;
}