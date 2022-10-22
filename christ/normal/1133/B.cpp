#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
const int MN = 2e5+5, MOD = 1e9+7, B = 300;
#define all(x) (x).begin(),(x).end()
int main() {
    int n,k;
	scanf ("%d %d",&n,&k);
	vector<int> a(n); vector<int> freq(k);
	for (int i = 0; i < n; i++) {
		scanf ("%d",&a[i]);
		freq[a[i]%k] += 1;
	}
	int ret = 0;
	for (int i = 1; i < (k+1)/2; i++) ret += min(freq[i],freq[k-i]);
	ret += freq[0]/2;
	if (k%2==0) ret += freq[k/2]/2;
	printf ("%d\n",ret<<1);
    return 0;
}