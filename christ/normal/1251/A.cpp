
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
char s[700];
int main () {
	int t;
	scanf ("%d",&t);
	while (t--) {
		scanf ("%s",s);
		int n = strlen(s);
		for (char letter = 'a'; letter <= 'z'; letter++) {
			for (int i = 0; i < n; i++) {
				if (s[i] == letter) {
					if (s[i+1] != letter) {
						printf ("%c",letter);
						break;
					}
					i++;
				}
			}
		}
		printf ("\n");
	}
	return 0;
}