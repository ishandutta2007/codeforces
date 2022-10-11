#include<iostream>
using namespace std;
long long n,l,r;
long long solve(long long pos,long long a,long long b){
	if(b<=l)return 0;
	if(r<a)return 0;
	if(a>=b)return 0;
	long long C=0;if(pos%2==1 && l<=(a+b)/2 && (a+b)/2<r)C=1;
	return solve(pos/2,a,(a+b)/2)+solve(pos/2,(a+b)/2+1,b)+C;
}
int main(){
	cin>>n>>l>>r;l--;
	long long T=0;
	for(int i=1;i<=60;i++){if((1LL<<i)-1>=n){T=(1LL<<i)-1;break;}}
	cout<<solve(n,0,T)<<endl;
	return 0;
}