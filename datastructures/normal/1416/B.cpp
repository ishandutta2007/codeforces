#include <iostream>
#include <cstdio>
using namespace std;
int t,n,a[100005];
int tot,ans1[100005],ans2[100005],ans3[100005];
signed main(){
	cin>>t;
	while(t--){
		cin>>n;
		int sum=0;
		for (int i=1;i<=n;i++)cin>>a[i],sum+=a[i];
		if (sum%n!=0){
			puts("-1");
			continue;
		}
		tot=0;
		for (int i=2;i<=n;i++){
			if (a[i]%i!=0){
				int move=i-a[i]%i;
				++tot;
				ans1[tot]=1,ans2[tot]=i,ans3[tot]=move;
				a[1]-=move,a[i]+=move;
			}
			int move=a[i]/i;
			++tot;
			ans1[tot]=i,ans2[tot]=1,ans3[tot]=move;
			a[1]+=move*i,a[i]-=move*i;
		}
		for (int i=2;i<=n;i++){
			int move=sum/n;
			++tot;
			ans1[tot]=1,ans2[tot]=i,ans3[tot]=move;
			a[1]-=move,a[i]+=move;
		}
		cout<<tot<<endl;
		for (int i=1;i<=tot;i++)cout<<ans1[i]<<' '<<ans2[i]<<' '<<ans3[i]<<endl;
	}
	return 0;
}