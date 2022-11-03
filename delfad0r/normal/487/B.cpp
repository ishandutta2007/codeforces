#include <cstdio>
#include <cstring>
#include <iostream>
#include <set>

using namespace std;

typedef pair< int, int > ii;

int N, S, L;
int A[100000];
int F[100000];

int main() {
	ios_base::sync_with_stdio(false);
	memset(F, -1, sizeof(F));
	
	cin >> N >> S >> L;
	for(int n = 0; n < N; ++n) cin >> A[n];
	
	multiset< int > E, Q;
	int j1 = 0, j2 = 0;
	for(int n = 0; n < N; ++n) {
		E.insert(A[n]);
		while(E.size() && *E.rbegin() - *E.begin() > S) E.erase(E.find(A[j1++]));
		if(L - 1 <= n - j1) {
			if(j1 == 0) F[n] = 1;
			else {
				while(j2 + 1 < j1) {
					if(F[j2] != -1) Q.erase(Q.find(F[j2]));
					++j2;
				}
				if(Q.size()) F[n] = *Q.begin() + 1;
			}
		}
		if(n - L + 1 >= 0 && F[n - L + 1] != -1) Q.insert(F[n - L + 1]);
	}
	
	cout << F[N - 1];
}