#include<cstdio>
#include<iostream>
using namespace std;
long long l,r;
int ok(long long number){
	int fk[15]={0};
	while(number!=0){
		long long kkksc03=number%10;
		if(fk[kkksc03])return 0;
		fk[kkksc03]=1;
		number/=10;
	}
	return 1;
}
int main(){
//  freopen("1228A.in","r",stdin);
//  freopen("1228A.out","w",stdout);
	scanf("%I64d%I64d",&l,&r);
	for(long long i=l;i<=r;i++){
		if(ok(i)){
			cout<<i<<endl;
			return 0;
		}
	}
	cout<<-1<<endl;
	return 0;
}