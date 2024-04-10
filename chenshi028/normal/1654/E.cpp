#include<cstdio>
#include<iostream>
using namespace std;
const int o=1e5+10,O=4e7+10;
int n,a[o],ans,b[O*2];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i) scanf("%d",&a[i]);
	for(int i=-300;i<=300;++i){
		for(int j=1;j<=n;++j) ++b[a[j]-i*j+O];
		for(int j=1;j<=n;++j) ans=max(ans,b[a[j]-i*j+O]--);
	}
	for(int i=1;i<=n;++i){
		for(int j=i+1;j<=n&&j<=i+400;++j)
			if((a[j]-a[i])%(j-i)==0) ++b[(a[j]-a[i])/(j-i)+O];
		for(int j=i+1;j<=n&&j<=i+400;++j)
			if((a[j]-a[i])%(j-i)==0) ans=max(ans,(b[(a[j]-a[i])/(j-i)+O]--)+1);
	}
	printf("%d",n-ans);
	return 0;
}