#include<bits/stdc++.h>
using namespace std;
long long D,K,A,B,T;
int main(){
	cin>>D>>K>>A>>B>>T;
	if(D<=K){cout<<A*D<<endl;return 0;}
	long long C1=K*A+(D-K)*B;
	long long C2=((D/K)*K)*A+((D/K)-1)*T+(D%K)*B;
	long long C3=D*A+((D-1)/K)*T;
	cout<<min(C1,min(C2,C3))<<endl;
	return 0;
}