
// Problem : B. Binary Palindromes
// Contest : Educational Codeforces Round 75 (Rated for Div. 2)
// URL : https://codeforces.com/contest/1251/problem/B
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
char s[100];
int main () {
	int t;
	scanf ("%d",&t);
	while (t--) {
		int n;
		scanf ("%d",&n);
		int cnt0=0,cnt1=0;
		vector<int> lens(n);
		int pchange = 0;
		for (auto &au : lens) {
			scanf ("%s",s);
			au = strlen(s);
			pchange += au&1;
			for (int i = 0; i < au; i++)
				(s[i]=='1'?cnt1:cnt0)++;
		}
		if (pchange & 1) {
			printf ("%d\n",n-1+((cnt0&1)^(cnt1&1)));
		} else if (pchange == 0) {
			printf ("%d\n",n-1+!(cnt0&1||cnt1&1));
		} else {
			printf ("%d\n",n-1+!((cnt0&1)^(cnt1&1)));
		}
	}
	return 0;
}