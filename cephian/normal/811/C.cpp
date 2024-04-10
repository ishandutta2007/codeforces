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

const int N = 5005;
int a[N],first[N]={0},last[N],n,dp[N];

int main() {
	scanf("%d",&n);
	for(int i = 1; i <= n; ++i) {
		scanf("%d",a+i);
		if(!first[a[i]])
			first[a[i]] = i;
		last[a[i]] = i;
	}
	dp[0] = 0;
	for(int j = 1; j <= n; ++j) {
		dp[j] = dp[j-1];
		int fs = 0x7fffffff,ls = -1,x=0;
		for(int i = j; i >= 1; --i) {
			fs = min(fs,first[a[i]]);
			ls = max(ls,last[a[i]]);
			if(first[a[i]] == i)
				x ^= a[i];
			if(ls > j) break;
			if(fs >= i)
				dp[j] = max(dp[j],x + dp[i-1]);
		}
	}
	printf("%d\n",dp[n]);


	return 0;
}