#include<bits/stdc++.h>
using namespace std;
vector<string> a,b,c;
int main(){
	int n,m; scanf("%d%d",&n,&m);
	a.resize(n); b.resize(m);
	for(int i=0;i<n;++i) cin>>a[i];
	for(int i=0;i<m;++i) cin>>b[i];
	for(int i=0,j=0;;){
		c.push_back(a[i]+b[j]);
		++i; ++j;
		if(i>=n) i=0;
		if(j>=m) j=0;
		if(i==0&&j==0) break;
	}
	int q; scanf("%d",&q);
	while(q--){
		int x; scanf("%d",&x); --x;
		cout<<c[x%c.size()]<<endl;
	}
	return 0;
}