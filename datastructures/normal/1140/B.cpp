#include <iostream>
#include <cstdio>
using namespace std;
int t,n,flag;
char a[105];
int main(){
//	freopen("1140B.in","r",stdin);
//	freopen("1140B.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		int first=0,last=n;		
		for (int i=1;i<=n;i++)cin>>a[i];
		for (int i=1;i<=n;i++)
			if (a[i]=='<')first=i;
		for (int i=n;i>=1;i--)
			if (a[i]=='>')last=i;
		cout<<min(last-1,n-first)<<endl;
	}
}