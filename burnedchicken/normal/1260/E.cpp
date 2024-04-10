#include <bits/stdc++.h>
 
#define ll long long
#define loop(a) loopi(i,a)
#define loopi(i,a) for(int i=0; i<a; i++)
#define pii pair<int,int>
#define pll pair<ll,ll>
 
using namespace std;
 
const int mod=1e9+7;
const int maxn=200005;
 
int main(){
	ios_base::sync_with_stdio(0),cin.tie(0);
	ll n;
	cin >> n;
	ll a[n];
	ll x,y,ans;
	loop(n){
		cin >> a[i];
		if(a[i]==-1) x=i;
	}
	ll num=n-1;
	ans=0;
	multiset<ll> s;
	y=num;
	while(num>x){
		while(y>=num){
			s.insert(a[y]);
			y--;
		}
		ans+=*s.begin();
		s.erase(s.begin());
		num-=(num+1)/2;
	}
	cout << ans << "\n";
	return 0;
}