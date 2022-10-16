#include <iostream>
#include <cstdio> 
#include <cstring>
using namespace std;
int t,n,x,a[205],book[205];
int main(){
	cin>>t;
	while(t--){
		memset(book,0,sizeof(book));
		cin>>n>>x;
		for (int i=1;i<=n;i++)cin>>a[i],book[a[i]]=1;
		int ans=0;
		for (int i=1;i<=200;i++){
			if (book[i]==0&&x==0)break;
			if (book[i]==0)book[i]=1,x--,ans=i;
			ans=i;
		}
		cout<<ans<<endl;
	} 
	return 0;
}