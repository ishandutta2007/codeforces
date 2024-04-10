#include<iostream>
using namespace std;
#define R register int
int a[100001],s[100001];
int main(){
	int n;
	cin>>n;
	for(R i=1;i<=n;i++){
		cin>>a[i];
	}
	for(R i=3;i<=n;i++){
		if((a[i-2]^a[i-1])>a[i]||a[i-2]>(a[i-1]^a[i])){
			cout<<1;
			return 0;
		}
	}
	for(R i=1;i<=n;i++){
		s[i]=s[i-1]^a[i];
	}
	int ans=2e9;
	for(R i=1;i!=n;i++){
		for(R j=i;j!=0;j--){
			for(R k=i+1;k<=n;k++){
				if(k-j<ans&&(s[i]^s[j-1])>(s[k]^s[i])){
					ans=k-j;
				}
			}
		}
	}
	if(ans==2e9){
		ans=0;
	}
	cout<<ans-1;
	return 0;
}