#include<bits/stdc++.h>
using namespace std;
#define MAXN 200005
long long sum[MAXN];
int main(){
	int k,n;
	cin>>n>>k;
	sum[0]=0;
	for (int i=1;i<=n;i++){
		int temp ;
		cin>>temp;
		sum[i]=sum[i-1]+temp;
	}
	long long ans =0;
	for (int i=1;i<=n-k+1;i++){
		ans+=sum[i+k-1]-sum[i-1];
	}
	double output = (double)ans/(double)(n-k+1);
	printf("%.10f",output);
	return 0;
}