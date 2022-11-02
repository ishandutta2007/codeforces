#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn = 1025;
ll a[maxn];
ll f[maxn];
int main(){
	ll t;
	cin >> t;
	while(t--){
		ll n;
		cin >> n;
		for(int i = 1;i <= n;i++){
			cin >> a[i];
		}
		bool f1 = 0, f2 = 0;
		for(int i = 1;i <= 1024;i++){
			memset(f, 0, sizeof(f));
			for(int j = 1;j <= n;j++){
				f[a[j] ^ i]++;
			}
			f2 = 0;
			for(int j = 1;j <= n;j++){
				if(!f[a[j]]){
					f2 = 1;
					break;
				}
				f[a[j]]--;
			}
			if(f2) continue;
			cout << i << endl;
			f1 = 1;
			break;
		}
		if(!f1){
			puts("-1");
		}
	}
	return 0;
}