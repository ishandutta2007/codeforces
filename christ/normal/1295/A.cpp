#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using ld = long double;
#define all(x) (x).begin(),(x).end()
#define io() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
int main () {
	int t;
	scanf ("%d",&t);
	while (t--) {
		int n;
		scanf ("%d",&n);
		vector<char> ret;
		while (n) {
			if (n == 3) {
				ret.push_back('7');
				break;
			}
		    ret.push_back('1');
			n -= 2;
		}
		reverse(ret.begin(),ret.end());
		for (char c : ret) putchar(c);
		putchar(10);
	}
	return 0;
}