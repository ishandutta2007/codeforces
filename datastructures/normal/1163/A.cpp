#include <iostream> 
#include <cstdio>
using namespace std;
int n,m;
int main(){
	cin>>n>>m;
	if (n==m)cout<<0<<endl;
	else cout<<max(1,min(n-m,m))<<endl;
	return 0;
}