#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long Int;
vector<Int> nums;
Int bit[1080000], a[1080000], l[1080000], r[1080000];
Int n, res;
void add(Int x){
x++;
	while(x < 1080000){
		bit[x]++;
		x += x & -x;
	}
}

Int get(Int x){
x++;
	Int res = 0;
	while(x){
		res += bit[x];
		x -= x & -x;
	}
	return res;
}

int main(){
	cin >> n;
	for(Int i = 0;i < n;i++){
		cin >> a[i];
		nums.push_back(a[i]);
	}
	sort(nums.begin(), nums.end());
	nums.erase(unique(nums.begin(), nums.end()), nums.end());
	
	for(int i = 0;i < n;i++){
		a[i] = lower_bound(nums.begin(), nums.end(), a[i]) - nums.begin();
	}
	for(int i = 0;i < n;i++){
		l[i] = get(a[i]) - get(a[i] - 1) + 1;
		add(a[i]);
	}                        
	for(Int i = 0;i < n;i++){
		r[i] = get(a[i]) - get(a[i] - 1) - l[i] + 1;
	}                      
	fill(bit, bit + 1080000, 0);
	for(Int i = n - 1;i >= 0;i--){
		res += get(l[i] - 1);
		add(r[i]);
	}
	cout << res << endl;
	return 0;
}