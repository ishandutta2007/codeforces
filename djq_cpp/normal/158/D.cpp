#include <iostream>
using namespace std;
int ml[50001],ys[50001],ysnum;
int main(){
	int n;
	long long res=-20000001,sum;
	cin>>n;
	for(int k=0;k<n;k++)cin>>ml[k];
	for(int step=1;step*2<n;step++){
		if(n%step)continue;
		for(int start=0;start<step;start++){
			sum=0;
			for(int k=start;k<n;k+=step)sum+=ml[k];
			if(sum>res)res=sum;
		}
	}
	cout<<res;
	return 0;
}