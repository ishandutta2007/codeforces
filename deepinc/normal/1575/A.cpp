#include<bits/stdc++.h>

using namespace std;

#define N 1200000

int n,m,a[N];
vector<char> f[N];

bool cmp(int x,int y){
	for (int i=0;i<m;++i){
		if (f[x][i]!=f[y][i]){
			return (i&1)^(f[x][i]<f[y][i]);
		}
	}
	return 0;
}

int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;++i){
		for (int j=1;j<=m;++j){
			char x;
			for (x=getchar();x<'A'||x>'Z';x=getchar());
			f[i].push_back(x);
		}
	}
	for (int i=1;i<=n;++i) a[i]=i;
	sort(a+1,a+n+1,cmp);
	for (int i=1;i<=n;++i) printf(i==n?"%d\n":"%d ",a[i]);
	
	return 0;
}