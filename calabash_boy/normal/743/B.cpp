#include<iostream>
using namespace std;
int main(){
	long long n,k;
	long long cnt=1;
	cin>>n>>k;
	for (int i=1;i<=n;i++)
		cnt=cnt*2;
	cnt--;
	while(true){
		long long mid=(cnt+1)>>1;
		if (mid==k){
			cout<<n;
			return 0;
		}else{
			if (k<mid){
				n--;
				cnt>>=1;
			}else{
				n--;
				k-=mid;
				cnt>>=1;
			}
		}
	}
	return 0;
}