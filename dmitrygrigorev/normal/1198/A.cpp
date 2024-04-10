#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (int i=0; i < n; i++) cin >> v[i];
    k *= 8;
	int can = k/n;
	sort(v.begin(), v.end());
	int u = 0;
	if (can >= 30) can = 1e9;
	else can = (1<<can);
	can--;
	int r = 0;
	int ans = n;
	while (r+1 < n){
		if (v[r] == v[r+1]){
			r++;
			continue;
		}
		else{
			if (can==0) break;
			else{
				can--;
				r++;
			}
		}
	}
	for (int i=0; i < n; i++){
		ans = min(ans, i+(n-r-1));
		if (i>=n-2) break;
		if (v[i] != v[i+1]){
			can++;
			while (r+1 < n){
				if (v[r] == v[r+1]){
					r++;
					continue;
				}
				else{
					if (can==0) break;
					else{
						can--;
						r++;
					}
				}
			}
		}
	}
	cout << ans;
}