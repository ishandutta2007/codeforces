#include<iostream>
#include<vector>
#include<algorithm>
#include<map>

using namespace std;

typedef pair<int, int> P;
vector<int> nums;
vector<int> number[216000];
int bit[216000];
int res[216000];
void add(int pos, int val = 1){
	pos++;
	while(pos < 216000){
		bit[pos] += val;
		pos += pos & -pos;
	}
}

int sum(int pos){
	pos++;
	int res = 0;
	while(pos){
		res += bit[pos];
		pos -= pos & -pos;
	}
	return res;
}



int main(){
	int n;
	int a[216000];
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		nums.push_back(a[i]);
	}
	sort(nums.begin(), nums.end());
	nums.erase(unique(nums.begin(), nums.end()), nums.end());
	for(int i = 1;i <= n;i++){
		a[i] = lower_bound(nums.begin(), nums.end(), a[i]) - nums.begin();
		number[a[i]].push_back(i);
	}
	for(int i = 0;i <= n;i++){
		for(int j = 0;j < number[i].size();j++){
			int tmp = number[i][j];
			for(int k = 1;k < n;k++){
				int l = k * (tmp - 1) + 1, r = k * tmp + 1;
				r = min(r, n);
				if(l > n)break;
				res[k] += sum(r) - sum(l);
			}
		}
		for(int j = 0;j < number[i].size();j++){
			int tmp = number[i][j];
			add(tmp);
		}
	}
	for(int i = 1;i < n;i++){
		if(i != 1)cout << " " ;
		cout << res[i];
	}                          cout << endl;
	return 0;
}