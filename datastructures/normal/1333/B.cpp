#include <iostream>
#include <cstdio>
using namespace std;
int t,n,a[100005],b[100005],larger,lower;
int main(){
	cin>>t;
	while(t--){
		scanf("%d",&n);
		for (int i=1;i<=n;i++)scanf("%d",&a[i]);
		for (int i=1;i<=n;i++)scanf("%d",&b[i]);
		larger=lower=0;
		for (int i=n;i>=1;i--){
			if (a[i]==-1)larger=0;
			if (a[i]==1)lower=0;
			if (a[i]<b[i])lower=1;
			if (b[i]<a[i])larger=1;
		}
		if (larger==0&&lower==0)puts("YES");
		else puts("NO");
	}
	return 0;
}//slhtxdy