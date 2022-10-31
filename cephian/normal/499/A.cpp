#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;

int n,l,r,x;

int main() {
	scanf("%d%d",&n,&x);
	int lr = 0;
	int w = 0;
	for(int i = 0; i < n; ++i) {
		scanf("%d%d",&l,&r);
		w += r-l+1;
		int k = l-lr-1;
		w += k%x;
		lr = r;
	}
	printf("%d\n",w);
	return 0;
}