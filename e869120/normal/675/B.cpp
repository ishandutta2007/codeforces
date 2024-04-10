#include<iostream>
#include<algorithm>
using namespace std;
long long n,a,b,c,d,cnt;
int main(){
	cin>>n>>a>>b>>c>>d;
	long long E=min(a+b,min(b+d,min(d+c,c+a)));
	long long F=max(a+b,max(b+d,max(d+c,c+a)));
	cout<<n*max(0LL,n-(F-E))<<endl;
	return 0;
}