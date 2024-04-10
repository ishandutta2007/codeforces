#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

using namespace std;
using ll = long long;
const int MM = 1e5+5;

int n, q;
ll k, a[MM], b[MM], psa[MM];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>q>>k;
	for(int i = 1; i <= n; i++){
		cin>>a[i];
	}
	a[0] = 1;
	a[n+1] = k;
	for(int i = 1; i <= n; i++){
		b[i] = a[i]-1-a[i-1] + a[i+1]-(a[i]+1);
		psa[i] = psa[i-1]+b[i];
		// cout<<b[i]<<' ';
	}
	// cout<<endl;
	while(q--){
		int l, r;
		cin>>l>>r;
		ll v = psa[r]-psa[l-1] - (a[r+1]-1-a[r]) + (k-a[r]) - (a[l]-(a[l-1]+1)) + (a[l]-1);
		cout<<v<<'\n';
	}
}