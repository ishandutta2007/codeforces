#include <bits/stdc++.h>

using namespace std;

vector<int> v;
int A[303030];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		int N; scanf("%d", &N);
		for(int i = 1; i <= N; i++) scanf("%d", &A[i]);
		v.clear();
		for(int i = N; i >= 1; i--) {
			if(v.size() == 0) { v.push_back(A[i]); continue; }
			while(v.size() > 1) {
				if(v.back() > A[i]) v.pop_back();
				else break;
			}
			if(v.back() < A[i]) v.push_back(A[i]);
		}
		puts(v.size() == 1 ? "YES" : "NO");
	}
	return 0;
}