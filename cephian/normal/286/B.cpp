#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;

const int N = 1e6;
int P[3*N],n;

int main() {
	scanf("%d",&n);
	for(int i = 0; i < n; ++i) {
		P[i] = i+1;
	}
	for(int i = 2; i <= n; ++i) {
		int o = i-2;
		int j = (n-1)/i*i;
		P[n+o] = P[j+o];
		for(; j >= i; j -= i) {
			P[j+o] = P[j-i+o];
		}
	}
	int o = n-1;
	for(int i = 0; i < n; ++i) {
		printf("%d ",P[i+o]);
	}
	printf("\n");
	return 0;
}