#include <bits/stdc++.h>
#define rep(i,n) for ((i)=1;(i)<=(n);(i)++)
using namespace std;
int n,a[100005],s[100005];
int main(){
	int i,j,k;
	scanf("%d",&n);
	rep(i,n)scanf("%d",&a[i]);
	rep(i,n-2){
		if(a[i]>(a[i+1]^a[i+2])){
			puts("1");return 0;
		}
	}
	rep(i,n){
		s[i]=s[i-1]^a[i];
	}
	int ans=n+1;
	rep(i,n){
		for(j=i;j<=n;j++){
			for(k=j+1;k<=n;k++){
				if((s[j]^s[i-1])>(s[k]^s[j])){
					ans=min(ans,k-i-1);
				}
			}
		}
	}
	if(ans==n+1)puts("-1");else cout<<ans<<endl;
	return 0;
}