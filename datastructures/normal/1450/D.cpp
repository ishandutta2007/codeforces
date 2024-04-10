#include <iostream>
#include <cstdio>
using namespace std;
int t,n,a[300005],ans[300005];
int cnt[300005];
int main(){
	cin>>t;
	while(t--){
		cin>>n;
		int fg=1;
		for (int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			cnt[a[i]]++;
			if (cnt[a[i]]>1)fg=0;
		}
		if (fg==1)ans[1]=1;
		int l=1,r=n;
		for (int i=1;i<=n;i++){
			if (cnt[i]==0)break;
			ans[n-i+1]=1;
			if (i!=a[l]&&i!=a[r])break;
			if (cnt[i]>1)break;
			if (i==a[l])l++;
			else if (i==a[r])r--;
		}
		for (int i=1;i<=n;i++)putchar('0'+ans[i]);
		puts("");
		for (int i=1;i<=n;i++)a[i]=ans[i]=cnt[i]=0;
	}
	return 0;
}