#include<iostream>
using namespace std;
int n,m;
int a[15],b[15];
int va[15];
int vb[15];
int main() {
	ios::sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1; i<=n; ++i)  cin>>a[i],va[a[i]]++;
	for(int i=1; i<=m; ++i)  cin>>b[i],vb[b[i]]++;
	for(int i=1; i<=n; ++i) {
		if(va[a[i]]&&vb[a[i]]) {
			for(int j=1; j<=min(va[a[i]],vb[a[i]]); ++j)
				cout<<a[i]<<' ';
		}
	}
	cout<<'\n';
	return 0;
}