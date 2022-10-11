#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
using namespace std;
#pragma warning (disable: 4996)

long long N, S1, S2, A[1 << 19], B[1 << 19], C1[1 << 19], C2[1 << 19];
vector<pair<long long, int>> V1; vector<long long>V2;

vector<tuple<long long, long long, int>> cl, cr;

int main() {
	scanf("%lld", &N);
	for (int i = 1; i <= N; i++) { scanf("%lld", &A[i]); S1 += A[i]; C1[i] = A[i]; V1.push_back(make_pair(A[i], i)); }
	for (int i = 1; i <= N; i++) { scanf("%lld", &B[i]); S2 += B[i]; C2[i] = B[i]; V2.push_back(B[i]); }
	sort(V1.begin(), V1.end()); sort(C1 + 1, C1 + N + 1);
	sort(V2.begin(), V2.end()); sort(C2 + 1, C2 + N + 1);

	if (S1 != S2) {
		cout << "NO" << endl;
		return 0;
	}

	long long D1 = 0, D2 = 0;
	for (int i = 1; i <= N; i++) {
		D1 += C1[i]; D2 += C2[i];
		if (D1 > D2) {
			cout << "NO" << endl;
			return 0;
		}
	}

	for (int i = 0; i < N; i++) {
		if (V1[i].first < V2[i]) cl.push_back(make_tuple(A[V1[i].second], V1[i].second, V2[i] - V1[i].first));
		else cr.push_back(make_tuple(A[V1[i].second], V1[i].second, V2[i] - V1[i].first));
	}
	sort(cl.begin(), cl.end());
	sort(cr.begin(), cr.end());

	vector<tuple<int, int, int>> tup; int cx = 0;
	for (int i = 0; i < cl.size(); i++) {
		while (get<2>(cl[i]) > 0) {
			if (get<2>(cl[i]) > -get<2>(cr[cx])) {
				if (get<2>(cr[cx]) < 0) tup.push_back(make_tuple(get<1>(cl[i]), get<1>(cr[cx]), -get<2>(cr[cx])));
				get<2>(cl[i]) += get<2>(cr[cx]);
				get<2>(cr[cx]) = 0;
				cx++;
			}
			else {
				tup.push_back(make_tuple(get<1>(cl[i]), get<1>(cr[cx]), get<2>(cl[i])));
				get<2>(cr[cx]) += get<2>(cl[i]);
				get<2>(cl[i]) = 0;
			}
		}
	}
	for (int i = 0; i < tup.size(); i++) { if (A[get<0>(tup[i])] > A[get<1>(tup[i])]) swap(get<0>(tup[i]), get<1>(tup[i])); }
	
	printf("YES\n");
	printf("%d\n", (int)tup.size());
	for (int i = 0; i < tup.size(); i++) printf("%d %d %d\n", get<0>(tup[i]), get<1>(tup[i]), get<2>(tup[i]));
	return 0;
}