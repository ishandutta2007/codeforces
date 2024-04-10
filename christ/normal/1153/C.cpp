#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#pragma GCC diagnostic ignored "-Wunused-result" 
#pragma GCC diagnostic ignored "-Wsign-compare" 
using namespace std;
using namespace __gnu_pbds;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using ld = long double;
#define all(x) (x).begin(),(x).end()
#define io() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
const int MN = 3e5+3, BASE = 31, LOG = 20;
char s[MN];
int bacc[MN];
int main() {
	int n;
	scanf ("%d",&n);
	if (n&1) return !printf (":(\n");
	scanf ("%s",s+1);
	if (s[1] == ')' || s[n] == '(') return !printf (":(\n");
	s[1] = '('; s[n] = ')';
	int cnt1 = 0, cnt2 = 0;
	for (int i = 2; i < n; i++) {
		if (s[i] == '(') ++cnt1;
		if (s[i] == ')') ++cnt2;
	}
	if (cnt1 > n/2-1 || cnt2 > n/2-1) return !printf (":(\n");
	for (int i = n-1; i >= 2; i--) {
		bacc[i] = bacc[i+1] + (s[i]=='('?-1:1);
	}
	int pre = 0;
	for (int i = 2; i < n; i++) {
		if (s[i]=='?') {
			if (bacc[i+1] >= pre+1)
				s[i] = '(';
			else
				s[i] = ')';
		}
		pre += s[i]=='('?1:-1;
		if (pre < 0) return !printf (":(\n");
	}
	printf ("%s\n",pre?":(":s+1);
	return 0;
}
//orz ninjaclasher