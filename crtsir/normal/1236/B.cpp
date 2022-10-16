#include<bits/stdc++.h>
using namespace std;
const long long mod=1000000007;
long long mypow(long long x,long long times){
	long long a=1;
	if(times==1)return x;
	if(times%2)a=x;
	return (a*mypow(x,times/2)%mod*mypow(x,times/2))%mod;
} 
int main(){
	long long n,m;
	cin>>n>>m;
	cout<<mypow((mypow(2,m)-1),n);
}