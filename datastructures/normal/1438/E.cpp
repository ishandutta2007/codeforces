#include <iostream>
#include <cstdio>
#define int long long
using namespace std;
int n,a[1000005],ans;
signed main(){
	cin>>n;
	for (int i=1;i<=n;i++)scanf("%lld",&a[i]);
	for (int i=1;i<=n;i++){
		int num=0;
		while(num<a[i])num=num*2+1;
		for (int j=i-2,sum=a[i-1];j>0;j--){
			if (sum>num)break;
			if (a[i]>a[j]&&sum==(a[i]^a[j]))ans++;
			sum+=a[j];
		}
		for (int j=i+2,sum=a[i+1];j<=n;j++){
			if (sum>num)break;
			if (a[i]>a[j]&&sum==(a[i]^a[j]))ans++;
			sum+=a[j];
		}
	}
	cout<<ans<<endl;
	return 0;
}