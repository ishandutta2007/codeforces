
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
const int MN = 5e5+5;
char s[MN];
int main () {
	int t;
	scanf ("%d",&t);
	while (t--) {
		scanf ("%s",s);
		deque<char> odd,even;
		int n = strlen(s);
		for (int i = 0; i < n; i++)
			(s[i]&1?odd:even).push_back(s[i]);
		for (int i = 0; i < n; i++) {
			if (odd.empty() || (!even.empty() && even.front()<odd.front())) {
				printf ("%c",even.front()); even.pop_front();
			}
				else{
					printf ("%c",odd.front()); odd.pop_front();
				}
		}
		printf ("\n");
		memset(s,0,sizeof (char) * (n+1));
	}
	return 0;
}