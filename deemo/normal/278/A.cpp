#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>

using namespace std;

int main(){
	int n;	cin >> n;
	vector<int>	vec(n);
	int sum = 0;
	for (int i = 0; i < n; i++){
		cin >> vec[i];
		sum += vec[i];
	}
	int s, t;	cin >> s >> t;	s--, t--;

	int ans1 = 0;
	int ts = s, tt = t;
	while (ts != tt){
		ans1 += vec[ts];
		ts = (ts + 1) % n;
	}	
	cout << min(ans1, sum - ans1) << endl;
	return 0;
}