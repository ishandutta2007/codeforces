#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>

using namespace std;

int main(){
	long long ans = 0;
	int n, m;	cin >> n >> m;
	int cur = 0;
	for (int i = 0; i < m; i++){
		int temp;	cin >> temp;	temp--;
		if (cur <= temp){
			ans += temp - cur;
			cur = temp;
			continue;
		}	
		ans += n - cur;
		cur = 0;
		ans += temp - cur;
		cur = temp;
	}
	cout << ans << endl;
	return 0;	
}