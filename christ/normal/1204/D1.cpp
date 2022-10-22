#include<bits/stdc++.h>
using namespace std;
char _;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
template <typename t> void scan (t& x) {do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0);}
template <typename t, typename ...r> void scan (t& x, r&... xs) {scan(x); scan(xs...);}
const int MN = 2e3+1;
int lis[MN][MN];
bool one[MN];
int best[2];
char s[MN];
char ans[MN];
int main () {
	scanf ("%s",s);
	int n = strlen(s);
	for (int end = n-1; end >= 0; end--) {
		best[0] = best[1] = 0;
		for (int i = end; i >= 0; i--) {
			if (s[i] == '0') lis[i][end] = best[0] = max(best[0],best[1])+1;
			else lis[i][end] = ++best[1];
		}
	}
	for (int end = n-1; end >= 0; end--) {
		best[0] = best[1] = 0;
		for (int i = end; i >= 0; i--) {
			if (lis[i][end] != max(best[0],best[1])+1) one[i] = 1;;
			if (s[i] == '0') lis[i][end] = best[0] = max(best[0],best[1])+1;
			else lis[i][end] = ++best[1];
		}
	}
	for (int i = 0; i < n; i++) putchar(one[i] ? '1' : '0');
	putchar(10); 
	return 0;
}