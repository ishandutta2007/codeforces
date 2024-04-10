#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int n,a[2000005],cnt[2000005],mx,id,c[2000005],book[2000005],sum,ans;
int main(){
	cin>>n;
	for (int i=1;i<=n;i++)scanf("%d",&a[i]),cnt[a[i]]++,mx=max(mx,cnt[a[i]]);
	for (int i=1;i<=n;i++) 
		if (cnt[a[i]]==mx)id=a[i];
	if (mx==n){
		cout<<0<<endl;
		return 0;
	}
	for (int i=1;i<=100;i++){
		if (i==id)continue;
		memset(book,0,sizeof(book));
		sum=0;
		for (int j=1;j<=n;j++){
			if (a[j]==id)sum++;
			if (a[j]==i)sum--;
			if (book[sum+n]!=0)ans=max(ans,j-book[sum+n]);
			else if (sum!=0)book[sum+n]=j;
			if (sum==0)ans=max(ans,j);
		}
	}
	cout<<ans<<endl;
	return 0;
}