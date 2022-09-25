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
	int n,m;
	ll ans=0;
	cin >> n >> m;
	int a[m][5];
	int s[m];
	rep(m) rep1(j,5) a[i][j]=0;
	string str[n];
	rep(n) cin >> str[i];
	rep(m) cin >> s[i];
	rep(n) rep1(j,m) a[j][str[i][j]-'A']++;
	rep(m) ans+=*max_element(a[i],a[i]+5)*s[i];
	cout << ans << "\n";
	return 0;
}