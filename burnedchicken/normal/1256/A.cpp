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
	int t;
	cin >> t;
	loopi(noob,t){
		ll a,b,n,s;
		cin >> a >> b >> n >> s;
		if(s>a*n+b){
			cout << "NO\n";
			continue;
		}
		if(b>=n-1){
			cout << "YES\n";
			continue;
		}
		s=s%n;
		if(s>b) cout << "NO\n";
		else cout << "YES\n";
	}
	return 0;
}