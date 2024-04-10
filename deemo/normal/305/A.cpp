#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main(){
	int n;	cin >> n;
	vector<int>	vec(n), ans;
	for (int i = 0; i < n; i++)	cin >> vec[i];
	sort(vec.begin(), vec.end());

	if (vec.size() && vec[0] == 0){
		ans.push_back(0);
		vec.erase(vec.begin());
	}
	if (vec.size() && vec.back() == 100){
		ans.push_back(100);
		vec.pop_back();
	}
	
	int z = ans.size();
	for (int i = 0; i < vec.size(); i++){
		if (vec[i] < 10){
			ans.push_back(vec[i]);
			break;
		}
	}
	for (int i = 0; i < vec.size(); i++)
		if (vec[i] >= 10 && vec[i] % 10 == 0){
			ans.push_back(vec[i]);
			break;
		}	
	if (z == ans.size() && vec.size())
		ans.push_back(vec[0]);

	cout << ans.size() << endl;
	for (int u:ans)
		cout << u << " ";
	cout << endl;
	return 0;	
}