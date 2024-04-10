#include <iostream>
#include <cstdio> 
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
#include <queue>
using namespace std;
int n,m,now,a[200005],sum,t[105];
signed main(){
	cin>>n>>m;
	for (int i=1;i<=n;i++)scanf("%d",&a[i]);
	for (int i=1;i<=n;i++){
		sum+=a[i];
		int ans=0;
		int delta=sum-m;
		for (int j=100;j>=1;j--){
			if (delta<=0)break;
			int ne=(delta-1)/j+1;
			ne=min(ne,t[j]);
			ans+=ne,delta-=ne*j;
		}
		t[a[i]]++;
		printf("%d ",ans);
	}
	cout<<endl;
	return 0;
}