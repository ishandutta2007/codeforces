#include<bits/stdc++.h>
using namespace std;
long long n,p;
int check(long long x){
	int cnt=0;
	while(x)cnt+=x%2,x/=2;
	return cnt;
}
int main(){
	cin>>n>>p;
	for(int i=0;i<=31;i++){
		if(check(n)<=i&&n>=i){
			cout<<i;
			return 0;
		}
		n-=p;
	}
	cout<<-1;
}