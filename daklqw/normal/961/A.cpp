#include <iostream>
#include <cstdio>
using namespace std;
int sums[1010],n,m,t;
int main(){
	cin>>n>>m;
	while(m--)cin>>t,++sums[t];t=sums[1];
	for(int i=1;i<=n;++i)t=min(t,sums[i]);
	cout<<t<<endl;
	return 0;
}