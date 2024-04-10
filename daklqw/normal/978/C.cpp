#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
#define int long long
#define MAXN 200010
int n,m,pre[MAXN],b[MAXN];
signed main(){
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>pre[i];
		pre[i]+=pre[i-1];
	}
	int cur=0;
	for(int i=1;i<=m;++i){
		cin>>b[i];
		while(b[i]>pre[cur])++cur;
		cout<<cur<<" "<<b[i]-pre[cur-1]<<endl;
	}
	return 0;
}