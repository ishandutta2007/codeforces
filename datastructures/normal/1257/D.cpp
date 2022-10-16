#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int t,n,m,a[200005];
int mx[200005];
int max1,max2,ans;
int main(){
	cin>>t;
	while(t--){
		scanf("%d",&n);
		max1=max2=ans=0;
		for (int i=1;i<=n;i++)mx[i]=0;
		for (int i=1;i<=n;i++)scanf("%d",&a[i]),max1=max(max1,a[i]);
		scanf("%d",&m);
		for (int i=1;i<=m;i++){
			int p,s;
			scanf("%d%d",&p,&s);
			mx[s]=max(mx[s],p);
			max2=max(max2,p);
		}
		if (max1>max2){
			printf("%d\n",-1);
			continue;
		}
		for (int i=n-1;i>=1;i--)mx[i]=max(mx[i],mx[i+1]);
		for (int i=1;i<=n;){
			int j=i,now=a[i],nows=1;
			while(mx[nows]>=now)j++,nows++,now=max(now,a[j]);
			i=j,ans++;
		}
		printf("%d\n",ans);
	}
}