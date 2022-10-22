#include<cstdio>
#include<iostream>
using namespace std;
int n,a[100010],all=1;
long long ans;
bool zero;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i]<0){
			ans+=-a[i]-1;
			all*=-1;
		}
		if(a[i]>0){
			ans+=a[i]-1;
		}
		if(a[i]==0) ans+=1,zero=1;
	}
	if(all==-1){
		if(zero) cout<<ans<<endl;
		else cout<<ans+2<<endl;
	}
	else cout<<ans<<endl;
	return 0;
}