#include <bits/stdc++.h>

using namespace std;

vector<int> nums;
int n, k;

int main(int argc, char const *argv[])
{
	cin >> n >> k;

	for (int i = 0; i < n; ++i)
	{
		int tmp;
		cin >> tmp;
		nums.push_back(tmp);
	}
	nums.push_back(1e9);

	sort(nums.begin(), nums.end());

	if(k == 0) {
		if(nums[0] == 1) {
			cout << -1 << endl;
		} else {
			cout << 1 << endl;
		}
		return 0;
	} else if(k == n) {
		cout << nums[n - 1] << endl; 
		
		return 0;
	} else {
		if(nums[k - 1] == nums[k]) {
			cout << -1 << endl;
		} else {
			if(nums[k - 1] + 1 <= nums[k]) {
				cout << nums[k - 1] << endl;
			} else {
				cout << -1 << endl;
			}
		}
		return 0;
	}

	cout << -1 << endl;

	return 0;
}