
// Problem : E. LIS of Sequence
// Contest : Codeforces Round #277 (Div. 2)
// URL : https://codeforces.com/problemset/problem/486/E
// Memory Limit : 256.000000 MB
// Time Limit : 2000.000000 milisec
// Powered by CP Editor (https://github.com/coder3101/cp-editor)

#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using ld = long double;
#define all(x) (x).begin(),(x).end()
#define io() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
const int MN = 1e5+3;
int a[MN], bit[MN], dp[MN], ans[MN]; bool in[MN];
vector<int> best[MN];
void update (int i, int v) {
	for (;i<MN;i+=i&-i)
		bit[i] = max(bit[i],v);
}
int query (int i) {
	int ret = 0;
	for(;i;i^=i&-i)
		ret = max(ret,bit[i]);
	return ret;
}
void update2 (int i, int v) {
	for (i=MN-i;i<MN;i+=i&-i)
		bit[i] = min(bit[i],v);
}
int query2 (int i) {
	int ret = INT_MAX;
	for (i=MN-i;i;i^=i&-i)
		ret = min(ret,bit[i]);
	return ret;
}
int main () {
	int n;
	scanf ("%d",&n);
	for (int i = 1; i <= n; i++) {
		scanf ("%d",&a[i]);
		update(a[i],dp[i] = query(a[i]-1)+1);
		best[dp[i]].push_back(i);
	}
	int lis = query(MN-1);
	memset(bit,0x3f,sizeof bit);
	for (int i = n; i >= 1; i--){
		in[i] = dp[i] == lis || query2(a[i]+1) == dp[i]+1;
		if (in[i]) update2(a[i],dp[i]), ans[i] = 1;
	}
	for (int i = 1; i <= lis; i++) {
		int cnt = 0, which = -1;
		for (int j : best[i]) if (in[j]) ++cnt, which = j;
		if (cnt == 1) ans[which] = 2;
	}
	for (int i = 1; i <= n; i++) printf ("%d",ans[i]+1);
	printf ("\n");
	return 0;
}