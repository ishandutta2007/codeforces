#include<bits/stdc++.h>
using namespace std;
char _;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
template <typename t> void scan (t& x) {do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0);}
template <typename t, typename ...r> void scan (t& x, r&... xs) {scan(x); scan(xs...);}
const int MN = 1e5+1;
int lis[MN];
bool one[MN];
int best[2];
char s[MN];
char ans[MN];
int main () {
	scanf ("%s",s);
	int n = strlen(s);
		best[0] = best[1] = 0;
		for (int i = n-1; i >= 0; i--) {
			if (s[i] == '0') lis[i] = best[0] = max(best[0],best[1])+1;
			else lis[i]= ++best[1];
		} 
		best[0] = best[1] = 0;
		for (int i = n-1; i >= 0; i--) {
			if (lis[i] != max(best[0],best[1])+1) one[i] = 1;;
			if (s[i] == '0') lis[i] = best[0] = max(best[0],best[1])+1;
			else lis[i] = ++best[1];
		}
	for (int i = 0; i < n; i++) putchar(one[i] ? '1' : '0');
	putchar(10); 
	return 0;
}