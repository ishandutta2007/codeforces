#include <iostream>
#include <cstdio> 
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
using namespace std;
int t,n,a[200005],k,d,book[1000005],num,ans=2e9;
signed main(){
	cin>>t;
	while(t--){
		cin>>n>>k>>d;
		for (int i=1;i<=n;i++)scanf("%d",&a[i]);
		for (int i=1;i<=n;i++)book[a[i]]=0;
		ans=2e9,num=0;
		for (int i=1;i<=d;i++){
			book[a[i]]++;
			if (book[a[i]]==1)num++;
		}
		ans=min(ans,num);
		for (int i=2;i+d-1<=n;i++){
			book[a[i-1]]--;
			if (book[a[i-1]]==0)num--;
			book[a[i+d-1]]++;
			if (book[a[i+d-1]]==1)num++;
			ans=min(ans,num);
		}
		cout<<ans<<endl;
	}
	return 0;
}