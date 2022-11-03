#include <iostream>
#include <queue>

long long N, M, K, P;
long long sum_row_tmp[1000], sum_col_tmp[1000];
std::priority_queue<long long> sum_row, sum_col;
long long row_max[1000001], col_max[1000001], row_col_max[1000001];
long long tot_pleasure = 0;

void solve() {
	long long max;
	
	for(int n = 0; n < N; ++n)
		sum_row.push(sum_row_tmp[n]);
	for(int m = 0; m < M; ++m)
		sum_col.push(sum_col_tmp[m]);
	
	for(int k = 0; k < K; ++k) {
		max = sum_row.top();
		sum_row.pop();
		row_max[k + 1] = row_max[k] + max;
		sum_row.push(max - M * P);
	}
	for(int k = 0; k < K; ++k) {
		max = sum_col.top();
		sum_col.pop();
		col_max[k + 1] = col_max[k] + max;
		sum_col.push(max - N * P);
	}
	
	for(int k = 0; k <= K; ++k) {
		row_col_max[k] = row_max[k] + col_max[K - k] - P * k * (K - k);
		if(k == 0 || row_col_max[k] > tot_pleasure)
			tot_pleasure = row_col_max[k];
	}
}

void read() {
	int x;
	
	std::cin >> N >> M >> K >> P;
	for(int n = 0; n < N; ++n) {
		for(int m = 0; m < M; ++m) {
			std::cin >> x;
			sum_row_tmp[n] += x;
			sum_col_tmp[m] += x;
		}		
	}			
}

void write() {
	std::cout << tot_pleasure;
}

int main() {
	std::ios_base::sync_with_stdio(false);
	read();
	solve();
	write();
	return 0;
}