#include <algorithm>
#include <iostream>
#include <map>
#include <utility>

struct front_back {
	int front, back;
};

int N;
std::map<int, front_back> col_n;
int solution = -1;

void solve() {
	int halfN = (N + 1) >> 1;	// = (N + 1) / 2
	
	for(std::map<int, front_back>::iterator it = col_n.begin(); it != col_n.end(); ++it) {
		if(it->second.front + it->second.back >= halfN) {
			if(solution < 0 || halfN - it->second.front < solution) {
				solution = std::max(0, halfN - it->second.front);
				if(solution == 0) return;
			}
		}
	}
}

void read() {
	int f, b;
	
	std::cin >> N;
	for(int i = 0; i < N; ++i) {
		std::cin >> f >> b;
		++col_n[f].front;
		if(f != b) ++col_n[b].back;
	}
}

void write() {
	std::cout << solution;
}

int main() {
	std::ios_base::sync_with_stdio(false);
	read();
	solve();
	write();
	return 0;
}