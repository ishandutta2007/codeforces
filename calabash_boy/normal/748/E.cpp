#include<stdio.h>
#include<iostream>
using namespace std;
long long a[10000005];
long long use[10000005];
int main(){
	long long sum=0;
	long long n,k,max=0,totol=0,temp;
	cin>>n>>k;
	for (long long i=1;i<=n;i++){
		scanf("%I64d",&temp);
		a[temp]++;
		max=max>temp?max:temp;
	}
	for (long long i=max;i>=1;i--){
		totol+=a[i];
		totol-=use[i];
		if (totol>=k){
			cout<<i<<endl;
			return 0;
		}else{
			a[i>>1]+=a[i];
			a[(i+1)>>1]+=a[i];
			use[(i+1)>>1]+=a[i];
		}
	}
	cout<<-1;
	return 0;
}