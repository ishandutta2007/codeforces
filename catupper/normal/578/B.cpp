#include<iostream>
#include<algorithm>

using namespace std;

typedef long long Int;

Int n, k, x;
Int a[216000];
Int lef[216000];
Int rig[216000];
int main(){
	cin >> n >> k >> x;
	Int mult = 1;
	for(int i = 0;i < k;i++)mult *= x;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	lef[0] = 0;
	rig[n+1] = 0;
	for(int i = 1;i <= n;i++){
		lef[i] = lef[i-1] | a[i];
	}
	for(int i = n;i >= 1;i--){
		rig[i] = rig[i+1] | a[i];
	}
	Int ans = 0;
	for(int i = 1;i <= n;i++){
		ans = max(ans, lef[i-1] | rig[i+1] | a[i] * mult);
	}
	cout << ans << endl;
	return 0;
}