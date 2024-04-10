#include <iostream>
#include <cstdio>
using namespace std;
int n,ans;
char a[200005];
int main(){
//	freopen("a.in","r",stdin);
//	freopen("a.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n;i++)cin>>a[i];
	for (int i=1;i<=n;i+=2){
		if (a[i]==a[i+1]){
			ans++;
			if (a[i]=='a')a[i]='b';
			else a[i]='a';
		}
	}
	cout<<ans<<endl;
	for (int i=1;i<=n;i++)cout<<a[i];
	cout<<endl;
	return 0;
}