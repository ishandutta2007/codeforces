#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for (int i=a; i<b; i++)
#define F0R(i, a) for (int i=0; i<a; i++)
 
int dp[31][31][51];
bool done[31][31][51];

int get(int a, int b, int c) {
	if (a<b) swap(a,b);
	if (done[a][b][c]) return dp[a][b][c];
	if (a*b == c || c == 0) return 0;
	int a1 = (1<<20), b1 = (1<<20);
	FOR(i,1,a) FOR(j,max(0,c-(a-i)*b), min(b*i,c)+1) a1 = min(a1,get(i,b,j)+get(a-i,b,c-j));
	FOR(i,1,b) FOR(j,max(1,c-(b-i)*a), min(a*i,c)+1) b1 = min(b1,get(i,a,j)+get(b-i,a,c-j));
	a1 += b*b, b1 += a*a;
	dp[a][b][c] = min(a1,b1), done[a][b][c] = 1;
	return dp[a][b][c];
}

int main() {
	int t,n,m,k;
	cin >> t;
	F0R(i,t) scanf("%d%d%d",&n,&m,&k),printf("%d\n", get(n,m,k));
}