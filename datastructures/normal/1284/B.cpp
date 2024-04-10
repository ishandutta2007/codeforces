#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define int long long
using namespace std;
int n,qwq[1000005],awa,mn[1000005],mx[1000005],cnt1[1000005],cnt2[1000005];
int ans;
signed main(){
	cin>>n;
	for (int i=1;i<=n;i++){
		int l,x;
		scanf("%lld",&l);
		mn[i]=1000000000,mx[i]=0;
		int fg=0,lst=1000000000;
		for (int j=1;j<=l;j++){
			scanf("%lld",&x);
			if (x>lst)fg=1;
			lst=x;
			mn[i]=min(mn[i],x);
			mx[i]=max(mx[i],x);
		}
		if (fg==1)qwq[i]=-1,awa++;
		else{
			cnt1[mn[i]]++;
			cnt2[mx[i]]++;
		}
	}
	ans+=n*n-(n-awa)*(n-awa);
	for (int i=1;i<=1000000;i++)cnt1[i]+=cnt1[i-1];
	for (int i=1000000;i>=0;i--)cnt2[i]+=cnt2[i+1];
	for (int i=1;i<=n;i++)
		if (qwq[i]!=-1){
			if (mx[i]>0)ans+=cnt1[mx[i]-1];
		}
	cout<<ans<<endl;
	return 0;
}