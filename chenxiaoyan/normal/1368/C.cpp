/*





D P 




 l l
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	n++;
	cout<<3*n+1<<"\n";
	for(int i=1;i<=n;i++){
		cout<<i<<" "<<i<<"\n";
		cout<<1+i<<" "<<i<<"\n";
		cout<<i<<" "<<1+i<<"\n";
	}
	cout<<n+1<<" "<<n+1;
	return 0;
}