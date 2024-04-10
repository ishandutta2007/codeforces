#include <iostream>
#include <cstdio>
#include <cstring>
#define move 100000
using namespace std;
int t,n,a[2000005],book[2000005],ans;
int main(){
	cin>>t;
	while(t--){
		cin>>n;
		for (int i=move-n;i<=move+n;i++)book[i]=2e9;
		for (int i=1;i<=2*n;i++)scanf("%d",&a[i]);
		int s=0;
		for (int i=n+1;i<=2*n;i++){
			if (a[i]==1)s--;
			else s++;
		}
		book[s+move]=0;
		for (int i=1;i<=n;i++){
			if (a[n+i]==1)s++;
			else s--;
			book[s+move]=min(book[s+move],i);
		}
		s=0;
		for (int i=1;i<=n;i++){
			if (a[i]==1)s--;
			else s++;
		}
		ans=book[-s+move];
		for (int i=1;i<=n;i++){
			if (a[n-i+1]==1)s++;
			else s--;
			ans=min(ans,i+book[-s+move]);
		}
		cout<<ans<<endl;
	}
	return 0;
}