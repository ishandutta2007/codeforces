#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <map>
#include <vector>
#include <queue>
#define int long long
using namespace std; 
int t,n,a[100005],pos[100005];
signed main(){
	cin>>t;
	while(t--){
		cin>>n;
		for (int i=1;i<=n;i++)scanf("%lld",&a[i]),pos[a[i]]=i;
		int now=n+1;
		for (register int i=n;i>=1;i--){
			if (pos[i]>=now)continue;
			for (register int j=pos[i];j<now;j++)printf("%lld ",a[j]);
			now=pos[i];
		}
		cout<<endl;
	}
	return 0;
}