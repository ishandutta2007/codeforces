#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define fio ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;

int n;
char h = 'a';
vector<char> c;

void go() {
	ll k = 2;
	while(k*(k+1)/2 <= n) ++k;
	n -= (k*(k-1))/2;
	cout << k*(k-1)/2 << endl;
	while(k--)
		c.pb(h);
	++h;
}

const int N = 1e5+5;
int dp[N], ch[N];

int main() {
	fio;
	scanf("%d",&n);
	if(n==0) {
		printf("a\n");
		return 0;
	}
	dp[0] = 0;
	for(int i = 1; i < N; ++i) {
		dp[i] = 1<<20;
		for(ll k = 2; k*(k-1)/2 <= i; ++k) {
			ll r = k*(k-1)/2;
			if(dp[i-r]+1 < dp[i]) {
				dp[i] = dp[i-r]+1;
				ch[i] = k;
			}
		}
	}
	char c = 'a';
	while(n) {
		for(int i = 0; i < ch[n]; ++i)
			printf("%c",c);
		n -= ch[n]*(ch[n]-1)/2;
		++c;
	}
	printf("\n");
}