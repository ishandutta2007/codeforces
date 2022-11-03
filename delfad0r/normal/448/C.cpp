#include <algorithm>
#include <iostream>
#include <vector>

int N;
int H[5000];

int calc(int l, int r, int h) {		//[l; r[
	if(r - l < 2)
		return r - l;
	int min_h = 1000000000;
	std::vector<int> min_h_vec;
	for(int i = l; i < r; ++i) {
		if(H[i] < min_h) {
			min_h = H[i];
			min_h_vec.resize(1);
			min_h_vec[0] = i;
		}
		else if(H[i] == min_h) {
			min_h_vec.push_back(i);
		}
	}
	min_h -= h;
	if(min_h >= r - l) {
		return r - l;
	}
	int tot = min_h;
	tot += calc(l, min_h_vec.front(), h + min_h);
	for(unsigned i = 1; i < min_h_vec.size(); ++i)
		tot += calc(min_h_vec[i - 1] + 1, min_h_vec[i], h + min_h);
	tot += calc(min_h_vec.back() + 1, r, h + min_h);
	return std::min(tot, r - l);
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin >> N;
	for(int n = 0; n < N; ++n) {
		std::cin >> H[n];
	}
	std::cout << calc(0, N, 0);
}