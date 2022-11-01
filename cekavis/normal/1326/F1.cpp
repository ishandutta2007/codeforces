#include<bits/stdc++.h>

using namespace std;
#define ll long long

const int N = 14, M = 1<<N;
int n, p[M];
char s[N][N];
vector<ll> f[M][N];
int main() {
	scanf("%d", &n);
	for(int i=0; i<n; ++i) scanf("%s", s[i]);
	for(int i=1; i<1<<n; ++i){
		p[i]=p[i>>1]+(i&1);
		for(int j=0; j<n; ++j) if(i>>j&1) f[i][j].resize(1<<p[i]>>1);
	}
	for(int i=0; i<n; ++i) f[1<<i][i][0]=1;
	for(int i=1; i<1<<n; ++i) for(int j=0; j<n; ++j) if(i>>j&1){
		for(int k=0; k<n; ++k) if(!(i>>k&1)){
			int x=s[j][k]=='1', y=i|(1<<k), z=x<<p[i]>>1;
			for(int t=0; t<1<<p[i]>>1; ++t) f[y][k][t|z]+=f[i][j][t];
		}
	}
	for(int i=0; i<1<<n>>1; ++i){
		ll x=0;
		for(int j=0; j<n; ++j) x+=f[(1<<n)-1][j][i];
		printf("%lld ", x);
	}
	return 0;
}