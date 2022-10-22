#include<iostream>
#include<algorithm>
#include<unordered_map>
#include<map>
using namespace std;

map<int, int> dp;

int gcd(int a, int b){
	if(a == 0)return b;
	return gcd(b % a, a);
}

int n;
int l[108000];
int c[108000];

int main(){
	cin >> n;
	dp[0] = 0;
	for(int i = 0;i < n;i++)cin >> l[i];
	for(int i = 0;i < n;i++)cin >> c[i];
	for(int i = 0;i < n;i++){
		for(auto it = dp.begin();it != dp.end();it++){
			int g = gcd(it->first, l[i]);
			if(g == it->first)continue;
			if(dp.count(g) == 0)dp[g] = it->second + c[i];
			else dp[g] = min(dp[g], it->second + c[i]);	
		}
	}
	if(dp.count(1) == 0)
		cout << -1 << endl;
	else 
		cout << dp[1] << endl;
	return 0;
}