#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
#define pii pair<int, int>
#define M 1000000007
#define all(a) a.begin(), a.end()
typedef long long ll;

ll q[5001000];
int n;

int Q;
ll L, R;

bool check(int a, int b){
	return pow(a, b) <= 1e18 + 10;
}

int getSqrt(ll m){
	return sqrt(m + 0.1);
}

int main(){
	for(int b = 3; b <= 60; b += 2){
		for(int i = 2; check(i, b); ++i){		 
			static ll Lim = 1e18;
			int t = getSqrt(i);
			if(t * t == i) continue;
			ll num = i;
			for(int j = 1; j < b; ++j) num *= i;
			if(num <= Lim)
				q[n++] = num;
		}
	}
	sort(q, q + n);
	n = unique(q, q + n) - q;
	
	scanf("%d", &Q);
	while(Q--){
		scanf("%I64d%I64d", &L, &R);
		int l = lower_bound(q, q + n, L) - q;
		int r = upper_bound(q, q + n, R) - q;
		int ans = r - l;
		ans += getSqrt(R) - getSqrt(L - 1);
		printf("%d\n", ans);
	}
	
#ifndef ONLINE_JUDGE
	system("pause");
#endif
	return 0;
}