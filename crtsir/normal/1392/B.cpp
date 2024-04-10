#include<bits/stdc++.h>
using namespace std;
int T,n,a[200003];
long long k;
void calc(){int d=-2147483648;
	for(int i=0;i<n;i++)d=max(d,a[i]);
	for(int i=0;i<n;i++)a[i]=d-a[i];
}
int main(){
	cin>>T;
	while(T--){
		cin>>n>>k;
		for(int i=0;i<n;i++)
			scanf("%d",a+i);
		if(k%2)
			calc();
		else{
			calc();
			calc();
		}
		for(int i=0;i<n;i++)
			printf("%d ",a[i]);
		printf("\n");
	}
}