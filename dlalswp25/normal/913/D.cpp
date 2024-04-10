#include <stdio.h>
#include <set>
#include <algorithm>
#include <vector>

using namespace std;

multiset<int> S;
vector<pair<int, int> > V;

struct prob {
	int a, t, idx;
};
prob A[200005];

bool cmp(prob x, prob y) {
	return x.a < y.a;
}

int main() {
	int N, T; scanf("%d %d", &N, &T);
	for(int i = 0; i < N; i++) {
		scanf("%d %d", &A[i].a, &A[i].t); A[i].idx = i + 1;
	}

	sort(A, A + N, cmp);
	long long sum = 0; int res = 0;
	
	int i = N - 1;
	for(int nowa = N; nowa >= 0; nowa--) {
		while(S.size() > nowa) {
			multiset<int>::iterator it = S.end(); it--;
			sum -= (*it); S.erase(it);
		}
		
		while(i >= 0) {
			if(A[i].a < nowa) break;
			if(S.size() < nowa) { S.insert(A[i].t); sum += A[i].t; }
			else {
				multiset<int>::iterator it = S.end(); it--;
				if((*it) > A[i].t) {
					sum -= (*it); S.erase(it);
					S.insert(A[i].t); sum += A[i].t;
				}
			}
			i--;
		}

		//printf("%d %d %d\n", i, sum, (int)S.size());
		if(sum <= (long long)T && S.size() == nowa) {
			res = S.size(); break;
		}
	}
	printf("%d\n%d\n", res, res);
	if(!res) return 0;

	for(int i = N - 1; i >= 0; i--) {
		if(A[i].a < res) break;
		V.push_back(make_pair(A[i].t, A[i].idx));
	}
	sort(V.begin(), V.end());
	for(int i = 0; i < res; i++) {
		printf("%d ", V[i].second);
	}
	return 0;
}