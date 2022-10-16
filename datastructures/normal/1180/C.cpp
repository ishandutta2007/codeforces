#include <iostream>
#include <cstdio> 
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
#define int long long
using namespace std;
int n,a[1000005],mx,q,m;
int ans[1000005][2],tot,b[1000005];
signed main(){
	cin>>n>>q;
	for (int i=1;i<=n;i++)scanf("%I64d",&a[i]),mx=max(mx,a[i]);
	int head=1,tail=n;
	while(a[head]!=mx){
		tot++;
		ans[tot][0]=a[head],ans[tot][1]=a[head+1];
		int x=a[head],y=a[head+1];
		head+=2;
		if (x>y)a[--head]=x,a[++tail]=y;
		else a[--head]=y,a[++tail]=x;
	}
	for (int i=1;i<n;i++)b[i]=a[head+i];
	while(q--){
		scanf("%I64d",&m);
		if (m<=tot)printf("%I64d %I64d\n",ans[m][0],ans[m][1]);
		else{
			m-=tot;
			m%=n-1;
			if (m==0)m=n-1;
			printf("%I64d %I64d\n",mx,b[m]);
		}
	}
	return 0;
}