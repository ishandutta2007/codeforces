#include<bits/stdc++.h>
using namespace std;
int T,n,a[200100],m,lim;
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n),lim=0;
		for(int i=1;i<=n;i++)scanf("%d",&a[i]);
		for(int i=0;i<30;i++){
			m=0;
			for(int j=1;j<=n;j++)if(a[j]&(1<<i))m++;
			lim=__gcd(m,lim);
		}
		for(int i=1;i<=n;i++)if(!(lim%i))printf("%d ",i);puts(""); 
	}
	return 0;
}