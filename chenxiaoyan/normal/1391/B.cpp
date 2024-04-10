/*





D P 




 l l
*/
#include<bits/stdc++.h>
using namespace std;
const int N=100,M=N;
int n,m;
char a[N+1][M+5];
void mian(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i]+1;
	int cnt=0;
	for(int i=1;i<=n;i++)cnt+=a[i][m]!='D'&&a[i][m]!='C';
	for(int i=1;i<=m;i++)cnt+=a[n][i]!='R'&&a[n][i]!='C';
	cout<<cnt<<"\n";
}
int main(){
	int testnum;
	cin>>testnum;
	while(testnum--)mian();
	return 0;
}