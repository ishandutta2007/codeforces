#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>

using namespace std;

int main(){
	int n;	cin >> n;
	vector<int>	vec(n);
	int cnt = 0;
	for (int i = 0; i < n; i++){
		cin >> vec[i];
		if (vec[i] < 0)	cnt++;
	}
	sort(vec.begin(), vec.end());
	vector<int>	ans[3];
	
	ans[0].push_back(vec[0]);
	vec.erase(vec.begin());
	cnt--;

	if (vec.back() > 0){
		ans[1].push_back(vec.back());
		vec.pop_back();
	}
	else{
		ans[1].push_back(vec[0]);
		ans[1].push_back(vec[1]);
		vec.erase(vec.begin());
		vec.erase(vec.begin());
	}


	for (int u:vec)	ans[2].push_back(u);

	for (int i = 0; i < 3; i++){
		cout << ans[i].size() << " ";
		for (int j:ans[i])	cout << j << " ";
		cout << "\n";
	}
	return 0;
}