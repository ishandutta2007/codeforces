#include <bits/stdc++.h>
#define rep(i,n) for ((i)=1;(i)<=(n);(i)++)
using namespace std;
int n,i,j,a[1005];
long long ans,cl,cr,cs;
int main(){
	scanf("%d",&n);
	rep(i,n){
		scanf("%d",&a[i]);
	}
	for(i=2;i<=n;i+=2){
		cl=cr=cs=0;
		for(j=i;j<=n;j+=2){
			long long l=-cl,r=a[i-1];
			r=min(r,0ll+a[j]-cs);
			if(l<=r)ans+=r-l+1;
			cs-=a[j];
			cl=min(cl,cs);
			cr=max(0ll,cr-a[j]);
			cs+=a[j+1];
			cl=min(cl,cs);
			cr=max(0ll,cr+a[j+1]);
		}
		ans--;
	}
	cout<<ans<<endl;
	return 0;
}