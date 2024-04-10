#include<cstdio>
#include<algorithm>
#include<cctype>
#include<string.h>
#include<cmath>
#include<vector>

using namespace std;
#define ll long long

const int N = 55, M = 1005, P = 1000000007;
int m, n, f[M], C[M][M];
char s[N][M];
vector<int> a[M];
int main() {
	scanf("%d%d", &m, &n);
	for(int i=0; i<=m; ++i) C[i][0]=1;
	for(int i=1; i<=m; ++i) for(int j=1; j<=i && j<=m; ++j) C[i][j]=(C[i-1][j]+C[i-1][j-1])%P;
	f[0]=1;
	for(int i=1; i<=m; ++i) for(int j=0; j<i; ++j) f[i]=(f[i]+(ll)f[i-j-1]*C[i-1][j])%P;

	for(int i=0; i<n; ++i) scanf("%s", s[i]);
	for(int i=0; i<m; ++i) for(int j=0; j<n; ++j) if(s[j][i]=='1') a[i].push_back(j);
	sort(a, a+m);
	int ans=1;
	for(int i=0, j=0; i<m; i=j){
		while(j<m && a[i]==a[j]) ++j;
		ans=(ll)ans*f[j-i]%P;
	}
	return printf("%d", ans), 0;
}