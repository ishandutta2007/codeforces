#include<bits/stdc++.h>

using namespace std;
#define ll long long

const int N = 1005;
int n, d[N];
bitset<N> a[N], aa[N], p[N], ans[N];
int main() {
	scanf("%d", &n);
	bool o=1;
	for(int i=1, t; i<=n; ++i){
		scanf("%d", &t), o&=t==n;
		for(int j=0, x; j<t; ++j) scanf("%d", &x), a[i][x]=1, aa[x][i]=1;
	}
	if(o){
		for(int i=2; i<=n; ++i) printf("1 %d\n", i);
		return 0;
	}
	for(int i=1; i<n; ++i) for(int j=i+1; j<=n; ++j){
		auto t=a[i]&a[j];
		if((int)t.count()==2){
			int x=t._Find_first(), y=t._Find_next(x);
			if(!ans[x][y]) ans[x][y]=ans[y][x]=1, ++d[x], ++d[y];
		}
	}
	for(int i=1; i<=n; ++i) if(ans[i].none()){
		bitset<N> x;
		x.set();
		for(int j=1; j<=n; ++j) if(a[j][i] && a[j].count()<x.count()) x=a[j];
		for(int j=1; j<=n; ++j) if(x[j] && (int)(ans[j]&x).count()>1){
			ans[i][j]=ans[j][i]=1;
			goto nxt;
		}
		for(int j=1; j<=n; ++j) if(x[j] && d[j]==1 && (p[j].none() || p[j]==x)){
			p[j]=x;
			break;
		}
		nxt:;
	}
	for(int i=1; i<n; ++i) for(int j=i+1; j<=n; ++j)
		if(ans[i][j] || p[i][j] || p[j][i]) printf("%d %d\n", i, j);
	return 0;
}