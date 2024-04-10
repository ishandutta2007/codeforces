#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define int long long
using namespace std;
int t,n,a[200005],b[200005];
int l1,c1[200005],l2,c2[200005];
int sum;
signed main(){
	cin>>t;
	while(t--){
		cin>>n;
		for (int i=1;i<=n;i++)scanf("%lld",&a[i]);
		for (int i=1;i<=n;i++)scanf("%lld",&b[i]);
		l1=l2=0;
		sum=0;
		for (int i=1;i<=n;i++){
			if (a[i]==0)c1[++l1]=b[i];
			else c2[++l2]=b[i];
			sum+=b[i];
		}
		sort(c1+1,c1+1+l1);
		sort(c2+1,c2+1+l2);
		for (int i=1;i<=min(l1,l2);i++)sum+=c1[l1-i+1]+c2[l2-i+1];
		if (l1==l2)sum-=min(c1[1],c2[1]);
		cout<<sum<<endl;
	}
	return 0;
}