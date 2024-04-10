#include <bits/stdc++.h>
 
#define ll long long
#define loop(a) loopi(i,a)
#define loopi(i,a) for(int i=0; i<a; i++)
#define pii pair<int,int>
#define pll pair<ll,ll>
 
using namespace std;
 
const int mod=1e9+7;
const int maxn=100005;
 
int main(){
	ios_base::sync_with_stdio(0),cin.tie(0);
	int n;
	cin >> n;
	loopi(noob,n){
		ll r,b,k;
		cin >> r >> b >> k;
		ll x=__gcd(r,b);
		r/=x;
		b/=x;
		if(r<b) swap(r,b);
		if(r==1){
			cout << "OBEY\n";
			continue;
		}
		if(ceil((r-1)/double(b))>=k){
			cout << "REBEL\n";
			continue;
		}
		cout << "OBEY\n";
	}
	return 0;
}