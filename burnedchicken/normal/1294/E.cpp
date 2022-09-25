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
int n,m,ans=0,x,y,z;
multiset<int> st;
 
int main(){
	ios_base::sync_with_stdio(0),cin.tie(0);
	cin >> n >> m;
	int a[n][m];
	rep(n) rep1(j,m) cin >> a[i][j];
	rep(m){
		st.clear();
		rep1(j,n){
			if((a[j][i]-i-1)%m) continue;
			if((a[j][i]-i-1)/m>=n) continue;
			st.insert((j-(a[j][i]-i-1)/m+n)%n);
		}
		x=0;
		y=-1;
		forall(st,multiset<int>){
			if(y!=-1){
				z=*it;
				if(y==z) continue;
			}
			x=max(x,int(st.count(*it))-(*it));
			y=*it;
		}
		ans+=n-x;
	}
	cout << ans << "\n";
	return 0;
}