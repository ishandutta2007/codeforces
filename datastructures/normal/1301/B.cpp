#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
int t,n,a[100005],m,k;
int tot,c[500005];
int main(){
	cin>>t;
	while(t--){
		cin>>n;
		for (int i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}
		a[0]=a[n+1]=0;
		tot=0;
		m=0,k=0;
		for (int i=1;i<=n;i++){
			if (a[i-1]==-1||a[i+1]==-1){
				if (a[i]!=-1)c[++tot]=a[i];
			}
		}
		sort(c+1,c+1+tot);
		k=(c[1]+c[tot])/2;
		for (int i=1;i<=n;i++)
			if (a[i]==-1)a[i]=k;
		for (int i=2;i<=n;i++)	
			m=max(m,abs(a[i]-a[i-1]));
		cout<<m<<' '<<k<<endl;
	}
	return 0;
}