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
		int n;
		cin >> n;
		int l[n],r[n];
		loop(n) cin >> l[i] >> r[i];
		ll lmax,rmin;
		lmax=-1;
		rmin=1e18;
		loop(n){
			if(l[i]>lmax) lmax=l[i];
			if(r[i]<rmin) rmin=r[i];
		}
		if(lmax<=rmin){
			cout << "0\n";
			continue;
		}
		cout << lmax-rmin << "\n";
	}
	return 0;
}