#include <iostream>
#include <cstdio>
using namespace std;
int t,a[105],n,m,k;
int main(){
//	freopen("b.in","r",stdin);
//	freopen("b.out","w",stdout);
	cin>>t;
	while(t--){
		int i;
		cin>>n>>m>>k;
		for (i=1;i<=n;i++)cin>>a[i];
		int flag=1;
		for (i=1;i<n&&flag;i++){
//			cout<<i<<' '<<m<<endl;
			if (a[i]+k<a[i+1]){
				if (a[i+1]-(a[i]+k)>m)flag=0;
				else m-=a[i+1]-(a[i]+k);
			}
			if (a[i]>=max(a[i+1]-k,0))m+=a[i]-max(a[i+1]-k,0);
		}
		if (flag)cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}