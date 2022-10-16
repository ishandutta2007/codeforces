#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <map>
#include <vector>
#include <queue>
#include <set>
using namespace std;
int t,n,c,sum[2000005],ch[2000005];
int main(){
	cin>>t;
	while(t--){
		cin>>n>>c;
		for (int i=1;i<=n;i++){
			int x;
			scanf("%d",&x);
			sum[x]=1;
		}
		for (int i=1;i<=c;i++)sum[i]+=sum[i-1];
		for (int i=1;i<=c;i++){
			for (int j=1;i*j<=c;j++)
				if (sum[i]>sum[i-1]&&sum[j]>sum[j-1])ch[i*j]++,ch[i*(j+1)]--;
		}
		int fg=1;
		for (int i=1;i<=c;i++){
			ch[i]+=ch[i-1];
			if (sum[i]>sum[i-1]&&ch[i]<sum[i])fg=0;
		}
		if (fg==1)puts("Yes");
		else puts("No");
		for (int i=1;i<=2*c;i++)sum[i]=ch[i]=0;
	}
	return 0;
}