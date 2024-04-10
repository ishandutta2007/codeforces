#include<bits/stdc++.h>
using namespace std;
int main(){
	vector<int> a,b;
	int n; scanf("%d",&n); a.resize(n); b.resize(n);
	int mx=0;
	for(int i=0;i<n;++i) scanf("%d",&b[i]);
	for(int i=0;i<n;++i){
		a[i]=b[i]+mx;
		mx=max(mx,a[i]);
	}
	for(int i=0;i<n;++i) printf("%d ",a[i]); 
	return 0;
}