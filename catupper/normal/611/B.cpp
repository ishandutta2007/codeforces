#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
vector<long long> vec;


int main(){

	for(int i = 0;i < 63;i++){
		long long mask = 1LL << i;mask--;
		for(int j = 0;j < i - 1;j++){
			vec.push_back(mask ^ (1LL << j));
		}
	}


	sort(vec.begin(), vec.end());
	vec.erase(unique(vec.begin(), vec.end()), vec.end());

	long long a, b;
	cin >> a >> b;
	
	cout << upper_bound(vec.begin(), vec.end(), b) - lower_bound(vec.begin(), vec.end(), a) << endl;
	return 0;
}