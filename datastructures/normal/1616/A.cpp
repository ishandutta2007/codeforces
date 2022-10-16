#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int t,n,a[10005],book[10005];
int main(){
	cin>>t;
	while(t--){
		cin>>n;
		memset(book,0,sizeof(book));
		for (int i=1;i<=n;i++){
			cin>>a[i];
			if (a[i]<0)book[-a[i]]++;
			else book[a[i]]++;
		}
		int ans=0;
		for (int i=1;i<=100;i++)ans+=min(book[i],2);
		if (book[0]>0)ans++;
		cout<<ans<<endl;
	}
	return 0;
}