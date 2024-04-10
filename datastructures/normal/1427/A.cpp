#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int t,n,a[100005];
int s1,s2;
int main(){
	cin>>t;
	while(t--){
		cin>>n;
		s1=s2=0;
		for (int i=1;i<=n;i++){
			cin>>a[i];
			if (a[i]>0)s1+=a[i];
			else s2-=a[i];
		}
		if (s1==s2)puts("NO");
		else{
			puts("YES");
			int fg=1;
			if (s1>s2)fg=-1;
			for (int i=1;i<=n;i++)a[i]=a[i]*fg;
			sort(a+1,a+1+n);
			for (int i=1;i<=n;i++)cout<<a[i]*fg<<' ';
			cout<<endl;
		}
	}
	return 0;
}