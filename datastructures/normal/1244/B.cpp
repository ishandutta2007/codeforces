#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int t,n,a[1005];
int main(){
//	freopen("b.in","r",stdin);
//	freopen("b.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		int ans=0,sum=0;
		char s[2005];
		scanf("%s",s);
		for (int i=1;i<=n;i++)a[i]=s[i-1]-'0';
		for (int i=1;i<=n;i++){
			sum+=a[i];
			if (a[i]==1)ans=max(ans,max(i*2,(n-i+1)*2));
		}
		ans=max(ans,n+sum);
		cout<<ans<<endl;
	}
	return 0;
}