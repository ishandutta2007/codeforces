/*




D P 




 l l
*/
#include<bits/stdc++.h>
using namespace std;
const int N=20,M=20;
int n,m;
string a[N+1],b[M+1];
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=m;i++)cin>>b[i];
	int qu;
	cin>>qu;
	while(qu--){
		int x;
		cin>>x;
		cout<<a[x%n?x%n:n]<<b[x%m?x%m:m]<<"\n";
	}
	return 0;
}