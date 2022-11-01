#include<cstdio>
#include<algorithm>
#include<cctype>
#include<string.h>
#include<cmath>
#include<vector>

using namespace std;
#define ll long long

const int N = 305, M = N*N;
ll ans;
int n, cnt, x[N], y[N], f[N][N][6];
pair<int,int> a[M];
inline bool cmp(pair<int,int> a, pair<int,int> b){
	int X1=x[a.second]-x[a.first], Y1=y[a.second]-y[a.first], X2=x[b.second]-x[b.first], Y2=y[b.second]-y[b.first];
	if((X1<0)^(X2<0)) return X1>X2;
	if(!X1 && !X2) return Y1>Y2;
	return (ll)X1*Y2-(ll)X2*Y1<0;
}
int main() {
	scanf("%d", &n);
	for(int i=1; i<=n; ++i) scanf("%d%d", x+i, y+i);
	for(int i=1; i<=n; ++i) for(int j=1; j<=n; ++j) if(i!=j) a[++cnt]=make_pair(i, j);
	sort(a+1, a+cnt+1, cmp);
	for(int i=1; i<=n; ++i) f[i][i][0]=1;
	for(int i=1; i<=cnt; ++i) for(int j=1; j<=n; ++j) for(int k=0; k<5; ++k)
		f[j][a[i].second][k+1]+=f[j][a[i].first][k];
	for(int i=1; i<=n; ++i) ans+=f[i][i][5];
	return printf("%lld", ans), 0;
}