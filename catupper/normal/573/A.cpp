#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<string>
#include<map>
#include<set>

using namespace std;

int n;
vector<int> nums;
int a;

int main(){
	cin >> n;
	for(int i = 0;i < n;i++){
		cin >> a;
		while(a % 2 == 0)a /= 2;
		while(a % 3 == 0)a /= 3;
		nums.push_back(a);
	}                     
	sort(nums.begin(), nums.end());
	if(nums[0] == nums[n-1]){
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}
	return 0;
}