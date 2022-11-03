#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef long long ll;

int N, K;
int A[200200];
unordered_map<int, int> freq;
unordered_map<int, ll> C1;
ll ans = 0;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> N >> K;
	for(int n = 0; n < N; ++n) cin >> A[n];
	for(int n = 0; n < N; ++n) {
		if(A[n] % K == 0) {
			int a = A[n] / K;
			if(C1.find(a) != C1.end())
				ans += C1[a];
			if(freq.find(a) != freq.end())
				C1[A[n]] += freq[a];
		}
		++freq[A[n]];
	}
	
	cout << ans;
}