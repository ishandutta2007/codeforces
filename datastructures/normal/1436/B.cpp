#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>
using namespace std;
int t,n,ans[1005][1005];
inline bool p(int x){
	for (int i=2;i*i<=x;i++)
		if (x%i==0)return 0;
	return 1;
}
signed main(){
	cin>>t;
	while(t--){
		cin>>n;
		for (int i=1;i<=n;i++)
			for (int j=1;j<=n;j++)ans[i][j]=1;
		int num=1;
		while(!p(num+n-1)||p(num))++num;
		for (int i=1;i<=n;i++)
			ans[i][i]=num;
		for (int i=1;i<=n;i++){
			for (int j=1;j<=n;j++)printf("%d ",ans[i][j]);
			cout<<endl;
		}
	}
	return 0;
}