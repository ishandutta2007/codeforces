#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int t,n,a[300005],f1[300005][21],f2[300005][21],c0[300005],c1[300005];
int q[300005],tail;
int main(){
	cin>>t;
	while(t--){
		cin>>n;
		for (int i=1;i<=n;i++)scanf("%d",&a[i]);
		tail=0;
		for (int i=n;i>=1;i--){
			while(tail>0&&a[q[tail]]<=a[i])tail--;
			c0[i]=q[tail];
			q[++tail]=i;
		}
		tail=0;
		for (int i=n;i>=1;i--){
			while(tail>0&&a[q[tail]]>=a[i])tail--;
			c1[i]=q[tail];
			q[++tail]=i;
		}
		for (int i=1;i<=n;i++){
			if (c0[i]==0)c0[i]=n+1;
			if (c1[i]==0)c1[i]=n+1;
		}
		int ans=0,p=1;
		while(p<n){
			if (c0[p]<c1[p]){
				int c=c1[p];
				while(c0[p]<c)p=c0[p];
				ans++;
			}
			else{
				int c=c0[p];
				while(c1[p]<c)p=c1[p];
				ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}