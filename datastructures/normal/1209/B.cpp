#include <iostream>
#include <cstdio>
using namespace std;
int n,a[105],b[105],s[105],ans;
int main(){
//	freopen("b.in","r",stdin);
//	freopen("b.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n;i++){
		char ch;
		cin>>ch;
		s[i]=ch-'0';
	}
	for (int i=1;i<=n;i++)cin>>a[i]>>b[i];
	for (int t=0;t<=100000;t++){
		int now=0;
		for (register int i=1;i<=n;i++){
			now+=s[i];
			if (t>=b[i]&&(t-b[i])%a[i]==0)s[i]^=1;
		}
		ans=max(ans,now);
	}
	cout<<ans<<endl;
	return 0;
}