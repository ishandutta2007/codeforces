#include <bits/stdc++.h>

using namespace std;

int N;
int A[1010];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d", &N);
		for(int i = 1; i <= N; i++) scanf("%d", &A[i]);
		vector<int> v;
		v.push_back(1); printf("%d\n", 1);
		for(int i = 2; i <= N; i++) {
			if(A[i] == 1) v.push_back(1);
			else {
				while(v.size() && v.back() != A[i] - 1) v.pop_back();
				v.pop_back();
				v.push_back(A[i]);
			}
			for(int j = 0; j < v.size(); j++) {
				printf("%d", v[j]);
				if(j + 1 != v.size()) printf(".");
			}
			puts("");
		}
	}
	return 0;
}