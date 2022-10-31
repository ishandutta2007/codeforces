#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;

const int N = 1e5+5;
int p[N];

int main() {
	int n;
	scanf("%d",&n);
	if(n%4 > 1) printf("-1\n");
	else {
		if(n&1) {
			p[(n+1)/2] = (n+1)/2;
		}
		for(int i = 1; i < (n+1)/2; i+=2) {
			int j = i+1;
			p[i] = j;
			p[j] = n-i+1;
			p[n-i+1] = n-j+1;
			p[n-j+1] = i;
		}
		for(int i = 1; i <= n; ++i) {
			printf("%d ",p[i]);
		}
		printf("\n");
	}
	return 0;
}