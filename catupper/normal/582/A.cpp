#include<iostream>
#include<algorithm>
#include<set>
#include<vector>
using namespace std;


vector<int> ans;
multiset<int> nums;

int n, x;

int gcd(int x, int y){
	if(x == 0)return y;
	return gcd(y % x, x);
}

int main(){
	cin >> n;
	for(int i = 0;i < n;i++){
		for(int j = 0;j < n;j++){
			cin >> x;
			nums.insert(x);
		}
	}
	
	for(int i = 0;i < n;i++){
		int tmp = *nums.rbegin();
		nums.erase(nums.find(tmp));
		ans.push_back(tmp);
		for(int j = 0;j < i;j++){
			nums.erase(nums.find(gcd(tmp,ans[j])));
			nums.erase(nums.find(gcd(tmp,ans[j])));
		}
	}
	
	for(int i = 0;i < n;i++){
		if(i) cout << " ";
		cout << ans[i];
	}                     cout << endl;
	
	return 0;
}