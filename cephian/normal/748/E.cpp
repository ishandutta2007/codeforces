#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstdio>
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

int n,k;
int a[1000005];
ll sm=0,l;

int w = 0;
int used[10000000];
int dp[10000005]={0};

int maxamt(int b) {
	if(b < l) return 0;
	if(!dp[b]) {
		used[w++] = b;
		dp[b] = max(1,maxamt(b/2) + maxamt((b+1)/2));
	}
	return dp[b];
}

bool ok(ll q) {
	for(int i = 0; i < w; ++i)
		dp[used[i]] = 0;
	w=0;
	l=q;
	ll total = 0;
	for(int i = 0; i < n; ++i) {
		total += maxamt(a[i]);
		if(total >= k) return true;
	}
	return false;
}

int main() {
	scanf("%d%d",&n,&k);
	for(int i = 0; i < n; ++i) {
		scanf("%d",&a[i]);
		sm+=a[i];
	}
	sort(a,a+n,greater<int>());
	if(sm < k) {
		printf("-1\n");
		return 0;
	}
	int lo = 1,hi = 10000001;
	while(hi-lo > 1) {
		int mid = (lo+hi)/2;
		if(ok(mid)) lo = mid;
		else hi = mid;
	}
	printf("%d\n",lo);
	return 0;
}