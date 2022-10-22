#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int num[108000];
int u[1080000];
vector<int> nums[108000];

int r(int x){
	if(u[x] == x)return x;
	return u[x] = r(u[x]);
}

void unite(int a, int b){
	u[r(a)] = r(b);
}

int main(){
	int n;
	char c;
	cin >> n;
	for(int i = 0;i < n;i++){
		cin >> num[i];
		u[i] = i;
	}
	for(int i = 0;i < n;i++){
		for(int j = 0;j < n;j++){
			cin >> c;
			if(c == '1' && r(i) != r(j)){
				unite(i, j);
			}
		}
	}
	for(int i = 0;i < n;i++){
		nums[r(i)].push_back(num[i]);
	}
	for(int i = 0;i < n;i++){
		sort(nums[i].begin(), nums[i].end(), greater<int>() );
	}
	for(int i = 0;i < n;i++){
		if(i)cout << " ";
		cout << nums[r(i)].back();
		nums[r(i)].pop_back();
	
	}
	return 0;
}