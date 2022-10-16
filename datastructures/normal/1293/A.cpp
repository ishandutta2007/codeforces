#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
#include <map>
#include <vector>
#include <queue>
using namespace std;
int t,n,s,k,a[10005];
signed main(){
//	freopen("a.in","r",stdin);
//	freopen("a.out","w",stdout);
	cin>>t;
	while(t--){
		memset(a,0,sizeof(a));
		cin>>n>>s>>k;
		for (int i=1;i<=k;i++)scanf("%d",&a[i]);
		sort(a+1,a+1+k);
		int now=-1;
		for (int i=1;i<=k;i++)
			if (a[i]==s)now=i;
		if (now==-1){
			cout<<0<<endl;
			continue;
		}
		int l=now,r=now,ans=2e9;
		while(l>=1){
			if (a[l]-a[l-1]!=1)break;
			l--;
		}
		if (a[l]>1)ans=min(ans,s-(a[l]-1));
		while(r<=k){
			if (a[r+1]-a[r]!=1)break;
			r++;
		}
		if (a[r]!=0&&a[r]<n)ans=min(ans,(a[r]+1)-s);
		cout<<ans<<endl;
	}
	return 0;
}