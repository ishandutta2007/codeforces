#include<bits/stdc++.h>
using namespace std;
char _;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
template <typename t> void scan (t& x) {do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0);}
template <typename t, typename ...r> void scan (t& x, r&... xs) {scan(x); scan(xs...);}
const int MAXN = 1e5+2;
int main () {
	string s;
	getline(cin,s);
	int n = s.length()-1;
	for (int i = 1; i < s.length(); i++) {
		if (s[i] != '0') {n++; break;}
	}
	printf ("%d\n",(n+1)/2);
	return 0;
}