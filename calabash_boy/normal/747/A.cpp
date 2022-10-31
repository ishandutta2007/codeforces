#include<iostream>
#include<stdlib.h>
#include<algorithm>
#include<math.h>
using namespace std;
int main(){
	long long n;
	cin>>n;
	int mid=sqrt(n);
	for (int i=mid;i>=1;i--){
		long long tmp=n/i;
		long long ans=tmp*i;
		if (ans==n){
			cout<<i<<' '<<tmp;
			return 0;
		}
	}
	return 0;
}