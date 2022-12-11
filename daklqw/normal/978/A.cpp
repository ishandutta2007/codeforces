#include <iostream>
#include <cstdio>
using namespace std;
int n,a[1010],t,ansl[1010],sums[1010],e;
int main(){
	cin>>n;
	for(int i=1;i<=n;++i)
		cin>>sums[i];
	for(int i=n;i;--i){
		if(a[sums[i]])continue;
		ansl[++e]=sums[i];a[sums[i]]=true;
	}
	cout<<e<<endl;
	for(int i=e;i;--i)cout<<ansl[i]<<" ";
	cout<<endl;
	return 0;
}