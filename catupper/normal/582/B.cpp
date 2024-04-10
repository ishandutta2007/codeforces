#include<iostream>
#include<algorithm>
#include<set>
#include<vector>
#include<map>
using namespace std;

typedef pair<int, int> P;

vector<int> ans;
multiset<int> nums;

P dp[108000];
int aa[108000];
P a[108000];
int cnt[108000];
int place[108000];
int s[108000];

int n, t, x;

int main(){
	cin >> n >> t;
	
	if(t >= 1000){
		for(int i = 0;i < n;i++){
			cin >> aa[i];
		}
	
		for(int i = 0;i < n;i++){
			for(int j = 0;j < 1000;j++){
				a[j * n + i] = P(aa[i], j * n + i);
			}
		}
		fill(dp, dp + 108000, P(314159, 0));
		for(int i = 0;i < n * 1000;i++){
			*lower_bound(dp, dp + 108000, a[i]) = a[i];
		}
		int ress;
		for(int i = n * 1000 - 1;i >= 0;i--){
			if(dp[i].first != 314159){
				ress = i;break;
			}
		}
		
		fill(dp, dp + 108000, P(314159, 0));
		for(int i = 0;i < n * 999;i++){
			*lower_bound(dp, dp + 108000, a[i]) = a[i];
		}
		for(int i = n * 999 - 1;i >= 0;i--){
			if(dp[i].first != 314159){
				cout << i + 1 + (ress - i) * (t - 999) << endl;
				return 0;
			}
		}
		
	}
	
	if(t < 1000){
		for(int i = 0;i < n;i++){
			cin >> x;
			for(int j = 0;j < t;j++){
				a[j * n + i] = P(x, j * n + i);
			}
		}
		fill(dp, dp + 108000, P(314159, 0));
		for(int i = 0;i < n * t;i++){
			*lower_bound(dp, dp + 108000, a[i]) = a[i];
		}
		for(int i = n * t - 1;i >= 0;i--){
			if(dp[i].first != 314159){
				cout << i + 1 << endl;
				return 0;
			}
		}
	}
	return 0;
}