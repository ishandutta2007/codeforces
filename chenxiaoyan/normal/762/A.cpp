/*




D P 




 l l
*/
#pragma GCC optimize(3)
#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	int n,m;
	cin>>n>>m;
	int sq=sqrt(n);
	for(int i=1;i<=sq;i++){
		if(n%i==0)m--;
		if(!m)return cout<<i,0;
	}
	for(int i=sq;i;i--){
		if(i*i!=n&&n%(n/i)==0)m--;
		if(!m)return cout<<n/i,0;
	}
	puts("-1");
	return 0;
}