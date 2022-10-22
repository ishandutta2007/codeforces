#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
const int MN = 5e3+5, MOD = 1e9+7, B = 300;
#define all(x) (x).begin(),(x).end()
int main() {
	int n,k;
	scanf ("%d %d",&n,&k);
	while (k--) {
		if (n%10==0) n/=10;
		else n--;
	}
	printf ("%d\n",n);
    return 0;
}