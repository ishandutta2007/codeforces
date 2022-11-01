#include<bits/stdc++.h>

using namespace std;
#define ll long long

const int N = 1005;
int n, cnt, a[N][N];
int main() {
	scanf("%d", &n);
	for(int i=0; i<n; i+=4) for(int j=0; j<n; j+=4)
		for(int x=0; x<4; ++x) for(int y=0; y<4; ++y) a[i+x][j+y]=cnt++;
	for(int i=0; i<n; ++i) for(int j=0; j<n; ++j)
		printf("%d%c", a[i][j], " \n"[j==n-1]);
	int ans=0;
	for(int i=0; i<n; ++i){
		for(int j=0; j<n; ++j) ans^=a[i][j];
		assert(!ans);
		for(int j=0; j<n; ++j) ans^=a[j][i];
		assert(!ans);
	}
	return 0;
}