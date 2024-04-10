#include<algorithm>
#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
#include<map>
#include<queue>
#include<set>
#include<sstream>
#include<stack>
#include<string>
#include<vector>
using namespace std;
double ave;
int n,k,a[5005],qz[5005],sum,len;
int main(){
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		qz[i]=a[i]+qz[i-1];
	}
	sum=0;
	len=2e9;
	for(int i=1;i<=n-k+1;i++){
		for(int j=i+k-1;j<=n;j++){
			if(((double)qz[j]-qz[i]+a[i])/((double)j-i+1)>((double)sum)/((double)len)){
				sum=qz[j]-qz[i]+a[i];
				len=j-i+1;
			}
		}
	}
	ave=((double)sum)/((double)len);
	printf("%.15lf",ave);
	return 0;
}