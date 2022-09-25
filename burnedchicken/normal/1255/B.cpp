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
	int t;
	cin >> t;
	loopi(noob,t){
		int n,m;
		cin >> n >> m;
		int a[n];
		loop(n) cin >> a[i];
		if(m<n||n==2){
			cout << "-1\n";
			continue;
		}
		int ans=0;
		loop(n) ans+=a[i];
		cout << ans*2 << "\n";
		loop(n-1) cout << i+1 << " " << i+2 << "\n";
		cout << n << " " << 1 << "\n";
		
	}
	return 0;
}