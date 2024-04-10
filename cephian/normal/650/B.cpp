#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <random>
#include <string>
#include <vector>
#include <cmath>
#include <queue>
#include <set>
#include <map>
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;

ll n,a,b,T,cw=0;
string s;

const int N = 500005;
ll dpf[N],dpb[N];

ll g(ll* A, ll* B) {
	int j = n, ans = 0;
	for(int i = 1; A[i]+a*(i-1) <= T; ++i) {
		ll L = A[i]+a*(i-1);
		while(j > 0 && L+B[j]-cw > T) --j;
		if(j == 0) break;
		ans = max(ans,i+j-1);
	}
	return ans;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n >> a >> b >> T >> s;
	dpf[0] = dpb[0] = 0;
	ll bst = 0;
	cw = b*(s[0]=='w')+1;
	for(int i = 1; i <= n; ++i) {
		dpf[i] = dpf[i-1] + a*!!(i-1) + b*(s[i-1]=='w') + 1;
		dpb[i] = dpb[i-1] + a*!!(i-1) + b*(s[(n-i+1)%n]=='w') + 1;
		if(dpf[i] <= T || dpb[i] <= T) bst = i;
	}
	if(bst != n)
		bst = max(bst,max(g(dpf,dpb),g(dpb,dpf)));
	cout << bst << "\n";
	return 0;
}