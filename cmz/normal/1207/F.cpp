#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int k=700;
ll ans[710][710];
int n;
ll a[500010];
int main(){
	ios :: sync_with_stdio(0);
	cin >> n;
	for (int i=1;i<=n;++i){
		int opt,x,y;
		cin >> opt >> x >> y;
		if (opt==1){
			a[x]+=y;
			for (int i=1;i<=k;++i) ans[i][x%i]+=y;
		} else 
		if (opt==2){
			if (x<=k) cout << ans[x][y] << endl;
			else {
				ll anss=0;
				for (int i=y;i<=500000;i+=x) anss+=a[i];
				cout << anss << endl;
			}
		}
	}
	return 0;
}