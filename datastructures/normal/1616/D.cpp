#include <iostream>
#include <cstdio>
using namespace std;
int t,n,a[1000005],x;
int f[50005];
int main(){
	cin>>t;
	while(t--){
		cin>>n;
		for (int i=1;i<=n;i++)scanf("%d",&a[i]);
		cin>>x;
		for (int i=1;i<=n;i++)a[i]-=x;
		int j=1;
		for (int i=1;i<=n;i++){
			f[i]=f[i-1];
			if (i>=2&&a[i]+a[i-1]<0)j=max(j,i);
			if (i>=3&&a[i]+a[i-1]+a[i-2]<0)j=max(j,i-1);
			int s=i-j+1;
			if (j>=2)s+=f[j-2];
			f[i]=max(f[i],s);
		}
		cout<<f[n]<<endl;
	}
	return 0;
}