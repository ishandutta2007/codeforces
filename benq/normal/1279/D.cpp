#include <iostream>
#include <vector>
#include <unordered_map>
 
using std::cout;
using std::endl;
using std::vector;
 
constexpr int MOD = 998244353;
 
// sauce: /gold/modular
long long pow_mod(long long base, long long exp) {
	base %= MOD;
	long long result = 1;
	while (exp > 0) {
		if (exp % 2 == 1) //if n is odd
			result = result * base % MOD;
		base = base * base % MOD;
		exp /= 2; //divide by two
	}
	return result;
}
 
long long mod_inv(long long n) {  // sauce is same as above
	return pow_mod(n, MOD - 2);
}
 
long long frac_total(long long num, long long denom) {
	return ((num % MOD) * mod_inv(denom)) % MOD;
}
 
int main() {
	int child_num;
	std::cin >> child_num;
	vector<vector<int>> children(child_num);
	std::unordered_map<int, int> wanter_nums;
	for (int c = 0; c < child_num; c++) {
		int wanted_num;
		std::cin >> wanted_num;
		for (int i = 0; i < wanted_num; i++) {
			int item;
			std::cin >> item;
			wanter_nums[item]++;
			children[c].push_back(item);
		}
	}
 
	long long prob = 0;
	for (const vector<int>& c : children) {
		for (const int& i : c) {
			int num = 1 * 1 * wanter_nums[i];
			long long denom = child_num * (long long)c.size() * child_num;
			prob = (prob + frac_total(num, denom)) % MOD;
		}
	}
	cout << prob << endl;
}