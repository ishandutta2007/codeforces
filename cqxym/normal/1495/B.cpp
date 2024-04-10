#include<iostream>
using namespace std;
#define R register int
int a[100002],lf[100002],rt[100002];
int main(){
	int n;
	cin>>n;
	for(R i=1;i<=n;i++){
		cin>>a[i];
	}
	lf[1]=1;
	for(R i=2;i<=n;i++){
		if(a[i-1]<a[i]){
			lf[i]=lf[i-1]+1;
		}else{
			lf[i]=1;
		}
	}
	rt[n]=1;
	for(R i=n-1;i!=0;i--){
		if(a[i+1]<a[i]){
			rt[i]=rt[i+1]+1;
		}else{
			rt[i]=1;
		}
	}
	int m=0,ct=0;
	for(R i=1;i<=n;i++){
		if(lf[i]>m){
			m=lf[i];
			ct=1;
		}else if(lf[i]==m){
			ct++;
		}
		if(rt[i]>m){
			m=rt[i];
			ct=1;
		}else if(rt[i]==m){
			ct++;
		}
	}
	int ans=0;
	for(R i=1;i<=n;i++){
		if(lf[i]==m&&rt[i]==m&&ct==2&&(m&1)==1){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}