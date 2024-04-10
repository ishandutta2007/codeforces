#include <bits/stdc++.h>
 
#define ll long long
#define loop(a) loopi(i,a)
#define loopi(i,a) for(int i=0; i<a; i++)
#define pll pair<ll,ll>
 
using namespace std;

const int mod=1e9+7;
const int maxn=200005;

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0);
	ll n,m;
	cin >> n >> m;
	ll a[n];
	loop(n) cin >> a[i];
	sort(a,a+n);
	ll tel[n],ans[n];
	loop(n){
		tel[i]=a[i];
		if(i>=m) tel[i]+=tel[i-m];
	}
	loop(n){
		if(i==0) ans[0]=tel[0];
		else ans[i]=ans[i-1]+tel[i];
		cout << ans[i] << " ";
	}
	cout << "\n";
	return 0;
}