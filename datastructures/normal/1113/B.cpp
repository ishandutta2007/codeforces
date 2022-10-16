#include <iostream>
#include <cstdio>
using namespace std;
int n,a[100005],sum,cnt[105],ans;
int main(){
	cin>>n;
	for (int i=1;i<=n;i++)scanf("%d",&a[i]),cnt[a[i]]++,sum+=a[i];
	ans=sum;
	for (int i=1;i<=100;i++)
		for (int j=1;j<=100;j++){
			if (cnt[i]==0||cnt[j]==0)continue;
			for (int k=1;k<=100;k++)
				if (j%k==0)ans=min(ans,sum-i-j+i*k+j/k);
		}
	cout<<ans<<endl;
	return 0;
}